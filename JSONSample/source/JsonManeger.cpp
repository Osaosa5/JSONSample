
#include "JsonManeger.h"


// �ÓI�����o����
std::unordered_map<std::string, nlohmann::json> JsonManeger::_mJson;

void JsonManeger::Init()
{
	_mJson.clear();
}

void JsonManeger::Release()
{
	ClearJson();
}

bool JsonManeger::DeleteJson(const std::string& fileName)
{
	// �L�[�̌���
	auto itr = _mJson.find(fileName);
	if (itr != _mJson.end())
	{
		// �L�[��������
		_mJson.erase(itr);
		return true;
	}
	// �L�[����������
	return false;
}

void JsonManeger::ClearJson()
{
    // ���ׂẴf�[�^�̍폜������
    _mJson.clear();
}

bool JsonManeger::IsJsonFile(const std::string& fileName)
{
	// �L�[�̌���
	auto itr = _mJson.find(fileName);

	// �L�[��������
	if (itr != _mJson.end()) return true;

	// �L�[����������
    return false;
}

nlohmann::json JsonManeger::LoadJsonFile(const std::string& fileName)
{
    // �L�[�̌���
    auto itr = _mJson.find(fileName);
    if (itr != _mJson.end())
    {
        // �L�[��������
        return itr->second;
    }
    // �L�[����������
    JsonFile json(fileName);
    // �L�[�ƃf�[�^��map�ɓo�^
    _mJson[fileName] = json.GetData();

    return json.GetData();
}
