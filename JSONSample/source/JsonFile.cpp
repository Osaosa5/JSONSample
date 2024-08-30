
#include <fstream>
#include <iostream>
#include "JsonFile.h"

JsonFile::JsonFile(const std::string& fileName)
{
	// メンバの初期化
	Init();

	// ファイルを開く
	_fileName = fileName;
	std::ifstream ifs(fileName);

	// ファイルを開けなかったら処理を終わらせる
	if (!ifs) return;

	// 読み込んだデータをデシリアライズする
	ifs >> _jsonData;
	ifs.close();

	_success = true;
}

JsonFile::JsonFile(const std::string& fileName, nlohmann::json writeData)
{
	// メンバの初期化
	Init();

	// ファイルを開く
	_fileName = fileName;
	std::ofstream ofs(fileName);

	// ファイルを開けなかったら処理を終わらせる
	if(!ofs) return;

	// ファイルに書き込むデータをシリアライズする
	ofs << writeData.dump() << std::endl;
	ofs.close();

	_success = true;
}

JsonFile::~JsonFile()
{
	_jsonData.clear();
}

void JsonFile::Init()
{
	_fileName = "";
	_jsonData.clear();
	_success = false;
}
