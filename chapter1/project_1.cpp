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

int main(){
    int x, y;
    printf("> Enter a truth value (0/1): \n");

     while(cin >> x)
        if(x==0 || x==1)
            break;
        else
            printf("> Please enter (0/1). \n");
        
    
    printf("The truth value of propostion p is set to %c. \n", transform(x));

    printf("> Enter a truth value (0/1): \n");

    while(cin >> y)
        if(y==0 || y==1)
            break;
        else
            printf("> Please enter (0/1). \n");
        
    
    printf("The truth value of propostion q is set to %c. \n", transform(y));

    printf("\n\nThe truth value given is\n%c and %c\n", transform(x), transform(y));
    printf("conjunction:    %c\n",transform(conjunction(x,y)));
    printf("disjunction:    %c\n",transform(disjunction(x,y)));
    printf("exclusive or:   %c\n",transform(exclusive_or(x,y)));
    printf("conditional:    %c\n",transform(conditional_val(x,y)));
    printf("biconditional:  %c\n",transform(biconditional_val(x,y)));

    return 0;
}
