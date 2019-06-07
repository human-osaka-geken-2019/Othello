#pragma once

#include <iostream>

using std::cout;

enum PieceType
{
	NONE,
	WHITE,
	BLACK,
};

//オセロの位置を決める構造体
struct Position
{
public:
	int m_row;		//行
	int m_column;	//列

	Position operator + (const Position& rhs)
	{
		Position result =
		{
			{m_row + rhs.m_row},
			{m_column + rhs.m_column }
		};

		return result;
	}
};

class Piece
{
public:
	//描画関数
	void Render();

	//ゲッター
	inline PieceType GetPieceType() { return m_pieceType; }

	//セッター
	inline void SetPieceType(PieceType pieceType) { m_pieceType = pieceType; }

private:
	PieceType m_pieceType;
};
