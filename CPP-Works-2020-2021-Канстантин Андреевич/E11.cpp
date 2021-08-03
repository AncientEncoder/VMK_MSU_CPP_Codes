#include<iostream>
using namespace std;
class Vec{
public:
    Vec(int lange, double* vect){
        this->lange = lange;
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
                return vect[i];
    }
    const Vec operator +(const Vec& instance)const{
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

int main()
{
    double y[] = {1,2,3,4};
    Vec u(4,y);
    cout<<u[3]<<endl;
    u = u;
//    if (x==y) {
//        cout<<"true";
//    }else{
//        cout<<"false";
//    }
//    cout<<x<<y;
    //cout<<u;
    return 0;
}
