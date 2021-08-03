#include<iostream>
using namespace std;

char c;
void S();
void A();

void gc(){
    c = cin.get();
}

void S(){
    if(c == '0'){
        gc();
        S();
        cout << 'b';
    }else if( c == '1'){
        cout << 'a';
        gc();
        A();
    }
    else throw c;
}

void A(){
    if(c == '1'){
        cout << 'a';
        gc();
        A();
    }else if(c == '\n');
    else
        throw c;
}
int main(){
    try{
        gc();
        S();
        cout << endl;
    }catch(char c){
        cerr << "Error in: " << c << endl;
    }
    return 0;
}
