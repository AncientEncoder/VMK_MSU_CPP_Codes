#include <iostream>
using namespace std;
enum{H,N,P,S};
char c;
void gc(){
    c=cin.get();
}
double Parser(){
    double num=0;
    double dec=0.1;
    int CS=H;
    gc();
    do{
        switch (CS) {
            case H:
                if (c=='0'||c=='1') {
                    num=c-'0';
                    CS=N;
                    gc();
                }else{
                    throw c;
                }
                break;
            case N:
                if (c=='0'||c=='1') {
                    num=10.*num+c-'0';
                    CS=N;
                    gc();
                }else if (c=='.'){
                    CS=P;
                    gc();
                }else{
                    throw c;
                }
                break;
            case P:
                if (c=='0'||c=='1') {
                    num=num+dec*(c-'0');
                    CS=S;
                    gc();
                }else{
                    throw c;
                }
            case S:
                if (c=='0'||c=='1') {
                    dec*=0.1;
                    num=num+dec*(c-'0');
                    CS=S;
                    gc();
                }else if (c=='\n'){
                    return num;
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
        double num;
        num=Parser();
        cout<<fixed<<num<<endl;
    } catch (char c) {
        cerr<<"Error in Lexeme: "<<c<<endl;
    }
}
