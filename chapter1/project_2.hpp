/* 
Computer project 1.2
        
Given two bit strings of length n, find the bitwise AND,
bitwise OR, and bitwise XOR of these strings.

*/

#ifndef PROJECT_1_2_DISCRETE
#define PROJECT_1_2_DISCRETE

#include<bitset>
#include<string>

using std::string;
using std::bitset;

class Project_1_2{
public:
    Project_1_2() = delete;
    Project_1_2(const string &a, const string &b):x(bitset<64>(a)),y(bitset<64>(b)),size(a.size()){}
    void print();

private:
    bitset<64> AND(bitset<64> a, bitset<64> b);
    bitset<64> OR(bitset<64> a, bitset<64> b);
    bitset<64> XOR(bitset<64> a, bitset<64>);
    string to_str(bitset<64> bit);
    bitset<64> x;
    bitset<64> y;
    int size;
};

bitset<64> 
Project_1_2::AND(bitset<64> a, bitset<64> b){
    bitset<64> temp(a); 
    temp&=b;
    return temp;                                                                                                                                                                                                                                                                                                                                           
}

bitset<64> 
Project_1_2::OR(bitset<64> a, bitset<64> b){
    bitset<64> temp(a);
    temp|=b;
    return temp;
}

bitset<64> 
Project_1_2::XOR(bitset<64> a, bitset<64> b){
    bitset<64> temp(a);
    temp^=b;
    return temp;
}

string 
Project_1_2::to_str(bitset<64> bit){
    string temp = bit.to_string();
    string ret(temp.begin()+64-size, temp.end());
    return ret;
}

void
Project_1_2::print(){
    std::cout << "       " << to_str(x) << std::endl;
    std::cout << "       " << to_str(y) << std::endl;
    std::cout << "------------------------------------------------------------------------------" << std::endl;
    std::cout << "AND:   " << to_str(AND(x, y)) << std::endl;
    std::cout << "OR:    " << to_str(OR(x, y)) << std::endl;
    std::cout << "XOR    " << to_str(XOR(x, y)) << std::endl;
}
#endif