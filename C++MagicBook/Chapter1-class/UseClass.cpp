//UseClass.cpp
#include "class.h"

int UseClass(void);

int UseClass(void)
{
	//----- �C���X�^���X�̍쐬(�I�u�W�F�N�g�̐���) -----

	//�I�u�W�F�N�g�������Ɏ����I�ɃR���X�g���N�^���Ă΂��

	POS a;//�f�t�H���g�R���X�g���N�^�ł̃I�u�W�F�N�g����

	POS b(10, 10);//�����̂���R���X�g���N�^�ł̃I�u�W�F�N�g����


	//�����o�̌Ăяo�����͍\���̂Ƒ債�ĕς��Ȃ�
	a.GetPosX();//�֐��̌Ăяo��

	a.SetPos(5, 5);//�����̂���֐��̌Ăяo��

	return 0;
	//return���ꂽ���ɁA�f�X�g���N�^�������ŌĂ΂��
}