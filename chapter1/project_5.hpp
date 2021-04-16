/* 5. Given positive integers m and n, interactively play the
 * game of Chomp
 */

#ifndef PROJECT_1_5_DISCRETE
#define PROJECT_1_5_DISCRETE

#include<iostream>
#include<vector>
using namespace::std;

class Project_1_5{
public:
    Project_1_5(){  init();  }
    Project_1_5(int a, int b):m(a),n(b){    init();   }
    void play();
private:
    vector<vector<char>> chomp;
    void print();
    bool eat(int x, int y);
    void init();
    int m = 4;
    int n = 4;
};

void
Project_1_5::init(){
    chomp.resize(m);
    vector<char> first;
    first.resize(n);
    first[0] = 'P';
    for(int i = 1; i < n; i++){
        first[i] = 'O';
    }
    chomp[0] = first;
    for(int i = 1; i < m; i++){
        vector<char> temp;
        temp.resize(n);
        for(int j = 0; j < n; j++)
            temp[j] = 'O';
        chomp[i] = temp;
    }
}

void 
Project_1_5::print(){
    for(auto i: chomp){
        for(char j:i)
            cout << j;
        cout << endl;
    }
}

bool
Project_1_5::eat(int x, int y){
    if(chomp[x-1][y-1] == 'O'){
        for(int i = x-1; i < m; i++)
            for(int j = y-1; j < n; j++)
                chomp[i][j] = 'X';
        return true;
    }
    else{
        printf("You cannot eat what the other player already eats.\n");
        return false;
    }
}

void 
Project_1_5::play(){
    printf("--------------CHOMP--------------\n");
    print();
    printf("--------------CHOMP--------------\n");
    printf("You should eat the rest of chomp(1<=x<=m and 1<=y<=n)\n");
    char Player;
    int x, y;
    bool PlayerA = true, PlayerB = true;
    while(PlayerA && PlayerB){
        x = 0, y = 0;
        Player = 'A';
        while(1){
            printf("For Player %c: \n> ", Player);
            while(scanf("%d %d",&x,&y)){
                if(x>=1 && x <=m && y>=1 && y<=n) break;
                printf("You've entered invalid parameter!\n> ");
            }
    
            if(x == 1 && y == 1){
                printf("Player %c Lost\n", Player);
                PlayerA = false;
                break;
            }
            if(eat(x,y))
                break;
        }
        if(!PlayerA)  break;
        printf("--------------CHOMP--------------\n");
        print();
        printf("--------------CHOMP--------------\n");

        Player = 'B';
        x = 0, y = 0;
        while(1){
            printf("For Player %c: \n> ", Player);
            while(scanf("%d %d",&x,&y)){
                if(x>=1 && x <=m && y>=1 && y<=n) break;
                printf("You've entered invalid parameter!\n> ");
            }
            if(x == 1 && y == 1){
                printf("Player %c Lost\n", Player);
                PlayerB = false;
                break;
            }
            if(eat(x,y))
                break;
        }
        if(!PlayerB)  break;
        printf("--------------CHOMP--------------\n");
        print();
        printf("--------------CHOMP--------------\n");
    }
}

#endif