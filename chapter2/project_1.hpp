/* 1. Given subsets A and B of a set with n elements, use bit
 * strings to find A, A ∪ B, A ∩ B, A − B, and A ⊕ B.
 */

#ifndef PROJECT_2_1_DISCRETE
#define PROJECT_2_1_DISCRETE

#include <iostream>
#include <string>
#include <bitset>

using std::bitset;
using std::string;
using std::cout;
using std::endl;

class Project_2_1{
public:
    Project_2_1() = delete;
    Project_2_1(const string& a, const string& b):x(bitset<64>(a)), y(bitset<64>(b)),_size(a.size()){}

    void print();
private:
    bitset<64> set_union();
    bitset<64> set_intersection();
    bitset<64> set_difference();
    bitset<64> set_XOR();
    string to_str(bitset<64> bit);

    bitset<64> x;
    bitset<64> y;
    int _size;
};

bitset<64> 
Project_2_1::set_union(){
    bitset<64> temp(x); 
    temp|=y;
    return temp; 
}

bitset<64> 
Project_2_1::set_intersection(){
    bitset<64> temp(x); 
    temp&=y;
    return temp; 
}

bitset<64>
Project_2_1::set_difference(){
    bitset<64> temp(x); 
    temp&=~y;
    return temp; 
}

bitset<64>
Project_2_1::set_XOR(){
    bitset<64> temp(x); 
    temp^=y;
    return temp; 
}

string 
Project_2_1::to_str(bitset<64> bit){
    string temp = bit.to_string();
    string ret(temp.begin()+64-_size, temp.end());
    return ret;
}

void 
Project_2_1::print(){
    cout << "              "  << to_str(x) << endl;
    cout << "              "  << to_str(y) << endl;
    cout << "-----------------------------------------------------------------" << endl;
    cout << "Union:        "  << to_str(set_union()) << endl;
    cout << "Intersection: "  << to_str(set_intersection()) << endl;
    cout << "Difference:   "  << to_str(set_difference()) << endl;
    cout << "XOR:          "  << to_str(set_XOR()) << endl;
}

#endif