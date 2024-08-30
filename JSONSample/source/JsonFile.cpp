
#include <fstream>
#include <iostream>
#include "JsonFile.h"

JsonFile::JsonFile(const std::string& fileName)
{
	// �����o�̏�����
	Init();

	// �t�@�C�����J��
	_fileName = fileName;
	std::ifstream ifs(fileName);

	// �t�@�C�����J���Ȃ������珈�����I��点��
	if (!ifs) return;

	// �ǂݍ��񂾃f�[�^���f�V���A���C�Y����
	ifs >> _jsonData;
	ifs.close();

	_success = true;
}

JsonFile::JsonFile(const std::string& fileName, nlohmann::json writeData)
{
	// �����o�̏�����
	Init();

	// �t�@�C�����J��
	_fileName = fileName;
	std::ofstream ofs(fileName);

	// �t�@�C�����J���Ȃ������珈�����I��点��
	if(!ofs) return;

	// �t�@�C���ɏ������ރf�[�^���V���A���C�Y����
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
