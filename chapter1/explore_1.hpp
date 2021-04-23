/* 
 * 1. Look for positive integers that are not the sum of the cubes
 * of nine different positive integers.
 */ 


#ifndef EXPLORATION_1_1_DISCRETE
#define EXPLORATION_1_1_DISCRETE

#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <cmath>
#include <bitset>
#include <map>

using std::multimap;
using std::vector;
using std::set;
using std::ofstream;
using std::bitset;
using std::endl;

class Explore_1_1{
public:
	Explore_1_1(){	yield();	}
	Explore_1_1(int seed):maxbit(seed){  yield();	}
	void print();
private:
	void yield();
	int bitCount(unsigned long long i);
	int maxbit = 10;
	multimap<unsigned long long, vector<int>> solutions;
	set<unsigned long long> non_solutions;
};

int 
Explore_1_1::bitCount(unsigned long long i){
	bitset<64> temp(i);
	return temp.count();
}



void 
Explore_1_1::yield(){
	unsigned long long limit = 1 << maxbit;
	vector<int> candidates;
	for(unsigned long long bit = 1; bit < limit; bit++){
		if(bitCount(bit)!= 9)
			continue;
		for(int i = 0; i < maxbit; i++){
			if((bit>>i)&0x1)
				candidates.push_back(i+1);
		}

		int sum = 0;
		for(int val: candidates)
			sum+=pow(val,3);

		solutions.emplace(sum, candidates);
		candidates.clear();
	}

	set<unsigned long long> temp;
	for(auto &t: solutions)
		temp.insert(t.first);
	
	for(unsigned long long bit = 1; bit < limit; bit++){
		auto iter = temp.find(bit);
		if(iter == temp.end())
			non_solutions.insert(bit);
	}
}

void 
Explore_1_1::print(){
	ofstream _os("./explore_1_solution.txt");
	ofstream _not("./explore_1_not_solution.txt");
	_not << "Num of not the cube of different integer: " << non_solutions.size() << endl;
	_os << "Num of the cube of different integer: " << solutions.size() << endl;
	

	int count = 0;
	for(unsigned long long i: non_solutions){
		_not << i << " ";
		count++;
		if(count == 13){
			count = 0;
			_not << endl;
		}
	}
		
			
		_not << endl;
	_not << endl;
	
	_os << "Sum:     parameter:" << endl;
	for(auto &val: solutions){
		_os << val.first << "    ";
		for(auto &v: val.second)
			_os << v << " ";
		_os << endl;
	}

	
}

#endif