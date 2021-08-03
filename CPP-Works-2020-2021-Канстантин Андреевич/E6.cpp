//#include <cstdlib>
//#include <iostream>
//#include <cmath>
//using namespace std;
class Complex{
public:
    Complex(double a=0,double b=0){
        re=a;
        im=b;
    }
    Complex(const Complex &op){
        re=op.re;
        im=op.im;
    }
    double modulo()const{
        return sqrt(re*re+im*im);
    }
    double argument()const{
        return atan2(im,re);
    }
    double get_re() const{
        return re;
    }
    double get_im() const{
        return im;
    }
    void print() const{
        cout<<re<<"+"<<im<<"i"<<endl;
    }
    ~Complex(){
        //NULL
    }
    private:
        double re;
        double im;
};
double pow2(const Complex &a){
    return a.get_re()*a.get_re()+a.get_im()*a.get_im();
}
