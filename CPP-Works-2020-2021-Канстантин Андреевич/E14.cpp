#include<iostream>
#include<cerrno>
#include <cstring>
#include <cstdio>
#include <cstdlib>
using namespace std;
class Exceptions{
public:
    Exceptions(char ID,int index_1,int index_2){
        this->id=ID;//c for index,d for lange
        this->index_1=index_1;
        this->index_2=index_2;
    }
    const int get_index_1(){
        return this->index_1;
    }
    const int get_index2(){
        return this->index_2;
    }
    const char get_id(){
        return this->id;
    }
private:
    char id;
    int index_1;
    int index_2;
};
class Vec{
public:
    Vec(int lange, double* vect){
        this->lange = lange;
        if (lange<0) {
            throw 'a';
        }
        this->vect = new double[lange];
        for (int i = 0;i < lange;i++){
            this->vect[i] = vect[i];
        }
    }
    Vec(double* vect,int lange){
        this->lange = lange;
        this->vect = new double[lange];
        for (int i = 0;i < lange;i++){
            this->vect[i] = vect[i];
        }
    }
    Vec(int lagen){
        this->lange = lagen;
        if (lagen<0) {
            throw 'a';
        }
        this->vect = new double[lange];
        for (int i = 0;i < this->lange;i++)
        this->vect[i] = 0;
    }
    Vec(const Vec& instance){
        lange = instance.lange;
        vect = new double[instance.lange];
        for (int i = 0;i < instance.lange;i++)
        vect[i] = instance.vect[i];
    }
    Vec& operator=(const Vec& instance){
        if(this->lange==instance.lange){
            for (int i = 0;i < instance.lange;i++){
                vect[i] = instance.vect[i];
            }
        }else{
            delete[] vect;
            lange = instance.lange;
            vect = new double[instance.lange];
            for (int i = 0;i < instance.lange;i++){
                vect[i] = instance.vect[i];
            }
        }
        return *this;
    }
    //=================14============
    const int get_lange(){
        return this->lange;
    }
    bool operator ==(const Vec instance){
        if(this->lange!=instance.lange){
            if(this->lange<instance.lange){
                int i=0;
                for(i=0;i<this->lange;i++){
                    if(this->vect[i]!=instance.vect[i]){
                        return false;
                    }
                }
                for(i=i;i<instance.lange;i++){
                    if(instance.vect[i]!=0){
                        return false;
                    }
                }
            }else{
                int i=0;
                for(i=0;i<instance.lange;i++){
                    if(this->vect[i]!=instance.vect[i]){
                        return false;
                    }
                }
                for(i=i;i<this->lange;i++){
                    if(this->vect[i]!=0){
                        return false;
                    }
                }
            }
                }else{
                    for(int i=0;i<this->lange;i++){
                        if((this->vect[i])!=(instance.vect[i])){
                            return false;
                        }
                    }
                }
                return true;
    }
    double & operator[](int i){
        if(i>this->lange||i<0){
            throw Exceptions('d',i,0);
        }
                return vect[i];
    }
    const Vec operator +(const Vec& instance)const{
        if(instance.lange!=this->lange){
            throw Exceptions('c',instance.lange,this->lange);
        }
        Vec n_instance(instance.lange);
        for (int i = 0;i < instance.lange;i++)
        n_instance.vect[i] = instance.vect[i] + vect[i];
        return n_instance;
    }
    friend const Vec operator *(double a, const Vec& op);
    friend const Vec operator *(const Vec& op,double a );
    friend ostream& operator<<(ostream& os, const Vec& op);
    ~Vec(void){
        delete vect;
    }
    void print(){
        if (lange==0) {
            //NULL
        }else{
            cout<<"(";
            for (int i=0; i<lange; i++) {
                cout<<this->vect[i];
                if (i+1<lange) {
                    cout<<",";
                }else{
                    cout<<")"<<endl;
                }
            }
        }
    }
    double euc_norma(){
        double x=0;
        for (int i=0; i<lange; i++) {
            x=x+vect[i]*vect[i];
        }
        return sqrt(x);
    }
    double max_norma(){
        if (this->lange==0) {
            return 0;
        }else{
            double x=0;
            for (int i=0; i<lange; i++) {
                if (x<(abs(vect[i]))) {
                    x=abs(vect[i]);
                }
            }
            return x;
        }
    }
    //get set
    double get(int index){
        if (index>lange||index<0) {
            throw 'b';
        }
        return this->vect[index];
    }
    void set(double numb,int Abmessungen_set){
        if (Abmessungen_set>lange||Abmessungen_set<0) {
            throw 'c';
        }
        this->vect[Abmessungen_set]=numb;
    }
private:
    int lange;
    double* vect;
};
const Vec operator *(double d_instance, const Vec& instance){
    Vec re_instance(instance.lange);
    for (int i = 0;i < instance.lange;i++){
        re_instance.vect[i] = d_instance * instance.vect[i];
    }
    return re_instance;
}
const Vec operator *(const Vec& instance,double d_instance ){
    Vec re_instance(instance.lange);
    for (int i = 0;i < instance.lange;i++){
        re_instance.vect[i] = instance.vect[i] * d_instance;
    }
    return re_instance;
}
ostream& operator<<(ostream& sys, const Vec& instance){
    sys << "(";
    for (int i = 0;i < (instance.lange);i++){
        if (instance.lange-1==i) {
            sys << instance.vect[i];
        }else{
            sys << instance.vect[i]<< ",";
        }
    }
    sys << ")";
    return sys;
}
void error()
{
    double y1[3] = {1,2,3};
    double y2[5] = {2,1,0,5,7};
    Vec x(3,y1);
    Vec y(-5,y2);
    //x+y;
    double a=y[4];
}
int main() {
    try {
        error();
    } catch (char err_index) {
        if (err_index == 'a')
            cerr << "Exception: length error" << endl;
            else if (err_index=='b')
            cerr << "Exception: coordinate error in get()" << endl;
            else if (err_index =='c')
            cerr << "Exception: coordinate error in set()" << endl;
        else if (err_index=='d')
            cerr<<"Exception: addition of vectors of different lengths: "<<endl;
    }catch(Exceptions &ErrID){
        if (ErrID.get_id()=='c') {
            cerr<<"Exception: addition of vectors of different lengths: "<<ErrID.get_index2()<<' '<<ErrID.get_index_1()<<endl;
        }else if (ErrID.get_id()=='d'){
            cerr<<"Exception: incorrect indexing: "<<ErrID.get_index_1()<<endl;
        }
    }catch(...){
        cerr<<"Exception: unknown error"<<endl;
    }
    return 0;
}
