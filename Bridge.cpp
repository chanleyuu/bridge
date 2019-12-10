//
//  Bridge.cpp
//  Simplified Bridge Game without Bridge contract bidding
//
//  Created by Effirul I Ramlan on 01/12/2019.
//  Copyright © 2019 Effirul I Ramlan. All rights reserved.
//

#include <iostream>
#include <string>
#include "SmartVector.h"
#include "Player.h"

using namespace std;

Card* PopulateDeck(string suit);	// Use this function to populate the Card struct using each suit
int* FindMax(int a, int b, int c, int d);	// Find the max between 4 players
string DisplayCard(int winner, Card& c);	// Output formatting to show the winning card for each trick

int main(int argc, const char* argv[]) {

	// Follow this pseudocodes to complete the Bridge gameplay
	// 1. Populate the decks with spades, hearts, diamonds and clubs (13 each)
	// 2. Push each Card suit into the SmartVector (total 52 cards)
	// 3. Randomly Shuffle the card to 4 players - Use SmartVector.Shuffle and SmartVector.Range
	// 4. Find the maximum points in hand to set first turn
	// 5. Start Playing the round - Player with startTurn will put the best card to start and determine trump suit
	// 6. Continue with the game for 13 turns
	// 7. Calculate score for the tricks and display result
	
	// Feel free to add any additional utility function to facilitate the gameplay implementation

	return 0;
}

Card* PopulateDeck(string suit) {
	// In order to simplify sorting we are going to start the deck at 2
	// with 11 - Jack, 12 - Queen, 13 - King, 14 - Ace
}

int* FindMax(int a, int b, int c, int d) {
	// Find the highest hand total, and return the player start position
	// Use 0 - North, 1 - East, 2 - South and 3 - West as player id
}

string DisplayCard(int winner, Card& c) {
	// Format the output for display
	// Display the player id, and winning move for each trick
}

