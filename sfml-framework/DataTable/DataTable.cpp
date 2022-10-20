#include "DataTable.h"

int DataTable::TotalTypes = (int)Types::Count;

DataTable::DataTable(Types t)
	: type(t)
{

}

DataTable::~DataTable()
{
}


DataTable::DataTable(const DataTable& ref)
{
}

DataTable& DataTable::operator=(const DataTable& ref)
{
	return *this;
}

