#include "CreateForeignKey.h"

CreateForeignKey::CreateForeignKey(wxWindow* parent, ErdTable* pSourceTable, ErdTable* pDestTable, const wxString& srcColName, const wxString& dstColName):_CreateForeignKey(parent)
{
	m_pSrcTable = pSourceTable;
	m_pDstTable = pDestTable;
	m_srcColName = srcColName;
	m_dstColName = dstColName;
	
	m_cmbDstCol->SetValue(dstColName);
	m_cmbSrcCol->SetValue(srcColName);
	m_txSrcTable->SetValue(pSourceTable->getTable()->getName());
	m_txDstTable->SetValue(pDestTable->getTable()->getName());	
	SerializableList::compatibility_iterator node = pSourceTable->getTable()->GetFirstChildNode();
	while( node ) {
		if( node->GetData()->IsKindOf( CLASSINFO(Column)) )  m_cmbSrcCol->AppendString(wxString::Format(wxT("%s"),((Column*) node->GetData())->getName().c_str()));
		node = node->GetNext();
	}
	node = pDestTable->getTable()->GetFirstChildNode();
	while( node ) {
		if( node->GetData()->IsKindOf( CLASSINFO(Column)) )  m_cmbDstCol->AppendString(wxString::Format(wxT("%s"),((Column*) node->GetData())->getName().c_str()));
		node = node->GetNext();
	}
}

CreateForeignKey::~CreateForeignKey()
{
}

void CreateForeignKey::OnCancelClick(wxCommandEvent& event)
{
	Destroy();
}
void CreateForeignKey::OnOKClick(wxCommandEvent& event)
{
	wxString srcColName;
	wxString srcLocColName;
	wxString dstColName;
	wxString dstLocColName;
	
	if (m_radioBox3->GetSelection() == 0){
		Table* pTable = m_pSrcTable->getTable();		
		Constraint* pConstr = new Constraint();
		pConstr->SetName(wxString::Format(wxT("FK_%s_%s"), pTable->getName().c_str(),m_pDstTable->getTable()->getName().c_str()));
		pConstr->SetLocalColumn(m_cmbSrcCol->GetValue());
		pConstr->SetRefCol(m_cmbDstCol->GetValue());
		pConstr->SetRefTable(m_txDstTable->GetValue());
		pConstr->SetType(Constraint::foreignKey);
		pTable->AddChild(pConstr);
		m_pSrcTable->updateColumns();
		}	

	if (m_radioBox3->GetSelection() == 1){
		// Get old tables   -------------------------------------------------------------
		Table* pSrcTable = m_pSrcTable->getTable();	
		Table* pDstTable = m_pDstTable->getTable();	
		// Create new table -------------------------------------------------------------
		//wxString sr1 = pSrcTable->getName();
 		//wxString sr2 = pDstTable->getName();
		//Table* newTab = new Table();//new Table(pSrcTable->GetDbAdapter(),wxString::Format(wxT("FKT_%s_%s"),pSrcTable->getName().c_str(),pDstTable->getName().c_str() ), wxT(""),0);
		Table* newTab = new Table();
		newTab->setName(wxString::Format(wxT("FKT_%s_%s"),pSrcTable->getName().c_str(),pDstTable->getName().c_str() ));
		// Copy selected columns --------------------------------------------------------
		SerializableList::compatibility_iterator node = pSrcTable->GetFirstChildNode();
		while( node ) {
			if( node->GetData()->IsKindOf( CLASSINFO(Column)) ){
				Column* col = wxDynamicCast(node->GetData(), Column);
				if (col->getName() == m_cmbSrcCol->GetValue()) {
					Column* colNew = (Column*) col->Clone();
					srcColName = col->getName();
					srcLocColName = wxString::Format(wxT("%s_%s"), pSrcTable->getName().c_str(), col->getName().c_str());
					colNew->setName(srcLocColName);
					newTab->AddChild(colNew);	
					}			
				} 
			node = node->GetNext();
		}
		
		node = pDstTable->GetFirstChildNode();
		while( node ) {
			if( node->GetData()->IsKindOf( CLASSINFO(Column)) ){
				Column* col = wxDynamicCast(node->GetData(), Column);
				if (col->getName() == m_cmbDstCol->GetValue()) {
					Column* colNew = (Column*) col->Clone();
					dstColName = col->getName();
					dstLocColName = wxString::Format(wxT("%s_%s"), pDstTable->getName().c_str(), col->getName().c_str());
					colNew->setName(dstLocColName);
					newTab->AddChild(colNew);	
					}			
				} 
			node = node->GetNext();
		}
		// create constraints ------------------------------------------------------------
		Constraint* pCSrc = new Constraint();
		pCSrc->SetName(wxString::Format(wxT("FK_%s_%s"),newTab->getName().c_str(), pSrcTable->getName().c_str()));
		pCSrc->SetLocalColumn(srcLocColName);
		pCSrc->SetRefTable(pSrcTable->getName());
		pCSrc->SetRefCol(srcColName);
		pCSrc->SetType(Constraint::foreignKey);
		newTab->AddChild(pCSrc);		
		
		Constraint* pCDest = new Constraint();
		pCDest->SetName(wxString::Format(wxT("FK_%s_%s"),newTab->getName().c_str(), pDstTable->getName().c_str()));
		pCDest->SetLocalColumn(dstLocColName);
		pCDest->SetRefTable(pDstTable->getName());
		pCDest->SetRefCol(dstColName);
		pCDest->SetType(Constraint::foreignKey);
		newTab->AddChild(pCDest);			
		
		
		int x = (m_pSrcTable->GetAbsolutePosition().x + m_pDstTable->GetAbsolutePosition().x) / 2;
		int y = (m_pSrcTable->GetAbsolutePosition().y + m_pDstTable->GetAbsolutePosition().y) / 2;
		
		ErdTable* newErdTable = (ErdTable*) m_pSrcTable->GetShapeManager()->AddShape(new ErdTable(), NULL, wxPoint(x,y), true);
		newErdTable->SetUserData(newTab);
		newErdTable->updateColumns();
		}
		
		
		
		Destroy();
}
void CreateForeignKey::OnOKUI(wxUpdateUIEvent& event)
{
	event.Enable(false);
	if ((!m_cmbSrcCol->GetValue().empty())&&(!m_cmbDstCol->GetValue().empty())) event.Enable(true);
}