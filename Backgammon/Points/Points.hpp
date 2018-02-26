//
// Created by Leslie on 11/6/2017.
#ifndef BACKGAMMON_POINTS_HPP
#define BACKGAMMON_POINTS_HPP

#include <iostream>

// to connect the doubling cube to the points
class Points {
public:

	// Starts each player's points at 0 at the start of the game session
	Points() : m_bPLayer(0), m_wPlayer(0), m_score(0) {};

	// Restarts overall score counter, but keeps points for two players (for follow up games in same session)
	Points(bool nextGame) : m_score(0) {};

	// Adds points at the end of the game (incomplete)
	void addPoints(const std::string &);

	// Declares a winner when the session is over
	void winnerReturn();

	// Applies the doubling cube value to the points value
	void doubleCubePoints();

private:
	// points for black player
	int m_bPLayer;
	// points for white player
	int m_wPlayer;
	// overall score of the game (what will be added to winner's total at the end of the game)
	int m_score;
};

#endif