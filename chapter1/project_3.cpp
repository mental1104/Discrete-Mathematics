#include<iostream>
#include<stack>
#include<vector>
#include<string>
#include<algorithm>
#include<unordered_map>
#include<deque>

using namespace::std;
stack<char> Stack;
stack<bool> P;
vector<char> RPN;
unordered_map<char, bool> value;

bool statisfiable = false;
deque<deque<bool>> table;
int cnt;

bool p[26];//To store the value of preposition.
vector<char> n;//name of prepostion


bool deny(bool p) { return !p; }
bool And(bool p, bool q) { return p&&q; }
bool Or(bool p, bool q) {return p||q; }
bool contain(bool p, bool q){return !(p == true && q == false); }
bool equal(bool p, bool q) { return p == q;}


bool judge(char p, char q){
    int x = 0;
    int y = 0;
    if(p == '!')
        x = 5;
    else if(p == '&')
        x = 4;
    else if(p == '|')
        x = 3;
    else if(p == '-')
        x = 2;
    else if(p == '<')
        x = 1;
    if(q == '!')
        y = 5;
    else if(q == '&')
        y = 4;
    else if(q == '|')
        y = 3;
    else if(q == '-')
        y = 2;
    else if(q == '<')
        y = 1;
    
    return x > y;
}



void evaluate(string s){
    int size = s.size();
    int i = 0;
    while(i<size){
        if(s[i] >='a' && s[i] <='z'){
            RPN.push_back(s[i]);
            vector<char>::iterator iter = find(n.begin(), n.end(), s[i]);
            if(iter == n.end())
                n.push_back(s[i]);
            i++;
        }
        else{
            if(s[i] == '('){
                Stack.push(s[i]);
                i++;
            }
            else if(s[i] == ')'){
                while(Stack.top()!='('){
                    RPN.push_back(Stack.top());
                    Stack.pop();
                }
                Stack.pop();
                i++;
            }
            else{
                if(Stack.empty()){
                    Stack.push(s[i]);
                    if(s[i] == '-') i++;
                    if(s[i] == '<') i=i+2;
                    i++;
                }else{
                    while(!judge(s[i],Stack.top())){
                        RPN.push_back(Stack.top());
                        Stack.pop();
                        if(Stack.empty())
                            break;
                    }
                    Stack.push(s[i]);
                    if(s[i] == '-') i++;
                    if(s[i] == '<') i=i+2;
                    i++;
                }
            }
        }
    }
    while(!Stack.empty()){
        if(Stack.top()!='(' && Stack.top()!=')')
            RPN.push_back(Stack.top());
        Stack.pop();
    }
}

bool yield(){
    while(!P.empty())
        P.pop();
    
    int size = RPN.size();
    for(int i = 0; i<size; i++){
        bool x,y;
        if(RPN[i] >='a' && RPN[i] <='z')
            P.push(value[RPN[i]]);
            
        else if(RPN[i] == '!'){
            x = P.top();
            P.pop();
            P.push(deny(x));
        }else{
            x = P.top();
            P.pop();
            y = P.top();
            P.pop();
            if(RPN[i] == '&')
                P.push(And(x,y));
            else if(RPN[i] == '|')
                P.push(Or(x,y));
            else if(RPN[i] == '-')
                P.push(contain(y,x));
            else if(RPN[i] == '<')
                P.push(equal(x,y));
        }
    }
    return P.top();
}

void dfs(int seed){
    if(seed == cnt){
        if(yield()){
            deque<bool> temp;
            for(int i = 0; i<cnt; i++)
                temp.push_back(value[n[i]]);
            table.push_back(temp);
        }
        return;
    }
    value[n[seed]] = true;
    dfs(seed+1);
    value[n[seed]] = false;
    dfs(seed+1);

}

int main(void){
    string sourceString;
    cout << "Please enter a compound proposition." << endl << "> ";
    cin >> sourceString;
    evaluate(sourceString);
    cout << "RPN: ";
    for(auto i: RPN){
        cout << i;
    }
    cout << endl;
    cnt = n.size();
    
    dfs(0);
    if(table.empty())
        cout << "This proposition is unstatisfiable!" << endl;
    else{
        cout << "Satisfiable." << endl; 
        for(auto i: n)
            cout << i << " ";
        cout << endl;
        for(auto i: table){
            for(auto j:i)
                cout << j << " ";
            cout << endl;
        }            
    }
    return 0;
}