#include<cmath>
#include <iostream>
using namespace std;
#include<cmath>
class Vector_3d{
public:
    Vector_3d(double a=0., double b=0., double c=0.){
        x=a;
        y=b;
        z=c;
    }
    void set(double a, double b, double c){
        x=a;
        y=b;
        z=c;
    }
    double max_norm(){
        if ((sqrt(x*x)>=sqrt(y*y))&&(sqrt(x*x)>=sqrt(z*z))) {
            return sqrt(x*x);
        }else if ((sqrt(y*y)>=sqrt(x*x))&&(sqrt(y*y)>=sqrt(z*z))) {
            return sqrt(y*y);
        }else{
            return sqrt(z*z);
        }
    }
    double get_x(){
        return x;
    }
    double get_y() {
        return y;
    }
    double get_z(){
        return z;
    }
    void print(){
        cout<<"("<<x<<","<<y<<","<<z<<")"<<endl;
    }
    double euc_norm(){
        return sqrt(x*x+y*y+z*z);
    }
private:
    double x;
    double y;
    double z;
};

//--------------------------------------------

int main(int argc,char*argv[]){
    Vector_3d v(1.5, 2.4, 3.);
         Vector_3d w, u = 2.;
         v.print();
         w.print();
         u.print();
         cout << "norma euc v = " << v.euc_norm() << endl;
         w.set(1,2,3);
         cout << "norma max w = " << w.max_norm() << endl;
         cout << " u_x = " << u.get_x() << endl;
         cout << " w_y = " << w.get_y() << endl;
         cout << " v_z = " << v.get_z() << endl;
    return 0;
}
