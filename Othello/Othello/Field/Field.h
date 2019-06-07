#pragma once

#include <iostream>

#include "Piece/Piece.h"

//8方向
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

	//初期化する
	void Initialize();

	//描画する
	void Render();

	/*
		駒を置く
		param pos 置く座標
		param type 置く駒の座標
		return 置けるかどうか
	*/
	bool CanPutPiece(Position pos, PieceType type);

	/*
		試合結果を判定する
		return 勝利したほうの駒の種類
	*/
	PieceType JudgeResult();

	/*
		試合が終わったか判定する
		return 試合が終わっているか
	*/
	bool IsFinished();

	//ゲッター
	inline int GetBlackCount() { return m_blackCount; }
	inline int GetWhiteCount() { return m_whiteCount; }

private:
	/*
		反転させる
		param pos　反転させる座標
		param currentType 現在の駒の色
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

	int m_reverseCount = 0;		//裏返す枚数のカウント
	int m_whiteCount = 0;		//勝敗に関する白色のカウント
	int m_blackCount = 0;		//勝敗に関する黒色のカウント

	Piece m_pieces[FIELD_SIZE][FIELD_SIZE];
	Directon m_nextDirection;
};
