/**
* @file		JsonFile.h
* @brief	JSON�t�@�C���N���X�w�b�_
*/

#pragma once

#include <string>
#include <nlohmann/json.hpp>

/**
* @brief	JSON�t�@�C���N���X
* @details	JSON�t�@�C����ǂݍ��ށA��������
*/
class JsonFile
{
public:
	/**
	* @brief	�R���X�g���N�^
	* @param	fileName	�t�@�C����
	* @details	�t�@�C����ǂݍ���
	*/
	JsonFile(const std::string& fileName);

	/**
	* @brief	�R���X�g���N�^
	* @param	fileName	�t�@�C����
	* @param	writeData	�������ރf�[�^
	* @details	�t�@�C������������
	*/
	JsonFile(const std::string& fileName, nlohmann::json writeData);	

	/**
	* @brief	�f�X�g���N�^
	*/
	~JsonFile();

public:

	/**
	* @brief	�t�@�C������Ԃ�
	* @return	�t�@�C����(string�^)
	*/
	std::string		GetFileName()	{ return _fileName; }

	/**
	* @brief	JSON�f�[�^��Ԃ�
	* @return	JSON�f�[�^(nlohmann::json�^)
	*/
	nlohmann::json	GetData()		{ return _jsonData; }

	/**
	* @brief	�����������ǂ�����Ԃ�
	* @return	����������true
	*/
	bool Success() const { return _success; }

private:
	/**
	* @brief    �f�t�H���g�R���X�g���N�^
	* @details  ���������֎~���邽�߂Ɏg�p�s�Ƃ��Ē�`
	*/
	JsonFile() = delete;	

	/**
	* @brief	�������֐�
	*/
	void Init();			

private:
	std::string		_fileName;	//! �t�@�C���p�X+�t�@�C����
	nlohmann::json	_jsonData;	//! JSON�f�[�^

	bool	_success;	//! �����������ǂ���
};

