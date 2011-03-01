#ifndef IDS_H_INCLUDED
#define IDS_H_INCLUDED

enum APPIDS
{
    //---------------------------------------------------------------//
    IDM_FIRST = wxID_HIGHEST + 1,

    // tool ErdPanel IDs
    //---------------------------------------------------------------//
	IDS_ERD_SAVE_SQL,
	IDT_ERD_FIRST,
    IDT_ERD_TOOL,
	IDT_ERD_TABLE,
	IDT_ERD_LINE,
	IDT_ERD_LAST,
	
	IDR_POPUP_MI1,
	IDR_POPUP_MI2,
	IDR_POPUP_MI3,
	IDR_DBVIEWER_ADD_DATABASE,
	IDR_DBVIEWER_DROP_DATABASE,
	IDR_DBVIEWER_IMPORT_DATABASE,
	IDR_DBVIEWER_EXPORT_DATABASE,
	IDR_DBVIEWER_ADD_TABLE,
	IDR_DBVIEWER_DROP_TABLE,
	IDR_DBVIEWER_ERD_DB,
	IDR_DBVIEWER_ERD_TABLE,

	MAX_ID
	
	
	};

#endif // IDS_H_INCLUDED