//1 .----
//
//2 ..---
//
//3 ...--
//
//4 ....-
//
//5 .....
//
//6 -....
//
//7 --...
//
//8 ---..
//
//9 ----.
//
//0 -----
#include <iostream>
using namespace std;
enum{H,A,B,C,D,E};
int trans(){
    int code_num=0;
    int count=0;
    int free_count=0;
    int attitude=H;
    char code=cin.get();
    for (;;) {
        switch (attitude) {
            case H:
                if (code=='-') {
                    attitude=C;
                    code=cin.get();
                    count=1;
                    break;
                }else if (code=='.'){
                    attitude=A;
                    code=cin.get();
                    count=1;
                    break;
                }else{
                    throw code;
                }
                break;
            case A:
                if (count<4) {
                    if (code=='.') {
                        count++;
                        code=cin.get();
                    }else if (code=='-'){
                        attitude=B;
                        free_count=count+1;
                        code=cin.get();
                    }else{
                        throw code;
                    }
                }else{
                    if (code=='.') {
                        attitude=E;
                        code_num=code_num*10+5;
                        code=cin.get();
                    }else if (code=='-'){
                        attitude=E;
                        code_num=code_num*10+4;
                        code=cin.get();
                    }
                }
                break;
            case B:
                if (free_count<4) {
                    if (code=='-') {
                        free_count++;
                        code=cin.get();
                        break;
                    }else{
                        throw code;
                    }
                }else{
                    if (code=='-') {
                        code_num=code_num*10+count;
                        code=cin.get();
                        attitude=E;
                    }else{
                        throw code;
                    }
                }
                break;
            case C:
                if (count<4) {
                    if (code=='-') {
                        count++;
                        code=cin.get();
                    }else if (code=='.'){
                        attitude=D;
                        free_count=count+1;
                        code=cin.get();
                    }else{
                        throw code;
                    }
                }else{
                    if (code=='-') {
                        attitude=E;
                        code_num=code_num*10;
                        code=cin.get();
                    }else if (code=='.'){
                        attitude=E;
                        code=cin.get();
                        code_num=code_num*10+9;
                    }
                }
                break;
            case D:
                if (free_count<4) {
                    if (code=='.') {
                        free_count++;
                        code=cin.get();
                        break;
                    }else{
                        throw code;
                    }
                }else{
                    if (code=='.') {
                        code_num=code_num*10+(count+5);
                        code=cin.get();
                        attitude=E;
                    }else{
                        throw code;
                    }
                }
                break;
            case E:
                if (code==' ') {
                    count=0;
                    free_count=0;
                    attitude=H;
                    code=cin.get();
                }else if (code=='\n'){
                    return code_num;
                }else{
                    throw code;
                }
                break;
            default:
                break;
        }
    }
}
int main(int argc,char*argv[]){
    try {
        cout<<fixed<<trans()<<endl;
    } catch (char Err) {
        cerr<<"Error in Lexeme: "<<Err<<endl;
    }
}
