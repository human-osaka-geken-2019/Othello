#include <stdlib.h>

#include <map>

#include <crtdbg.h>

#include <cstdio>
#include <cstdlib>

#include "../Field/Field.h"

#define _CRTDBG_MAP_ALLOC
#define new ::new(_NORMAL_BLOCK, __FILE__, __LINE__)

//���͂����ʒu��Ԃ�
Position InputPos();

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	PieceType playerColor = BLACK;

	Field field;
	field.Render();

	std::map<PieceType, std::string> playerName
	{
		{WHITE, "��"},
		{BLACK, "��"}
	};

	//���C�����[�v
	while (true)
	{
		playerColor = (playerColor == WHITE) ? BLACK : WHITE;

		if (field.IsFinished())
		{
			std::cout << "��" << field.GetWhiteCount() << " , ��" << field.GetBlackCount() << std::endl;
			std::cout << "����" << playerName[field.JudgeResult()] << std::endl;

			getchar();
			break;
		}

		std::cout << "���݂̃^�[��" << playerName[playerColor] << std::endl;

		Position pos = InputPos();

		if(!field.CanPutPiece(pos, playerColor))
		{
			std::cout << "�u���܂���" << std::endl;

			//������x�����F�ɂ���
			playerColor = (playerColor == WHITE) ? BLACK : WHITE;
		}

		system("cls");

		field.Render();
	}

	return 0;
}

Position InputPos()
{
	Position pos;

	while (true)
	{
		std::cout << "�c,���̏��Ԃɐ�������͂��Ă�������" << std::endl;
		std::cin >> pos.m_column >> pos.m_row;

		if (std::cin.fail())
		{
			std::cout << "���͎��s���Ă��܂�" << std::endl;
			std::cin.clear();
			std::cin.ignore(1024, '\n');

			continue;
		}

		break;
	}

	return pos;
}
