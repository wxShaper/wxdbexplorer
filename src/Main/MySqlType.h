#ifndef MYSQLTYPE_H
#define MYSQLTYPE_H

#include <wx/wxxmlserializer/XmlSerializer.h>
#include "Interfaces/IDbType.h" // Base class: IDbType

class MySqlType : public IDbType {

	public:
		XS_DECLARE_CLONABLE_CLASS(MySqlType);
		MySqlType();
		MySqlType(const MySqlType& obj);
		MySqlType(const wxString& typeName, long propertyFlags, UNIVERSAL_TYPE universalType);
		virtual ~MySqlType();
		void InitSerialize();

		virtual bool GetAutoIncrement()						{
			return m_autoIncrement;
		}
		virtual bool GetNotNull()							{
			return m_notNull;
		}
		virtual bool GetPrimaryKey()						{
			return m_primaryKey;
		}
		virtual long GetSize()								{
			return m_size;
		}
		virtual long GetSize2()								{
			return m_size2;
		}
		virtual wxString GetTypeName()						{
			return m_typeName;
		}
		virtual bool GetUnique()							{
			return m_unique;
		}
		virtual bool HaveAutoIncrement() 					{
			return (m_dbtPropertyFlags & dbtAUTO_INCREMENT);
		}
		virtual bool HaveNotNull() 							{
			return (m_dbtPropertyFlags & dbtNOT_NULL);
		}
		virtual bool HavePrimaryKey() 						{
			return (m_dbtPropertyFlags & dbtPRIMARY_KEY);
		}
		virtual bool HaveSize() 							{
			return (m_dbtPropertyFlags & dbtSIZE);
		}
		virtual bool HaveSize2() {
			return (m_dbtPropertyFlags & dbtSIZE_TWO);
		}
		virtual bool HaveUnique() 							{
			return (m_dbtPropertyFlags & dbtUNIQUE);
		}
		virtual void SetAutoIncrement(bool autoIncrement) 	{
			m_autoIncrement = autoIncrement;
		}
		virtual void SetNotNull(bool notNull) 				{
			m_notNull = notNull;
		}
		virtual void SetPrimaryKey(bool primaryKey) 		{
			m_primaryKey = primaryKey;
		}
		virtual void SetSize(long size) 					{
			m_size = size;
		}
		virtual void SetSize2(long size) 					{
			m_size2 = size;
		}
		virtual void SetUnique(bool unique) 				{
			m_unique = unique;
		}
		virtual wxString ReturnSql();

		virtual long GetPropertyFlags() {
			return m_dbtPropertyFlags;
		}
		virtual void SetPropertyFlags(long flags) {
			m_dbtPropertyFlags = flags;
		}

		virtual IDbType::UNIVERSAL_TYPE GetUniversalType();

	protected:
		wxString m_typeName;
		long m_dbtPropertyFlags;
		long m_universalType;

		long m_size;
		long m_size2;
		bool m_unique;
		bool m_primaryKey;
		bool m_notNull;
		bool m_autoIncrement;

};

#endif // MYSQLTYPE_H
