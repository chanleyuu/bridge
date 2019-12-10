#pragma once
//
//  Player.h
//  Bridge
//
//  Created by Effirul I Ramlan on 01/12/2019.
//  Copyright © 2019 Effirul I Ramlan. All rights reserved.
//

#ifndef Player_h
#define Player_h
#include "SmartVector.h"

struct Card {
	int value_;		// value from 2 - 14, 11 - Jack, 12 - Queen, 13 - King and 14 - Ace
	std::string suit_;	// spade, heart, diamond and club

	// overload the less than operator (<)
	bool operator<(const Card& c) const {
	}

	// overload the equality operator (==)
	bool operator==(const Card& c) const {
	}
};

class Player {
private:
	SmartVector<Card> hand_;	// each player has 13 random cards
	Card played_;	// card that is played during a turn

public:
	Player(SmartVector<Card> c);	// custom constructor for Player
	bool PlayCard(Card bestCard, std::string trump, int turn);		// function to play a card 
	std::string GetTrumpSuit();		// function to return the highest suit in a hand
	int GetHandTotal();		// return the total hand calculation
	void RemoveCard();		// remove a card from hand
	Card GetPlayed() const;		// return played_
};

#endif /* Player_h */

