//
// Created by Eric on 11/8/2017.
//

#include "Points.hpp"
#include "../DoublingCube/DoublingCube.h"

void Points::addPoints(const std::string & winner) {
	// winning player gets points added
	if (winner == "black") {
		this->m_bPLayer += m_score;
	} else if (winner == "white") {
		this->m_wPlayer += m_score;
	}
}

// Declares a winner when the session is over
void Points::winnerReturn() {
	// If the black player has a higher score
	if (this->m_bPLayer > this->m_wPlayer) {
		std::cout << "Black player wins!" << std::endl;
	} else if (this->m_wPlayer > this->m_bPLayer) {
		std::cout << "White player wins!" << std::endl;
	} else {
		std::cout << "It's a tie!" << std::endl;
	}
}

// Applies the doubling cube value to the points value
void Points::doubleCubePoints() {
	this->m_score *= DoublingCube().getValue();
}