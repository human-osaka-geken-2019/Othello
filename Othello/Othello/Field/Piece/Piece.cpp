#include "Piece.h"

void Piece::Render()
{
	switch (m_pieceType)
	{
	case WHITE:
		cout << "��";
		break;

	case BLACK:
		cout << "��";
		break;

	default:
		cout << "��";
		break;
	}
}
