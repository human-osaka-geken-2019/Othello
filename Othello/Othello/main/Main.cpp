#include <stdlib.h>

#include <map>

#include <crtdbg.h>

#include <cstdio>
#include <cstdlib>

#include "../Field/Field.h"

#define _CRTDBG_MAP_ALLOC
#define new ::new(_NORMAL_BLOCK, __FILE__, __LINE__)

//入力した位置を返す
Position InputPos();

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	PieceType playerColor = BLACK;

	Field field;
	field.Render();

	std::map<PieceType, std::string> playerName
	{
		{WHITE, "白"},
		{BLACK, "黒"}
	};

	//メインループ
	while (true)
	{
		playerColor = (playerColor == WHITE) ? BLACK : WHITE;

		if (field.IsFinished())
		{
			std::cout << "白" << field.GetWhiteCount() << " , 黒" << field.GetBlackCount() << std::endl;
			std::cout << "勝者" << playerName[field.JudgeResult()] << std::endl;

			getchar();
			break;
		}

		std::cout << "現在のターン" << playerName[playerColor] << std::endl;

		Position pos = InputPos();

		if(!field.CanPutPiece(pos, playerColor))
		{
			std::cout << "置けません" << std::endl;

			//もう一度同じ色にする
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
		std::cout << "縦,横の順番に数字を入力してください" << std::endl;
		std::cin >> pos.m_column >> pos.m_row;

		if (std::cin.fail())
		{
			std::cout << "入力失敗しています" << std::endl;
			std::cin.clear();
			std::cin.ignore(1024, '\n');

			continue;
		}

		break;
	}

	return pos;
}
