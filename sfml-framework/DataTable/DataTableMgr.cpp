#include "DataTableMgr.h"
#include "StringTable.h"

void DataTableMgr::Init()
{
    DataTable* table = new StringTable();
    table->Load();
    tables.insert( { DataTable::Types::String, table } );
}

void DataTableMgr::Release()
{
    for (auto pair : tables)
    {
        delete pair.second;
    }
    tables.clear();
}
