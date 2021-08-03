#include <iostream>
using namespace std;
class Err{
public:
    Err(const char *ErrInfo,char ErrType,int Index1=0,int Index2=0):ErrInfo(ErrInfo),ErrType(ErrType),Index1(Index1),Index2(Index2){
    }
    void outerr(){
        if (ErrType=='N') {
            cerr<<"Exception: "<<ErrInfo<<" "<<Index1<<" "<<Index2<<endl;
        }else if(ErrType=='U'){
            cerr<<"Exception: "<<ErrInfo<<endl;
        }else if (ErrType=='E'){
            cerr<<"Exception: "<<ErrInfo<<" "<<Index1<<endl;
        }
    }
    ~Err(){}
private:
    const char* ErrInfo;
    char ErrType;
    int Index1,Index2;
};
//----------------------------------a beautiful dividing line----------------------------//
template<typename T>
class Vec{
public:
    Vec<T>(int lange,T* Vectors):lange(lange){
        if (lange<0) {
            throw Err("length error", 'U');
        }else{
            this->Vectors=new T[lange];
            for (int i=0; i<lange; i++) {
                this->Vectors[i]=Vectors[i];
            }
        }
    }
    Vec<T>(int lange):lange(lange){
        if (lange<0) {
            throw Err("length error", 'U');
        }else{
            this->Vectors=new T[lange];
            for (int i=0; i<lange; i++) {
                this->Vectors[i]=0;
            }
        }
    }
    Vec<T>(const Vec<T>& that){
        this->lange=that.lange;
        this->Vectors=new T[lange];
        for(int i=0;i<lange;i++){
            this->Vectors[i]=that.Vectors[i];
        }
    }
    
    T get(int index);
    void set(T targen,int index);
    T max_norm()const;
    Vec<T>& operator += (const Vec<T>& ap);
    Vec<T>& operator = (const Vec<T>& ap);
    T& operator[](int index);
    template<typename V>
    friend const Vec<V> operator +(const Vec<V>& ap1, const Vec<V>& ap2);
    template<typename V>
    friend const Vec<V> operator *(const Vec<V>& ap, double index);
    template<typename V>
    friend const Vec<V> operator *(double index, const Vec<V>& ap);
    template<typename V>
    friend const V operator ^(const Vec<V>& ap1, const Vec<V>& ap2);
    template<typename V>
    friend bool operator ==(const Vec<V>& ap1, const Vec<V>& ap2);
    template<typename V>
    friend ostream& operator << (ostream& sys, const Vec<V>& ap);
    ~Vec<T>(){
        delete [] Vectors;
    }
private:
    T* Vectors;
    int lange;
};

template<typename T>
T Vec<T>::get(int index){
    if (index>=lange||index<0) {
        throw Err("coordinate error in get()", 'U');
    }else{
        return Vectors[index];
    }
}
template<typename T>
void Vec<T>::set(T targen,int index){
    if (index>=lange||index<0) {
        throw Err("coordinate error in set()", 'U');
    }else{
        Vectors[index]=targen;
    }
}
template<typename T>
T Vec<T>::max_norm()const{
    T aparm=abs(Vectors[0]);
    for (int i=0; i<lange; i++) {
        if (abs(Vectors[i])>aparm) {
            aparm=abs(Vectors[i]);
        }
    }
    return aparm;
}
template<typename T>
Vec<T>& Vec<T>::operator += (const Vec<T>& ap){
    if (ap.lange!=lange) {
        throw Err("addition of vectors of different lengths:", 'N',lange,ap.lange);
    }else{
        for (int i=0; i<lange; i++) {
            Vectors[i]=Vectors[i]+ap.Vectors[i];
        }
    }
    return *this;
}

// + *  = ^ == [] <<
template<typename V>
const Vec<V> operator +(const Vec<V>& ap1,const Vec<V>& ap2){
    if (ap1.lange!=ap2.lange) {
        throw Err("addition of vectors of different lengths:", 'N',ap1.lange,ap2.lange);
    }
    Vec<V> ap(ap1.lange);
    for (int i=0; i<ap.lange;i++ ) {
        ap.Vectors[i]=ap1.Vectors[i]+ap2.Vectors[i];
    }
    return ap;
}
template<typename V>
const Vec<V> operator *(const Vec<V>& ap, double index){
    Vec<V> aparm(ap.lange);
    for (int i=0; i<ap.lange;i++ ) {
        aparm.Vectors[i]=ap.Vectors[i]*index;
    }
    return aparm;
}
template<typename V>
const Vec<V> operator *(double index, const Vec<V>& ap){
    Vec<V> aparm(ap.lange);
    for (int i=0; i<ap.lange;i++ ) {
        aparm.Vectors[i]=ap.Vectors[i]*index;
    }
    return aparm;
}
template<typename T>
Vec<T>& Vec<T>::operator=(const Vec<T> &ap){
    if(lange==ap.lange){
        for(int i=0;i<lange;i++){
            Vectors[i]=ap.Vectors[i];
        }
    }else{
        delete [] Vectors;
        lange=ap.lange;
        Vectors=new T[lange];
        for(int i=0;i<lange;i++){
            Vectors[i]=ap.Vectors[i];
        }
    }
    return *this;
}
template<typename V>
const V operator ^(const Vec<V>& ap1, const Vec<V>& ap2){
    V ap=0;
    if(ap1.lange!=ap2.lange){
        throw Err("multiplication of vectors of different lengths:", 'N',ap1.lange,ap2.lange);
    }else{
        for(int i=0;i<ap1.lange;i++){
            ap=ap1.Vectors[i]*ap2.Vectors[i]+ap;
        }
    }
    return ap;
}
template<typename V>
bool operator ==(const Vec<V>& ap1, const Vec<V>& ap2){
    if(ap1.lange!=ap2.lange){
        return false;
    }else{
        for(int i=0;i<ap1.lange;i++){
            if(ap1.Vectors[i]!=ap2.Vectors[i]){
                return false;
            }
        }
    }
    return true;
}
template<typename T>
T& Vec<T>::operator[](int index){
    if(index<0||lange<index){
        throw Err("incorrect indexing:", 'E',index,0);
    }else{
        return Vectors[index];
    }
}
template<typename V>
ostream& operator << (ostream& sys, const Vec<V>& ap){
    sys << "(";
    for (int i = 0; i < ap.lange; i++){
        if(i<ap.lange-1){
            sys<<ap.Vectors[i]<<",";
        }else{
            sys<<ap.Vectors[i]<<")";
        }
    }

    return sys;
}

// +done  *done  =done ^done == []done <<done
void Vector()
{
        int w1[3] = {1,2,3};
        int w2[3] = {2,3,1};
        Vec <int> v1(3, w1), v2(3, w2), v3(0);
        cout << "v1 = " << v1 << endl;
        cout << "v2 = " << v2 << endl;
        v3 = 2*v1 + v2*3;
        cout << "v3 = " <<v3 << endl;
        int pr = v1^v2;
        cout << "v1^v2 = " << pr << endl;
        v1[1] = 7;
        cout << "v[1] = " << v1[1] << endl;
    v1=v2;
    if(v1==v2){
        cout<<"True"<<endl;
    }else{
        cout<<"False"<<endl;
    }
}
int main(int argc,char* argv[]){
    try{
        Vector();
    }catch(Err err){
        err.outerr();
    }catch(...){
        cerr<<"Exception: unknown error"<<endl;
    }
    return 0;
}
