#include <iostream>
#include <cstdlib>
using namespace std;
class Vec{
public:
    Vec(int Abmessungen,double *vect_ii);
    Vec(int x);
    Vec(const Vec &index);
    void print();
    void set(double numb,int Abmessungen_set);
    double get(int cood);
    double euc_norm();
    double max_norm();
    //Vec & operator+(const Vec op);
    ~Vec(){
        delete [] v;
    }
private:
    int Abmessungen;
    double *v;
};
Vec::Vec(const Vec &index){
    this->Abmessungen=index.Abmessungen;
    this->v=new double [this->Abmessungen];
    for (int i=0; i<this->Abmessungen; i++) {
        v[i]=index.v[i];
    }
}
Vec::Vec(int x){
    this->Abmessungen=x;
    v=new double[x];
    for (int i=0; i<this->Abmessungen; i++) {
        v[i]=0;
    }
}
Vec::Vec(int Abmessungen,double *vect_ii){
    this->Abmessungen=Abmessungen;
    this->v=new double[Abmessungen];
    for (int i=0; i<Abmessungen; i++) {
        this->v[i]=vect_ii[i];
    }
}
void Vec::set(double numb,int Abmessungen_set){
    if (Abmessungen_set>=0&&Abmessungen_set<this->Abmessungen) {
        v[Abmessungen_set]=numb;
    }
}
double Vec::get(int cood){
    if (cood<this->Abmessungen&&cood>=0) {
        return this->v[cood];
    }else{
        return 0;
    }
}
void Vec::print(){
    if (Abmessungen==0) {
        //NULL
    }else{
        cout<<"(";
        for (int i=0; i<Abmessungen; i++) {
            cout<<this->v[i];
            if (i+1<Abmessungen) {
                cout<<",";
            }else{
                cout<<")"<<endl;
            }
        }
    }
}
double Vec::euc_norm(){
    double x=0;
    for (int i=0; i<Abmessungen; i++) {
        x=x+v[i]*v[i];
    }
    return sqrt(x);
}
double Vec::max_norm(){
    if (this->Abmessungen==0) {
        return 0;
    }else{
        double x=0;
        for (int i=0; i<Abmessungen; i++) {
            if (x<(abs(v[i]))) {
                x=abs(v[i]);
            }
        }
        return x;
    }
}
int main(void)
{
    double y1[3] = {1,2,3};
    double y2[5] = {2,1,0,5,7};
    Vec x(3, y1), y(5, y2), z(4);
    Vec u = x;

    y.print();
    x.print();
    z.print();
    u.print();

    x.set(23, 2);  u.set(34, 1);  z.set(-3, 3);
    cout << "x[2] = " << x.get(2) << endl;
    cout << "u[1] = " << u.get(1) << endl;
    cout << "euc_norma y: " << y.euc_norm() << endl;
    cout << "max_norma z: " << z.max_norm() << endl;
    return 0;
}
