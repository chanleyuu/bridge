//
//  Player.cpp
//  Bridge
//
//  Created by Effirul I Ramlan on 07/12/2019.
//  Copyright © 2019 Effirul I Ramlan. All rights reserved.
//

#include "Player.h"

// Constructor for the Player class
Player::Player(SmartVector<Card> c) : hand_{ c } {
}

// Play card is a function to play a card given a turn, the general strategy is
// 1. If it is the first turn for the first player - play the best card
// 2. For other turn, follow suit and play,
// 2.1 Your best card, if you can beat the current bestCard 
// 2.2 Your lowest card, if you are unable to beat the current bestCard
//
// 3. If you can't follow suit, you should,
// 3.1 Play a trump card, only if there is no trump card being played OR you can over-trump
// 3.2 Play the lowest card you have (last option)
//
// Return true, if you are beating the current bestCard, and false otherwise
//
bool Player::PlayCard(Card bestCard, std::string trump, int turn) {
	hand_.Sort();
	Card Highcard = hand_[hand_.Size() - 1];
	if (turn == 1) {
		played_ = Highcard;
		return true;
	}
	else {
		std::vector<int> high = hand_.Search(bestCard);
		int athand = high[high.size() - 1];
		if (athand > 0) {
			Highcard = hand_[athand];
		}
		else {
			Highcard = hand_[0];
		}
	}
	played_ = Highcard;
	if (Highcard > bestCard) {
		return true;
	}
	return false;
}


// Return the suit with the highest representation in your hand
std::string Player::GetTrumpSuit() {
}

// Return the hand total following the rules,
// +4 if you have an ace, +3 if you have a king, +2 for queen and +1 for jack
int Player::GetHandTotal() {
}

// Remove a card from your hand
void Player::RemoveCard() {
}

Card Player::GetPlayed() const {
	return played_;
}

