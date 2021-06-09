#include<iostream>
#include<vector>
#include"combination.h"

using namespace::std;

int main(){
    vector<int> v{1,2,3,4,5,6,7,8};
    R_Combination c1(v, 6);
    c1.printAll();
    std::cout << "---------------" << std::endl;
    vector<int> vec{1,2,3,4,5,6};
    R_Combination c2(vec, 4);
    for(int i = 0; i < 30; i++)
        c2.printNext();
    return 0;
}