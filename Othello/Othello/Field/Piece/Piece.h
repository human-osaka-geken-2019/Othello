#pragma once

#include <iostream>

using std::cout;

enum PieceType
{
	NONE,
	WHITE,
	BLACK,
};

//�I�Z���̈ʒu�����߂�\����
struct Position
{
public:
	int m_row;		//�s
	int m_column;	//��

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
	//�`��֐�
	void Render();

	//�Q�b�^�[
	inline PieceType GetPieceType() { return m_pieceType; }

	//�Z�b�^�[
	inline void SetPieceType(PieceType pieceType) { m_pieceType = pieceType; }

private:
	PieceType m_pieceType;
};
