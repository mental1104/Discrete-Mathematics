/* 
Computer project 1.1
        
Given the truth values of the propositions p and q, find the
truth values of the conjunction, disjunction, exclusive or,
conditional statement, and biconditional of these propositions 

*/

#ifndef PROJECT_1_1_DISCRETE
#define PROJECT_1_1_DISCRETE

class Project_1_1{
public:
    Project_1_1() = delete;
    Project_1_1(int a, int b):x(a),y(b){}
    void print();

private:
    bool conjunction() {    return x&&y;  }
    bool disjunction() {    return x||y;  }
    bool XOR() {   return (x||y) && !(x&&y); }
    bool conditional() {    return !x||y;   }
    bool equivalence()  {   return x==y;   }
    bool x;
    bool y;
};

void
Project_1_1::print(){
    printf("conjunction:    %d\n",conjunction());
    printf("disjunction:    %d\n",disjunction());
    printf("exclusive or:   %d\n",XOR());
    printf("conditional:    %d\n",conditional());
    printf("equivalence:    %d\n",equivalence());
}
#endif