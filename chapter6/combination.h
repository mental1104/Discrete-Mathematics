#ifndef GENERATING_COMBINATION
#define GENERATING_COMBINATION

#include<iostream>
#include<vector>
using std::vector;

class R_Combination{
public:
    R_Combination() = delete;
    R_Combination(const vector<int>& rhs, int r);
    void printAll();
    void printNext();
    bool check();
private:
    void next();
    vector<int> origin;
    vector<int> curr;
};

R_Combination::R_Combination(const vector<int>& rhs, int r){
    origin = rhs;
    curr.resize(r);
    for(int i = 0; i<r; i++)
        curr[i] = origin[i];
}

bool
R_Combination::check(){
    int size = origin.size()-curr.size();//2
    int s = curr.size();//4
    for(int i = 0; i<s; i++){
        if(curr[i]!=origin[size+i])
            return true;
    }
    return false;
}

void 
R_Combination::printNext(){
    if(check()){
        next();
        for(int i:curr)
            std::cout << i << " ";
        std::cout << std::endl;
    }else
        std::cout << "End-Of-File.\n";
    
}
void 
R_Combination::next(){//This code is buggy!!!!!!!!!
    int n = origin.size();
    int r = curr.size();
    int i = r;
    while(curr[i] = n-r+i)
        i = i-1;
    curr[i] = curr[i]+1;
    for(int j = i+1; j<=r; j++)
        curr[j] = curr[i] + j -i;
    
    for(int i = 0; i<curr.size(); i++)
        curr[i] = curr[i+1];
}

void 
R_Combination::printAll(){
    int n = origin.size();
    int r = curr.size();
    int temp = n-r;
    unsigned long long n_permutation = 1, factorial_r = 1;
    while(n!=temp){
        n_permutation = n_permutation *n;
        n--;
    }

    while(r!=0){
        factorial_r = factorial_r * r;
        r--;
    }
    
    unsigned long long total = n_permutation/factorial_r;
    std::cout << "Size: " << n_permutation << " " << factorial_r << " " << total << std::endl;

    for(int i:curr)
        std::cout << i << " ";
    std::cout << std::endl;

    for(int i = 1; i<total ; i++){
        next();
        for(int i:curr)
            std::cout << i << " ";
        std::cout << std::endl;
    }
    
}

#endif