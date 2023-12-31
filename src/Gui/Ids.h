#ifndef IDS_H_INCLUDED
#define IDS_H_INCLUDED

enum APPIDS
{
    //---------------------------------------------------------------//
    IDM_FIRST = wxID_HIGHEST + 1,

    // tool ErdPanel IDs
    //---------------------------------------------------------------//
	IDS_ERD_SAVE_SQL,
	IDS_ERD_SAVE_BMP,
	IDS_ERD_COMMIT,
	IDT_ERD_FIRST,
    IDT_ERD_TOOL,
	IDT_ERD_TABLE,
	IDT_ERD_VIEW,
	IDT_ERD_LINE,
	IDT_ERD_LAST,
	IDT_ERD_ALIGN_CIRCLE,
	IDT_ERD_ALIGN_MESH,
	IDT_ERD_ALIGN_VTREE,
	IDT_ERD_ALIGN_HTREE,
	IDT_ERD_ZOOM100,
	IDT_ERD_ZOOMALL,
	
	IDR_POPUP_NEW_TABLE,
	IDR_POPUP_NEW_VIEW,
	IDR_POPUP_NEW_KEY,
	IDR_POPUP_MI1,
	IDR_POPUP_MI2,
	IDR_POPUP_MI3,
	IDR_POPUP_COPY,
	IDR_POPUP_CUT,
	IDR_POPUP_PASTE,
	IDR_DBVIEWER_ADD_DATABASE,
	IDR_DBVIEWER_DROP_DATABASE,
	IDR_DBVIEWER_IMPORT_DATABASE,
	IDR_DBVIEWER_EXPORT_DATABASE,
	IDR_DBVIEWER_ADD_TABLE,
	IDR_DBVIEWER_DROP_TABLE,
	IDR_DBVIEWER_ERD_DB,
	IDR_DBVIEWER_ERD_TABLE,
	IDR_DBVIEWER_CLASS_DB,
	IDR_DBVIEWER_CLASS_TABLE,
	IDR_DBVIEWER_DUMP_DATABASE,
	
	IDR_SQLCOMMAND_SELECT,
	IDR_SQLCOMMAND_INSERT,
	IDR_SQLCOMMAND_UPDATE,
	IDR_SQLCOMMAND_DELETE,
	MAX_ID
	
	
	};

#endif // IDS_H_INCLUDED