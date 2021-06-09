#include<iostream>
#include<vector>
#include"permutation.h"

using namespace::std;

int main(){

    vector<int> vec{1,2,3,4,5};
    Permutation p1(vec);
    p1.printAll();
    vector<int> v{1,2,3};
    Permutation p2(v);
    for(int i = 0; i<10; i++)
        p2.printNext();
    return 0;    
}