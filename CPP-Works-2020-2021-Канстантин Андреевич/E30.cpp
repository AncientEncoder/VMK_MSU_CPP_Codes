#include <iostream>
using namespace std;
template<typename T>
class Set{
public:
    Set<T>(){
        lange=0;
        inhalt=nullptr;
    }
    //no need maybe useful???
    Set<T>(int lange):lange(lange){
        inhalt=new T[lange];
        memset(this->inhalt, 0, sizeof(T)*lange);
    }
    Set<T>(T *aparm,int index){
        lange=0;
        inhalt=nullptr;
        for(int i=0;i<index;i++){
            if(!in(aparm[i])){
                if(lange!=0){
                    renew(lange+1);
                    inhalt[lange-1]=aparm[i];
                }else{
                    inhalt=new T[1];
                    inhalt[0]=aparm[i];
                    lange++;
                }
            }
        }
    }
    bool in(T ap);
    void add(T ap);
    void add(T *aps,int indexs);
    void del(T ap);
    void del(T *ap,int indexs);
    void print();
    void renew(int indexs);
    Set<T> operator +(const Set<T>& ap1);
    Set<T> operator *(const Set<T>& ap1);
    Set<T> &operator = (const Set<T>& ap1);
    ~Set(){
        delete [] inhalt;
    }
private:
    T *inhalt;
    int lange;
};
template<typename T>
void Set<T>::renew(int indexs){
    T *aparm=new T[indexs];
    if (indexs<lange) {
        for (int i=0; i<indexs; i++) {
            aparm[i]=inhalt[i];
        }
        delete [] inhalt;
        inhalt=new T[indexs];
        for (int i=0; i<indexs; i++) {
            inhalt[i]=aparm[i];
        }
        lange=indexs;
        delete [] aparm;
    }else{
        for (int i=0; i<lange; i++) {
            aparm[i]=inhalt[i];
        }
        delete [] inhalt;
        inhalt=new T[indexs];
        for (int i=0; i<lange; i++) {
            inhalt[i]=aparm[i];
        }
        lange=indexs;
        delete [] aparm;
    }
}
template<typename T>
bool Set<T>::in(T ap){
        for (int i=0; i<lange; i++) {
            if (inhalt[i]==ap) {
                return true;
            }
        }
        return false;
}
template<typename T>
void Set<T>::add(T ap){
    if (!in(ap)) {
        if (lange!=0) {
            renew(lange+1);
            inhalt[lange-1]=ap;
        }else{
            inhalt=new T[1];
            inhalt[0]=ap;
            lange++;
        }
    }
}
template<typename T>
void Set<T>::add(T *aps,int indexs){
    for (int i=0; i<indexs; i++) {
        add(aps[i]);
    }
}
template<typename T>
void Set<T>::del(T ap){
    if (in(ap)) {
            int flag_index=0;
            for (flag_index=0; flag_index<lange; flag_index++) {
                if (inhalt[flag_index]==ap) {
                    break;
                }
            }
            for (flag_index=flag_index; flag_index<lange-1; flag_index++) {
                inhalt[flag_index]=inhalt[flag_index+1];
            }
            renew(lange-1);
    }
}
template<typename T>
void Set<T>::del(T *ap, int indexs){
    for (int i=0; i<indexs; i++) {
        del(ap[i]);
    }
}
template<typename T>
void Set<T>::print(){
    T aparm;
    for (int i=0; i<lange; i++) {
        for (int j=0; j<lange; j++) {
            if (inhalt[i]<inhalt[j]) {
                aparm=inhalt[i];
                inhalt[i]=inhalt[j];
                inhalt[j]=aparm;
            }
        }
    }
    for (int i=0; i<lange; i++) {
        if (i<lange-1) {
            cout<<inhalt[i]<<" ";
        }else{
            cout<<inhalt[i];
        }
    }
    cout<<endl;
}
template<typename T>
Set<T> Set<T>::operator *(const Set<T>& ap1){
    Set<T> temp;
    for (int i=0; i<ap1.lange; i++) {
        for(int j=0;j<lange;j++){
            if(ap1.inhalt[i]==inhalt[j]){
                temp.add(ap1.inhalt[i]);
            }
        }
    }
    return temp;
}
template<typename T>
Set<T> Set<T>::operator +(const Set<T>& ap1){
    Set<T> temp;
    temp.lange=ap1.lange;
    temp.inhalt=new T[temp.lange];
    for (int i=0; i<temp.lange; i++) {
        temp.inhalt[i]=ap1.inhalt[i];
    }
    for (int i=0; i<lange; i++) {
        if (!temp.in(inhalt[i])) {
            temp.add(inhalt[i]);
        }
    }
    return temp;
}
template<typename T>
Set<T>& Set<T>::operator = (const Set<T>& ap1)
{
    if (lange != ap1.lange){
        delete[]inhalt;
        inhalt = new T[ap1.lange];
        lange=ap1.lange;
    }
    for (int i = 0;i < lange;i++)
        inhalt[i] = ap1.inhalt[i];
    return *this;
}
//int main()
//{
//        int a[] = { 1,2,3,4,5 };
//        int b[] = { 3,2,6};
//        Set <int> seti1(a,5),seti2,seti3,seti4;
//        seti3.add(1);
//        seti1.print();
//        seti3.print();
//        return 0;
//}
