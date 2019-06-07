#include "Piece.h"

void Piece::Render()
{
	switch (m_pieceType)
	{
	case WHITE:
		cout << "œ";
		break;

	case BLACK:
		cout << "›";
		break;

	default:
		cout << " ";
		break;
	}
}
