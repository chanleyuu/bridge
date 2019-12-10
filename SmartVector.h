#pragma once
//
//  SmartVector.h
//  A custom Smart Vector implementation based on the std::vector
//
//  Created by Effirul I Ramlan on 01/12/2019.
//  Copyright © 2019 Effirul I Ramlan. All rights reserved.
//

#ifndef SmartVector_h
#define SmartVector_h

#include <iostream>
#include <vector>
#include <random>
#include <algorithm>

template<typename T>
class SmartVector {
private:
	std::vector<T> smartVector_;

	int genrand(int min, int max) {
		std::random_device r;
		std::seed_seq seed2{ r(), r(), r(), r(), r(), r(), r(), r() };
		std::mt19937 eng(seed2);
		std::uniform_real_distribution<float> dist(min, max);
		return dist(eng);
	}

public:
	// Constructor accepts std::vector
	SmartVector(const std::vector<T>& t) {
	}

	// Constructor accepts T array and array size
	SmartVector(const T t[], int s) {	
	}

	// Push function with T array and array size - similar to std::vector.push_back
	void Push(const T t[], int s) {
		for (int i = 0; i < s; i++) {
			smartVector_.push_back(t[i]);
		}
	}

	// Return the total sum of all elements inside the vector
	T Sum() {
		T total = smartVector_[0];
		for (int i = 1; i < smartVector_.size(); i++) {
			total = total + smartVector_[i];
		}
		return total;
	}

	// Sort the vector in ascending order
	void Sort() {
		std::sort(smartVector_.begin(), smartVector_.end());
	}

	// Random shuffle all element inside the vector - use random shuffle
	// Link: https://en.cppreference.com/w/cpp/algorithm/random_shuffle
	void Shuffle() {

	}

	// Return indexes for all matching elements (as std::vector) in the vector given the argument
	std::vector<int> Search(T match) {
	}

	// Return the element of a given index - similar to std::vector.at
	T At(int i) {
	}

	// Return the maximum size of the vector - similar to std::vector.size
	int Size() const {
	}

	// Return the element of vector from index b, until index e 
	SmartVector<T> Range(int b, int e) {
	}

	// Erase a vector element given index
	void Erase(int index) {
	}

};


#endif /* SmartVector_h */
