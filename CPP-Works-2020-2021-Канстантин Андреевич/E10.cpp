#include<iostream>
#include<cmath>
using namespace std;
class Complex {
public:
    Complex(double i=0., double j=0. ) { x = i;y = j; }
    Complex operator=(const Complex& op){
        x = op.x;
        y = op.y;
        return *this;
    }
    bool operator ==(const Complex op1){
        if ((op1.x == x) && (y == op1.y))
            return true;
        else
            return false;
    }
    const Complex operator +(const Complex& n_instance)const{
        Complex instance;
        instance.x = x + n_instance.x;
        instance.y = y + n_instance.y;
        return instance;
    }
    const Complex operator-(const Complex& h_instance)const{
        Complex instance;
        instance.x = x - h_instance.x;
        instance.y = y - h_instance.y;
        return instance;
    }
    const Complex operator *(const Complex& n_instance)const{
        Complex instance;
        instance.x = x * n_instance.x - y * n_instance.y;
        instance.y = x * n_instance.y + n_instance.x * y;
        return instance;
    }
    friend ostream& operator<<(ostream& sys, const Complex& n_instance);
    friend const Complex operator-(const Complex& instance, double d_instance);
    friend const Complex operator-(double d_instance, const Complex& instance);
    friend const Complex operator *(double d_instance, const Complex& instance);
    friend const Complex operator *(const Complex& instance, double d_instance);
    friend const Complex operator +(const Complex& instance, double d_instance);
    friend const Complex operator +(double d_instance, const Complex& instance);
private:
    double x, y;
};
ostream& operator<<(ostream& sys, const Complex& n_instance){
    if (n_instance.x == 0){
        if (n_instance.y == 0){
            return sys << n_instance.x;
        }else if(n_instance.y==1){
            return sys << "i";
        }else if (n_instance.y==-1){
            return sys << "-i";
        }else{
            return sys<<n_instance.y<<"i";
        }
    }else{
        if (n_instance.y == 0){
            return sys << n_instance.x;
        }else if(n_instance.y==1){
            return sys << n_instance.x << "+i";
        }else if (n_instance.y==-1){
            return sys <<n_instance.x<< "-i";
        }else if(n_instance.y>0){
            return sys<<n_instance.x<<"+"<<n_instance.y<<"i";
        }else{
            return sys<<n_instance.x<<"-"<<abs(n_instance.y)<<"i";
        }
    }
    return sys;
}
const Complex operator *(double d_instance, const Complex& instance){
    return Complex(d_instance * instance.x, d_instance * instance.y);
}

const Complex operator *(const Complex& instance, double d_instance){
    return Complex(d_instance * instance.x, d_instance * instance.y);
}

const Complex operator-(const Complex& instance, double d_instance){
    return Complex(instance.x - d_instance, instance.y);
}

const Complex operator-(double d_instance, const Complex& instance){
    return Complex(d_instance-instance.x, instance.y);
}
const Complex operator +(const Complex& instance, double d_instance){
    return Complex(instance.x + d_instance, instance.y);
}

const Complex operator +(double d_instance, const Complex& instance){
    return Complex(instance.x +d_instance, instance.y);
}

int main()
{
   Complex c(1,-2), g(3), v;
   cout << "c = " << c << endl;
   cout << "g = " << g << endl;
   cout << "v = " << v << endl;
   v = 4.*c*2.;
   cout << "v = " << v << endl;
   g = 3.-g+c-2.*v;
   cout << "g = " << g << endl;
   cout << "2.*g*v = " << 2.*g*v << endl;
   v = g = c;
   if (c == g)
        v = 2.*Complex(0,1);
   else
        v = 2.;
   cout << "c = " << c << " g = " << g << "v = " << v << endl;
   return 0;
}
