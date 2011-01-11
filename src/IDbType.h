#ifndef IDBTYPE_H
#define IDBTYPE_H

#include <wx/wx.h>
#include <wx/wxxmlserializer/XmlSerializer.h>

class IDbType: public xsSerializable
{
public:
		virtual wxString GetTypeName() = 0;
		
		// size
		virtual bool HaveSize() = 0;
		virtual long GetSize() = 0;
		virtual void SetSize(long size) = 0;
		
		// primary key
		virtual bool HavePrimaryKey() = 0;
		virtual bool GetPrimaryKey() = 0;
		virtual void SetPrimaryKey(bool primaryKey) = 0;
		
		// unique
		virtual bool HaveUnique() = 0;
		virtual bool GetUnique() = 0;
		virtual void SetUnique(bool unique) = 0;
		
		// not null
		virtual bool HaveNotNull() = 0;
		virtual bool GetNotNull() = 0;
		virtual void SetNotNull(bool notNull) = 0; 
		
		// auto increment
		virtual bool HaveAutoIncrement() = 0;
		virtual bool GetAutoIncrement() = 0;
		virtual void SetAutoIncrement(bool autoIncrement) = 0;
		
		// sql
		virtual wxString ReturnSql() = 0;

	
};


#endif