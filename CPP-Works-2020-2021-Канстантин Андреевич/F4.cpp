#include <iostream>
using namespace std;
char c;
void A();
void B();
void S();
void gc(){
    c=cin.get();
}

void S(){
    cout<<"S -> AB"<<endl;
    A();
    B();
    if (c!='\n') {
        throw c;
    }
}
void A(){
    if (c=='a') {
        cout<<"A -> a"<<endl;
        gc();
    }else if(c=='c'){
        cout<<"A -> cA"<<endl;
        gc();
        A();
    }else{
        throw c;
    }
}
void B(){
    if (c=='b') {
        cout<<"B -> bA"<<endl;
        gc();
        A();
    }else{
        throw c;
    }
}
int main(){
    try {
        gc();
        S();
        cout<<"Success"<<endl;
    } catch (char c) {
        cerr<<"Error in: "<<c<<endl;
    }
    return 0;
}
