
#pragma once

#include <string>
#include <nlohmann/json.hpp>

class JsonFile
{
public:
	// 読み込み
	JsonFile(const std::string& fileName);
	// 書き込み
	JsonFile(const std::string& fileName, nlohmann::json writeData);	

	~JsonFile();

	// ゲッター
	std::string		GetFileName()	{ return _fileName; }
	nlohmann::json	GetData()		{ return _jsonData; }

	bool Success() const { return _success; }

private:
	
	JsonFile() = default;	// デフォルトコンストラクタ

	void Init();			// 初期化

	std::string		_fileName;	// ファイルパス
	nlohmann::json	_jsonData;

	bool	_success;
};

