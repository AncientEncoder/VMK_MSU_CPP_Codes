#include <iostream>
#include <cstdlib>
using namespace std;


int nod(int x,int y){
    return y==0?x:nod(y,x%y);
}
class Quotient{
public:
    Quotient(int u=0,int d=1){
        x=u;
        y=d;
    }
    void print(){
        if ((x==0)) {
            cout<<"0"<<endl;
        }else if (y==1){
            cout<<x<<endl;
        }else{
            int m,n,p;
            m=x;n=y;p=m%n;
            while(p!=0){
            m=n;n=p;
            p=m%n;
            }
            if(n!=0){
            x/=n;
            y/=n;
            }
            cout<<x<<"/"<<y<<endl;
        }
    }
    
private:
    int x;
    int y;
};
int main()
{
       Quotient q1(1,1), q2(6,12), q3(7), q4;
       q1.print();
       q2.print();
       q3.print();
       q4.print();
       return 0;
}

