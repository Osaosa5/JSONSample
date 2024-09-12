/**
 * @file	JsonManeger.h
 * @brief	JSONデータ管理クラスヘッダ
 * @details	JSONデータを管理するクラスのヘッダファイル
*/

#pragma once

#include	"JsonFile.h"

#include	<unordered_map>
#include	<string>

/**
 * @brief	JSONデータ管理クラス
 * @details	JSONデータを管理するクラス
*/
class JsonManeger
{
public:
	/**
	 * @brief	初期化処理を行う
	 * @details	クラスの内部リソースの初期化を行う
	 */
	static	void	Init();

	/**
	 * @brief	解放処理を行う
	 * @details	クラス内で使用しているリソースの解放を行う
	 */
	static	void	Release();

	/**
	* @brief		JSONデータを削除する
	* @param[in]	fileName 削除するJSONデータのファイル名
	* @return		削除に成功したらtrue, 失敗あるいはデータがなければfalse
	* @details		指定されたファイル名のJSONデータを削除する
	*/
	static	bool	DeleteJson(const std::string& fileName);

	/**
	 * @brief	JSONデータをすべてクリアする
	 * @details _mJson に保存されているすべてのデータを削除する
	 */
	static	void	ClearJson();

	/**
	* @brief		JSONファイルが登録されているか確認する
	* @param[in]	fileName 確認するファイル名
	* @return		登録されていればtrue, されていなければfalse
	*/
	static	bool	IsJsonFile(const std::string& fileName);

	/**
	 * @brief		JSONファイルを読み込む
	 * @param[in]	fileName 読み込むファイル名
	 * @return		読み込んだJSONデータを返す
	 * @details		指定されたファイルからJSONデータを読み込み、_mJson にキャッシュする
	 */
	static	nlohmann::json		LoadJsonFile(const std::string& fileName);

private:
	//! JSONファイル名をキーにして、対応するJSONデータを保持するマップ
	//! _mJson->(fileName, jsonData)
	static std::unordered_map<std::string, nlohmann::json> _mJson;
};

