/**
 * @file	JsonManeger.h
 * @brief	JSON�f�[�^�Ǘ��N���X�w�b�_
 * @details	JSON�f�[�^���Ǘ�����N���X�̃w�b�_�t�@�C��
*/

#pragma once

#include	"JsonFile.h"

#include	<unordered_map>
#include	<string>

/**
 * @brief	JSON�f�[�^�Ǘ��N���X
 * @details	JSON�f�[�^���Ǘ�����N���X
*/
class JsonManeger
{
public:
	/**
	 * @brief	�������������s��
	 * @details	�N���X�̓������\�[�X�̏��������s��
	 */
	static	void	Init();

	/**
	 * @brief	����������s��
	 * @details	�N���X���Ŏg�p���Ă��郊�\�[�X�̉�����s��
	 */
	static	void	Release();

	/**
	* @brief		JSON�f�[�^���폜����
	* @param[in]	fileName �폜����JSON�f�[�^�̃t�@�C����
	* @return		�폜�ɐ���������true, ���s���邢�̓f�[�^���Ȃ����false
	* @details		�w�肳�ꂽ�t�@�C������JSON�f�[�^���폜����
	*/
	static	bool	DeleteJson(const std::string& fileName);

	/**
	 * @brief	JSON�f�[�^�����ׂăN���A����
	 * @details _mJson �ɕۑ�����Ă��邷�ׂẴf�[�^���폜����
	 */
	static	void	ClearJson();

	/**
	* @brief		JSON�t�@�C�����o�^����Ă��邩�m�F����
	* @param[in]	fileName �m�F����t�@�C����
	* @return		�o�^����Ă����true, ����Ă��Ȃ����false
	*/
	static	bool	IsJsonFile(const std::string& fileName);

	/**
	 * @brief		JSON�t�@�C����ǂݍ���
	 * @param[in]	fileName �ǂݍ��ރt�@�C����
	 * @return		�ǂݍ���JSON�f�[�^��Ԃ�
	 * @details		�w�肳�ꂽ�t�@�C������JSON�f�[�^��ǂݍ��݁A_mJson �ɃL���b�V������
	 */
	static	nlohmann::json		LoadJsonFile(const std::string& fileName);

private:
	//! JSON�t�@�C�������L�[�ɂ��āA�Ή�����JSON�f�[�^��ێ�����}�b�v
	//! _mJson->(fileName, jsonData)
	static std::unordered_map<std::string, nlohmann::json> _mJson;
};

