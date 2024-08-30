
#pragma once

#include	"JsonFile.h"

#include	<unordered_map>
#include	<string>

// リソース管理サーバ
// すべて静的メンバで構成する

class JsonManeger
{
public:
	static	void	Init();
	static	void	Release();

	static	void				ClearJson();
	static	nlohmann::json		LoadJsonFile(const std::string& fileName);

private:
	// _mJson->(fileName, jsonData)
	static std::unordered_map<std::string, nlohmann::json> _mJson;
};

