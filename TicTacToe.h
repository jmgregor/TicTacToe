#pragma once
class TicTacToe
{
public:
	//constructor
	TicTacToe() {
		xMoves_ = 0;
		oMoves_ = 0;
	}

	//getters
	int xMoves() const { return xMoves_; }
	int oMoves() const { return oMoves_; }

	//setters
	void set_xMoves(int xMoves);
	void set_oMoves(int oMoves);

private:
	int xMoves_;
	int oMoves_;
};

