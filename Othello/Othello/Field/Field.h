#pragma once

#include <iostream>

#include "Piece/Piece.h"

//8����
enum Directon
{
	TOP,
	TOP_RIGHT,
	RIGHT,
	BOTTOM_RIGHT,
	BOTTOM,
	BOTTOM_LEFT,
	LEFT,
	TOP_LEFT,
	DIRECTION_MAX
};

class Field
{
public:
	Field() 
	{
		Initialize();
	}

	~Field() {}

	//����������
	void Initialize();

	//�`�悷��
	void Render();

	/*
		���u��
		param pos �u�����W
		param type �u����̍��W
		return �u���邩�ǂ���
	*/
	bool CanPutPiece(Position pos, PieceType type);

	/*
		�������ʂ𔻒肷��
		return ���������ق��̋�̎��
	*/
	PieceType JudgeResult();

	/*
		�������I����������肷��
		return �������I����Ă��邩
	*/
	bool IsFinished();

	//�Q�b�^�[
	inline int GetBlackCount() { return m_blackCount; }
	inline int GetWhiteCount() { return m_whiteCount; }

private:
	/*
		���]������
		param pos�@���]��������W
		param currentType ���݂̋�̐F
	*/
	void ReversePiece(Position pos, PieceType currentType);

	static const int FIELD_SIZE = 8;

	const Position ADJACENT_POS[DIRECTION_MAX] =
	{
		{  0,  -1},
		{  1,  -1},
		{  1,   0},
		{  1,   1},
		{  0,   1},
		{ -1,   1},
		{ -1,   0},
		{ -1,  -1},
	};

	int m_reverseCount = 0;		//���Ԃ������̃J�E���g
	int m_whiteCount = 0;		//���s�Ɋւ��锒�F�̃J�E���g
	int m_blackCount = 0;		//���s�Ɋւ��鍕�F�̃J�E���g

	Piece m_pieces[FIELD_SIZE][FIELD_SIZE];
	Directon m_nextDirection;
};
