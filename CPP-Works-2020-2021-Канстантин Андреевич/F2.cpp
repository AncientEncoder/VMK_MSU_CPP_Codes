#include <iostream>
using namespace std;
enum{H,A,B,S};
char c;
void g_translate(){
    c=cin.get();
}

void transmission(){
    string str;
    g_translate();
    int SC=H;
    do{
        switch (SC) {
            case H:
                if (c=='a') {
                    str='a';
                    SC=A;
                    g_translate();
                }else{
                    throw c;
                }
                break;
            case A:
                if (c=='a'|c=='d') {
                    if (c=='a') {
                        SC=B;
                        str+='a';
                        g_translate();
                        break;
                    }
                    if (c=='d') {
                        SC=A;
                        str+='d';
                        g_translate();
                        break;
                    }
                }else{
                    throw c;
                }
                break;
            case B:
                if (c=='a') {
                    SC=A;
                    str+='a';
                    g_translate();
                }else if (c=='\n'){
                    cout<<fixed<<str;
                    return;
                }else{
                    throw c;
                }
                break;
            default:
                break;
        }
    }while(true);
}
int main(int argc,char*argv[]){
    try {
        transmission();
    } catch (char c) {
        cerr<<"Error in Lexcem: "<<c<<endl;
    }
    return 0;
}
