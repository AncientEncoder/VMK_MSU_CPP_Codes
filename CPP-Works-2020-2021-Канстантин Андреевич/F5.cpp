//a^nb^m
//b^n
#include <iostream>
using namespace std;
class Parser {
public:
    void getElement() {
        ch_get = cin.get();
        if (ch_get!='\n') {
            elements+=ch_get;
        }
    }

    Parser() {
        getElement();
        S();
    }

    void S() {
        if (ch_get == 'a') {
            A();
            B();
        } else if (ch_get == 'b') {
            B();
        }
    }

    void A() {
        if (ch_get == 'a') {
            getElement();
            A();
        } else if (ch_get == 'b') {
            getElement();
        }
    }

    void B() {
        if (ch_get == 'b') {
            getElement();
            B();
        }
    }
    bool analyze() {
        long len = elements.length();
        if (len == 0){
            return false;
        }
        if (elements[0] == 'a') {
            long intro=0;
            for (intro=0; intro<len; intro++) {
                if (elements[intro]=='b') {
                    break;
                }else if(elements[intro]!='a'){
                    return false;
                }
            }
            if (intro==len-1 && elements[intro]!='b') {
                return false;
            }else if(elements[intro]=='b'){
                return true;
            } else{
                for (intro=intro; intro<len; intro++) {
                    if (elements[intro]!='b') {
                        return false;
                    }
                }
            }
        } else if (elements[0] == 'b') {
            for (int i = 0; i < len; i++) {
                if (elements[i] != 'b')
                    return false;
            }
            return true;
        }
        return false;
    }
private:
    char ch_get;
    string elements;
};

int main(int argc,char* argv[]) {
    Parser parser;
    if (parser.analyze()){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }
    return 0;
}
