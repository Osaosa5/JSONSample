
#include "JsonManeger.h"


// 静的メンバ実体
std::unordered_map<std::string, nlohmann::json> JsonManeger::_mJson;

void JsonManeger::Init()
{
	_mJson.clear();
}

void JsonManeger::Release()
{
	ClearJson();
}

void JsonManeger::ClearJson()
{
    // すべてのデータの削除をする
    _mJson.clear();
}

nlohmann::json JsonManeger::LoadJsonFile(const std::string& fileName)
{
    // キーの検索
    auto itr = _mJson.find(fileName);
    if (itr != _mJson.end())
    {
        // キーがあった
        return itr->second;
    }
    // キーが無かった
    JsonFile json(fileName);
    // キーとデータをmapに登録
    _mJson[fileName] = json.GetData();

    return json.GetData();
}
