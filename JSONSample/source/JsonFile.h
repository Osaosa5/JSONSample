/**
* @file		JsonFile.h
* @brief	JSONファイルクラスヘッダ
*/

#pragma once

#include <string>
#include <nlohmann/json.hpp>

/**
* @brief	JSONファイルクラス
* @details	JSONファイルを読み込む、書き込む
*/
class JsonFile
{
public:
	/**
	* @brief	コンストラクタ
	* @param	fileName	ファイル名
	* @details	ファイルを読み込む
	*/
	JsonFile(const std::string& fileName);

	/**
	* @brief	コンストラクタ
	* @param	fileName	ファイル名
	* @param	writeData	書き込むデータ
	* @details	ファイルを書き込む
	*/
	JsonFile(const std::string& fileName, nlohmann::json writeData);	

	/**
	* @brief	デストラクタ
	*/
	~JsonFile();

public:

	/**
	* @brief	ファイル名を返す
	* @return	ファイル名(string型)
	*/
	std::string		GetFileName()	{ return _fileName; }

	/**
	* @brief	JSONデータを返す
	* @return	JSONデータ(nlohmann::json型)
	*/
	nlohmann::json	GetData()		{ return _jsonData; }

	/**
	* @brief	成功したかどうかを返す
	* @return	成功したらtrue
	*/
	bool Success() const { return _success; }

private:
	/**
	* @brief    デフォルトコンストラクタ
	* @details  初期化を禁止するために使用不可として定義
	*/
	JsonFile() = delete;	

	/**
	* @brief	初期化関数
	*/
	void Init();			

private:
	std::string		_fileName;	//! ファイルパス+ファイル名
	nlohmann::json	_jsonData;	//! JSONデータ

	bool	_success;	//! 成功したかどうか
};

