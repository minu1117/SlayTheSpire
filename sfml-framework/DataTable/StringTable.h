#pragma once
#include "DataTable.h"
#include <map>
#include <vector>

using namespace std;

enum class Languages
{
	KOR,
	ENG,
	JPN,
	COUNT,
};

class StringTable : public DataTable
{
private:
	map<string, string> table;
	Languages currentLang;

public:
	StringTable();
	virtual ~StringTable();

	void SetLanguage(Languages lang);

	const string& Get(const string& id);

	virtual void Release();
	virtual bool Load();

	vector<string> fileNames;
};

