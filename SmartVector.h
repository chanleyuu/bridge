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

	T operator [](int i) const { return smartVector_[i]; }
	T& operator [](int i) { return smartVector_[i]; }
	// Constructor accepts std::vector
	SmartVector(const std::vector<T>& t) : smartVector_{ t } {
	}

	// Constructor accepts T array and array size
	SmartVector(const T t[], int s) {	
		for (int i = 0; i < s; i++) {
			smartVector_.push_back(t[i]);
		}
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
		for (int i = 0; i < smartVector_.size(); i++) {
			int rand = genrand(0, smartVector_.size());
			smartVector_[i] += smartVector_[rand];
			smartVector_[rand] = smartVector_[i] - smartVector_[rand];
			smartVector_[i] = smartVector_[i] - smartVector_[rand];
		}
	}

	// Return indexes for all matching elements (as std::vector) in the vector given the argument
	std::vector<int> Search(T match) {
		int temp;
		std::vector<int> out;
		int start = smartVector_.begin();
		while (temp != smartVector_.end()) {
			temp = std::search(start, smartVector_.end(), match);

			if (temp != smartVector_.end()) {
				out.push_back(temp);
				start = temp + 1;
			}
		}
		return out;
	}

	// Return the element of a given index - similar to std::vector.at
	T At(int i) {
		return smartVector_[i];
	}

	// Return the maximum size of the vector - similar to std::vector.size
	int Size() const {
		return smartVector_.size();
	}

	// Return the element of vector from index b, until index e 
	SmartVector<T> Range(int b, int e) {
		std::vector<T> e;
		SmartVector<T> out;
		
		for (int i = b; i <= e; i++) {
			e.push_back(smartVector_[i]);
		}

		out.Push(e, e.size());
		return out;
	}

	// Erase a vector element given index
	void Erase(int index) {
		smartVector_.erase(smartVector_.begin() + index);
	}

};


#endif /* SmartVector_h */
