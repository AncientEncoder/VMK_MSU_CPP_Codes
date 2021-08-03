#include <iostream>
#include <cstring>
using namespace std;
string str;
char c;
void S();
void A();
void gc() {
    c = cin.get();
}

void S() {
    if (c == '0') {
        gc();
        A();
        str+='a';
    } else if (c == '1') {
        str+='b';
        gc();
        A();
    } else throw c;
}

void A() {
    if (c == '0') {
        str+='a';
        gc();
        A();
    } else if (c == '1') {
        str+='b';
        gc();
        A();
    } else if (c == '\n');
    else throw c;
}

int main(int argc,char* argv[]) {
    try {
        str="\n";
        gc();
        S();
        int count_1=0;
        int count_0=0;
        for (int i = 0; i <= str.length(); i++) {
            if (str[i] == 'b'){
                count_1++;
            }else if (str[i] == 'a'){
                count_0++;
            }
        }
        for (int i = 0; i < count_0; i++){
            cout << 'a';
        }
        for (int i = 0; i < count_1; i++){
            cout << 'b';
        }
        cout << endl;
    } catch (char c) {
        cerr << "Error in: " << c << endl;
    }
    return 0;
}
