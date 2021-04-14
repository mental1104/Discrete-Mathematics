/* 3.Give a compound proposition, determine whether 
     it is satisfiable by checking its truth value for 
     all positive assignments of truth values to 
     its propositional variables
*/

#ifndef PROJECT_1_3_DISCRETE
#define PROJECT_1_3_DISCRETE

#include<unordered_map>
#include<stack>
#include<vector>
#include<algorithm>
#include<deque>

using namespace::std;

unordered_map<char, int> m{
    {'!', 0},//negation
    {'&', 1},//conjunction
    {'|', 2},//disjunction
    {'-', 3},//implication
    {'<', 4},//equivalence
    {'(', 5},//left_parenth
    {')', 6}//right_parenth
};

bool priority[5][7] = {
       //   !  &  | -> <-> (  )  
 /*!   */  {0, 1, 1, 1, 1, 1, 1},
 /*&   */  {0, 0, 1, 1, 1, 1, 1},
 /*|   */  {0, 0, 0, 1, 1, 1, 1},
 /*->  */  {0, 0, 0, 0, 1, 1, 1},
 /*<-> */  {0, 0, 0, 0, 0, 1, 1}
};

bool judge(char l, char r){
    return priority[m[l]][m[r]];
}

class Project_1_3{
public:
    Project_1_3() = delete;
    Project_1_3(const string& rhs):sourceString(rhs){ evaluate(); dfs(0); }
    string RPN() {  string str(_RPN.begin(),_RPN.end()); return str; }
    void print_table();
    void print_satisfiable();
private:
    void evaluate();
    bool yield();
    void dfs(int num);

    bool deny(bool p) { return !p; }
    bool And(bool p, bool q) { return p&&q; }
    bool Or(bool p, bool q) {return p||q; }
    bool contain(bool p, bool q){return !(p == true && q == false); }
    bool equal(bool p, bool q) { return p == q;}

    stack<char> E;//stack for evaluate
    stack<bool> Y;//stack for yielding truth table
    vector<char> _RPN;//RPN to convenient computation
    string sourceString;
    vector<char> total;//All name of Proposition
    unordered_map<char,bool> value;//value of propostion
    deque<deque<bool>> truth_table;
};

void 
Project_1_3::evaluate(){
    int size = sourceString.size();
    int i = 0;
    while(i < size){
        if(sourceString[i] >= 'a' && sourceString[i] <= 'z'){
            _RPN.push_back(sourceString[i]);
            vector<char>::iterator iter = find(total.begin(),total.end(),sourceString[i]);
            if(iter == total.end())
                total.push_back(sourceString[i]);
            i++;
        }
        else if(sourceString[i] == '('){
            E.push(sourceString[i]);
            i++;
        }
        else if(sourceString[i] == ')'){
            while(E.top()!='('){
                _RPN.push_back(E.top());
                E.pop();
            }
            E.pop();
            i++;
        }
        else if(E.empty()){
            E.push(sourceString[i]);
            if(sourceString[i] == '-') i++;
            if(sourceString[i] == '<') i=i+2;
            i++;
        }
        else{
            while(!judge(sourceString[i],E.top())){
                _RPN.push_back(E.top());
                E.pop();
                if(E.empty())
                    break;
            }
            E.push(sourceString[i]);
            if(sourceString[i] == '-') i++;
            if(sourceString[i] == '<') i = i+2;
            i++;
        }
    }
    while(!E.empty()){
        if(E.top()!='(' && E.top()!=')')
            _RPN.push_back(E.top());
        E.pop();
    }
}

void 
Project_1_3::dfs(int num){
    if(num == total.size()){
        deque<bool> temp;
        for(int i = 0; i<total.size(); i++)
            temp.push_back(value[total[i]]);
        temp.push_back(yield());
        truth_table.push_back(temp);
        return;
    }
    value[total[num]] = true;
    dfs(num+1);
    value[total[num]] = false;
    dfs(num+1);
}

bool 
Project_1_3::yield(){
    while(!Y.empty())
        Y.pop();
    
    int size = _RPN.size();
    for(int i = 0; i<size; i++){
        bool x,y;
        if(_RPN[i] >= 'a' && _RPN[i] <= 'z')
            Y.push(value[_RPN[i]]);
        else if(_RPN[i] == '!'){
            x = Y.top();
            Y.pop();
            Y.push(deny(x));
        }else{
            x = Y.top();
            Y.pop();
            y = Y.top();
            Y.pop();
            if(_RPN[i] == '&')
                Y.push(And(x,y));
            else if(_RPN[i] == '|')
                Y.push(Or(x,y));
            else if(_RPN[i] == '-')
                Y.push(contain(y,x));
            else if(_RPN[i] == '<')
                Y.push(equal(x,y));
        }
    }
    return Y.top();
}

void 
Project_1_3::print_table(){
    for(char c:total)
        cout << c << " ";
    cout << sourceString;
    cout << endl;
    int size;
    for(auto table:truth_table){
        size = table.size()-1;
        int i;
        for(i = 0; i < size; i++)
            cout << table[i] << " ";
        cout << "  " << table[i] <<endl;
    }
    return;
}
void
Project_1_3::print_satisfiable(){
    deque<deque<bool>> s;
    deque<bool> tmp = truth_table[0];
    bool satis = false;
    int size = tmp.size()-1;
    for(auto i:truth_table){
        if(i[size] == true){
            satis = true;
            s.push_back(i);
        }
    }
    if(satis == false)
        cout << "This proposition is not satisfiable!" << endl;
    else{
        cout << "Satisfiable." << endl;
        for(char c:total)
            cout << c << " ";
        cout << sourceString;
        cout << endl;

        int size;
        for(auto table:s){
            size = table.size()-1;
            int i;
            for(i = 0; i < size; i++)
                cout << table[i] << " ";
            cout << "  " << table[i] <<endl;
        }
    }
    return;
}


#endif