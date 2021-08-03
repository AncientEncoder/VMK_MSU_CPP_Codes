#include <iostream>
#include <cstring>
#include <cstdlib>
class ctrl_f{
public:
    //@overwrite
    char* left(char *str,int N){
        char *renew;
        renew=nullptr;
        if (N<=0) {
            return renew;
        }
        renew=(char*)malloc(sizeof(char)*N);
        for(int a=0;a<N;a++){
            renew[a]=str[a];
        }
        return renew;
    }
    long left(unsigned long num,int N){
        int lps=1;
        for (int i=1; i<N; i++) {
            lps=lps*10;
        }
        while (num/lps>=10) {
            num=num/10;
        }
        if(N==0){
            return 0;
        }
        return num;
    }
};
int main(int argc,char*argv[]){
    using namespace std;
    ctrl_f Ctrl;
    string str;
    cin>>str;
    if (str.compare("number")==0) {
        unsigned long num;
        int N;
        cin>>num;
        cin>>N;
        if (N<=0) {
            cout<<0;
            return 0;
        }
        long sum=Ctrl.left(num, N);
        cout<<sum<<endl;
    }else if (str.compare("string")==0){
        char* result;
        char inputs[100];
        int index;
        cin>>inputs;
        cin>>index;
        result=Ctrl.left(inputs, index);
        if (result==nullptr) {
            return 0;
        }
        cout<<result<<endl;
        free(result);
    }
    return 0;
}
