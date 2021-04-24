#include <iostream>
#include "./project_1.hpp"
using namespace::std;

void test_1(){
    string x, y;
    printf("Please enter two bit strings with same length.\n> ");
    cin >> x;
    cout << "> ";
    cin >> y;
    if(x.size()!= y.size()){
        printf("The size of two bit strings are not the same.\n");
        return;
    }
    Project_2_1 temp(x,y);
    temp.print();
    return;
}

int main(int argc, char** argv){
    if(argc!=2){
        printf("Please enter the corresponding project number.\n");
        return 0;
    }
    int n = atoi(argv[1]);

    switch(n){
        case 1:
            test_1();
            break;
        default:
            printf("No such project.\n");
    }
}