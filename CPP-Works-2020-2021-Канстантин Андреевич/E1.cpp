#include <iostream>
using namespace std;
void func(const char *str){
    cout<<str<<endl;
}
void func(const char *str,int round){
    for(int i=0;i<round;i++){
        cout<<str<<endl;
    }
}
void func(float index){
    cout<<index*2<<endl;
}
void func(float dl1,int dl2){
    cout<<dl1*dl2<<endl;
}
void func(int *p,int index){
    int sum=0;
    for(int i=0;i<index;i++){
        sum=sum+p[i];
    }
    cout<<sum<<endl;
}
void func(double *p,int index){
    double prov=1;
    for(int i=0;i<index;i++){
        prov=prov*p[i];
        //cout<<p[i]<<endl;
    }
    cout<<prov<<endl;
}

int main()
{
     double array[7] = {1.2,2.3,3.5,4,5,6,7};
    int array1[7] = {1,2,3,4,5,6,7};
                func("mather");
                func("abcd", 3);
                func(3.14);
                func(2.71828, 4);
                func(array1, 7);
                func(array, 7);
     return 0;
}
