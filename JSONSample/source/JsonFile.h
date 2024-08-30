
#pragma once

#include <string>
#include <nlohmann/json.hpp>

class JsonFile
{
public:
	// �ǂݍ���
	JsonFile(const std::string& fileName);
	// ��������
	JsonFile(const std::string& fileName, nlohmann::json writeData);	

	~JsonFile();

	// �Q�b�^�[
	std::string		GetFileName()	{ return _fileName; }
	nlohmann::json	GetData()		{ return _jsonData; }

	bool Success() const { return _success; }

private:
	
	JsonFile() = default;	// �f�t�H���g�R���X�g���N�^

	void Init();			// ������

	std::string		_fileName;	// �t�@�C���p�X
	nlohmann::json	_jsonData;

	bool	_success;
};

