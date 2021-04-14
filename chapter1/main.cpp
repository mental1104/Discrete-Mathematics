#include <iostream>
#include "./project_1.hpp" 
#include "./project_2.hpp"
#include "./project_3.hpp"
#include "./project_4.hpp"

using namespace::std;

void test_1(){
    int x, y;
    printf("Enter two truth value(0/1):\n> ");
    scanf("%d %d",&x,&y);
    if(x == 0 || x == 1 || y == 0 || y == 1){
        Project_1_1 truth_val(x,y);
        truth_val.print();
    }else
        printf("You've entered invalid truth value(not 0/1).\n");
    return;
}

void test_2(){
    printf("Enter two string bit(filled with 0 or 1) with the same size. (not beyond 64!)\n");
    string a, b;
    printf("Input the the first string of length: \n> ");
    cin >> a;
    printf("Now you should enter the second: \n> ");
    cin >> b;
    printf("Now checking...\n");
    if(a.size() == b.size() && a.size() <= 64){
        printf("Size of these bit string is %lu\n", a.size());
        Project_1_2 bit(a,b);
        bit.print();
    }else
        printf("The size of two string are not equal.\n");
    return;
}

void test_3(){
    cout << "Please enter a compound proposition." << endl << "> ";
    string p;
    if(cin >> p){
        Project_1_3 tmp(p);
        //tmp.print_table();
        //cout << "------------------------------------------------------------------" << endl;
        tmp.print_satisfiable();
    };
    
    return;
}

void test_4(){
    cout << "Please enter two proposition[0,1] to yield their fuzzy logic.\n" << "> ";
    double x, y;
    if(scanf("%lf %lf",&x,&y)){
        Project_1_4 tmp(x,y);
        tmp.print();
    }
    return;
}

void test_5(){
    return;
}

void test_6(){
    return;
}

int main(int argc, char** argv){
    if(argc!=2){
        printf("You should enter (1-6) to enter the corresponding project.\n");
        return 0;
    }

    int n = atoi(argv[1]);
    switch(n){
        case 1:
            test_1();
            break;
        case 2:
            test_2();
            break;
        case 3:
            test_3();
            break;
        case 4:
            test_4();
            break;
        case 5:
            test_5();
            break;
        case 6:
            test_6();
            break;
        default:
            printf("No such project.\n");
            break;
    }
    return 0;
}