#include "Field.h"

const int Field::FIELD_SIZE;

void Field::Initialize()
{
	for (int colomn = 0; colomn < FIELD_SIZE; ++colomn)
	{
		for (int row = 0; row < FIELD_SIZE; ++row)
		{
			m_pieces[colomn][row].SetPieceType(NONE);
		}
	}

	m_pieces[3][4].SetPieceType(WHITE); m_pieces[4][3].SetPieceType(WHITE);
	m_pieces[3][3].SetPieceType(BLACK); m_pieces[4][4].SetPieceType(BLACK);
}

void Field::Render()
{
	std::cout << "  0 1 2 3 4 5 6 7" << std::endl;

	for (int column = 0; column < FIELD_SIZE; ++column)
	{	
		std::cout << column << " ";

		for (int row = 0; row < FIELD_SIZE; ++row)
		{
			m_pieces[column][row].Render();
		}

		std::cout << std::endl;
	}
}

bool Field::CanPutPiece(Position pos, PieceType type)
{
	PieceType reverseType = (type == WHITE) ? BLACK : WHITE;
	bool canPut = false;

	//8方向チェック
	for (int i = 0; i < DIRECTION_MAX; ++i)
	{
		Position buff = pos + ADJACENT_POS[i];

		m_nextDirection = static_cast<Directon>(i);

		if (m_pieces[buff.m_column][buff.m_row].GetPieceType() != reverseType) continue;

		while (true)
		{
			buff = buff + ADJACENT_POS[i];

			if ((buff.m_column < 0 || buff.m_column > FIELD_SIZE - 1) ||
				(buff.m_row < 0    || buff.m_row > FIELD_SIZE - 1))
				break;

			//自分の逆の色か
			if (m_pieces[buff.m_column][buff.m_row].GetPieceType() == reverseType)
			{
				++m_reverseCount;	//裏返す枚数をカウントする
				continue;
			}

			//置けるかどうか
			if ((m_pieces[buff.m_column][buff.m_row].GetPieceType() == type)&&
				(m_pieces[pos.m_column][pos.m_row].GetPieceType() == NONE))
			{
				ReversePiece(pos, type); 
				canPut = true;
				break;
			}
		}
	}

	if (canPut)
	{
		m_pieces[pos.m_column][pos.m_row].SetPieceType(type);
		return true;
	}

	return false;
}

void Field::ReversePiece(Position pos, PieceType currentType)
{
	//駒の色を反転させる
	PieceType reverseType = (currentType == WHITE) ? BLACK : WHITE;

	//次の座標を保存する
	Position nextPos = pos;

	for (int i = 0; i <= m_reverseCount; ++i)
	{
		nextPos = nextPos + ADJACENT_POS[m_nextDirection];

		//裏返せなくなったらやめる
		if (m_pieces[nextPos.m_column][nextPos.m_row].GetPieceType() != reverseType)
		{
			m_reverseCount = 0;
			return;
		}

		m_pieces[nextPos.m_column][nextPos.m_row].SetPieceType(currentType);
	}

	m_reverseCount = 0;
}

PieceType Field::JudgeResult()
{
	PieceType winPiece = (m_blackCount > m_whiteCount) ? BLACK : WHITE;

	return winPiece;
}

bool Field::IsFinished()
{
	for (int column = 0; column < FIELD_SIZE; ++column)
	{
		for (int row = 0; row < FIELD_SIZE; ++row)
		{
			if (m_pieces[column][row].GetPieceType() == NONE)
			{
				m_whiteCount = 0; m_blackCount = 0;
				return false;
			}

			switch (m_pieces[column][row].GetPieceType())
			{
			case WHITE: ++m_whiteCount; break;
			case BLACK: ++m_blackCount; break;
			default:
				break;
			}
		}
	}

	return true;
}
