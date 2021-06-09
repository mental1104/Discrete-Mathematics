#ifndef GENERATING_PERMUTATION
#define GENERATING_PERMUTATION
//algorithm 1 Generating the Next Permutation in Lexicographic Order. 

#include<iostream>
#include<vector>

using std::vector;

class Permutation{
public:
    Permutation() = delete;
    Permutation(const vector<int>& rhs):origin(rhs),curr(rhs){}

    void printNext();
    void printAll();
    bool check();

private:
    void next();
    vector<int> origin;
    vector<int> curr;
};

bool 
Permutation::check(){
    int size = origin.size();
    for(int i = 0; i<size-1; i++)
        if(curr[i]<curr[i+1])
            return true;
    return false;
}

void 
Permutation::next(){
    int size = curr.size()-1;
    int j = size-1;
    while(curr[j]>curr[j+1])
        j = j-1;
    int k = size;
    while(curr[j]>curr[k])
        k = k-1;
    
    int temp = curr[j];
    curr[j] = curr[k];
    curr[k] = temp;

    int r = size;
    int s = j+1;
    while(r>s){
        int temp = curr[r];
        curr[r] = curr[s];
        curr[s] = temp;
        r = r-1;
        s = s+1;
    }
}

void 
Permutation::printNext(){
    if(check()){
        next();
        for(int i:curr)
            std::cout << i << " ";
        std::cout << std::endl;
    }else
        std::cout << "End Of File.\n";
}

void 
Permutation::printAll(){
    unsigned long long total = 1;
    int size = origin.size();
    while(size!=0){
        total = total*size;
        size--;
    }
    std::cout << "Size: " << total << std::endl;
    for(int i:origin)
        std::cout << i << " ";
    std::cout << std::endl;
    for(int i = 1; i < total; i++){
        next();
        for(int i:curr)
            std::cout << i << " ";
        std::cout << std::endl;
    }
}


#endif