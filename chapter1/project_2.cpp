/* 
Computer project 1.2
        
Given two bit strings of length n, find the bitwise AND,
bitwise OR, and bitwise XOR of these strings.

*/

#include<iostream>
#include<bitset>
#include<string>

using namespace::std;

bitset<32> AND(bitset<32> a, bitset<32> b){
    bitset<32> temp(a); 
    temp&=b;
    return temp;                                                                                                                                                                                                                                                                                                                                           
}

bitset<32> OR(bitset<32> a, bitset<32> b){
    bitset<32> temp(a);
    temp|=b;
    return temp;
}

bitset<32> XOR(bitset<32> a, bitset<32> b){
    bitset<32> temp(a);
    temp^=b;
    return temp;
}


string to_str(bitset<32> bit, int n){
    string temp = bit.to_string();
    string ret(temp.begin()+32-n, temp.end());
    return ret;
}

int main(int argc, char** argv){
    if(argc!=2){
        printf("You should enter the length of bit strings(not beyond 32): n.\n");
        return 0;
    }
    int n = atoi(argv[1]);

    if(n > 32){
        printf("too large n!\n");
        return 0;
    }

    string a, b;
    printf("> Input the the first string of length %d: ",n);
    cin >> a;
    printf("> Now you should enter the second: ");
    cin >> b;
    printf("Now checking...\n");

    if(a.size() == n && b.size() == n){
        bitset<32> bit_string_1(a);
        bitset<32> bit_string_2(b);
        cout << "       " << a << endl;
        cout << "       " << b << endl;
        cout << "---------------------------------------" << endl;
        cout << "AND:   " << to_str(AND(bit_string_1, bit_string_2),n) << endl;
        cout << "OR:    " << to_str(OR(bit_string_1, bit_string_2),n) << endl;
        cout << "XOR    " << to_str(XOR(bit_string_1, bit_string_2),n) << endl;
    }else
        printf("The bit string you have entered is not equal to the length n given.\n");
    
    return 0;
}