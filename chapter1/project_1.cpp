/* 
Computer project 1.1
        
Given the truth values of the propositions p and q, find the
truth values of the conjunction, disjunction, exclusive or,
conditional statement, and biconditional of these propositions 

*/

#include<iostream>
using namespace::std;

bool conjunction(bool a, bool b){
    return a && b;
}

bool disjunction(bool a, bool b){
    return a || b;
}

bool exclusive_or(bool a, bool b){
    return (a||b) && !(a&&b);
}

bool conditional_val(bool a, bool b){
    return !a || b;
}

bool biconditional_val(bool a, bool b){
    return a == b;
}

 char transform(int val){
    if(val)
        return 'T';
    else
        return 'F';
}

int main(int argc, char** argv){
    if(argc!=3){
        printf("You should enter two truth value.\n");
        return 0;
    }
    int x, y;
    x = atoi(argv[1]);
    y = atoi(argv[2]);
    printf("%d %d\n",x,y);
    if(x==0 || x==1 || y==0 || y==1){
        printf("The truth value of propostion p and q is set to \n%c %c. \n", transform(x),transform(y));
        printf("conjunction:    %c\n",transform(conjunction(x,y)));
        printf("disjunction:    %c\n",transform(disjunction(x,y)));
        printf("exclusive or:   %c\n",transform(exclusive_or(x,y)));
        printf("conditional:    %c\n",transform(conditional_val(x,y)));
        printf("biconditional:  %c\n",transform(biconditional_val(x,y)));
    } else 
        printf("You should enter (0/1).\n");
    
    
    return 0;
}
