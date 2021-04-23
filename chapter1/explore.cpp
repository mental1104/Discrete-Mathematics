#include <iostream>
#include <fstream>

#include "./explore_1.hpp"
using namespace::std;

void test_1(){
    unsigned short n;
	cout << "What is the range you want to search?(0-2^n,you need to input n, not beyond 63)\n> ";
	cin >> n;
	if(n > 63)
		return;
    Explore_1_1 temp(n);
	temp.print();
}

int main(int argc, char** argv){
    if(argc!=2){
        printf("You should enter another num.\n");
        return 0;
    }
    int n = atoi(argv[1]);
    switch(n){
        case 1:
            test_1();
            break;
        default:
            printf("No such project.\n");
            break;
    }
}