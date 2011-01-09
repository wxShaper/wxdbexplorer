#ifndef MYSQLTYPE_H
#define MYSQLTYPE_H

#include "IDbType.h" // Base class: IDbType

class MySqlType : public IDbType {

public:
	MySqlType(const wxString& typeName, bool haveAutoIncrement, bool haveNotNull, bool havePrimaryKey, bool haveSize, bool haveUnique);
	~MySqlType();
	
	virtual bool GetAutoIncrement()						{ return m_autoIncrement; }
	virtual bool GetNotNull()							{ return m_notNull; }
	virtual bool GetPrimaryKey()						{ return m_primaryKey; }
	virtual long GetSize()								{ return m_size; }
	virtual wxString GetTypeName()						{ return m_typeName; }
	virtual bool GetUnique()							{ return m_unique; }
	virtual bool HaveAutoIncrement() 					{ return m_haveAutoIncrement; }
	virtual bool HaveNotNull() 							{ return m_haveNotNull; }
	virtual bool HavePrimaryKey() 						{ return m_havePrimaryKey; }
	virtual bool HaveSize() 							{ return m_haveSize; }
	virtual bool HaveUnique() 							{ return m_haveUnique; }
	virtual void SetAutoIncrement(bool autoIncrement) 	{ m_autoIncrement = autoIncrement; }
	virtual void SetNotNull(bool notNull) 				{ m_notNull = notNull; }
	virtual void SetPrimaryKey(bool primaryKey) 		{ m_primaryKey = primaryKey; }
	virtual void SetSize(long size) 						{ m_size = size; }
	virtual void SetUnique(bool unique) 				{ m_unique = unique; }
	virtual wxString ReturnSql();
protected:
	wxString m_typeName;
	long m_size;
	bool m_unique;
	bool m_primaryKey;
	bool m_notNull;
	bool m_autoIncrement;
	
	bool m_haveSize;
	bool m_haveUnique;
	bool m_havePrimaryKey;
	bool m_haveNotNull;
	bool m_haveAutoIncrement;
	
	
};

#endif // MYSQLTYPE_H
