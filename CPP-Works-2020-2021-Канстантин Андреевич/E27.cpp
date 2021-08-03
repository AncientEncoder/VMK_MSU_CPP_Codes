//#include <iostream>
//using namespace std;
template<class T>
class Vector_2d{
    T x,y;
    enum{
         NUM=0
    };
public:

    Vector_2d(T x=NUM,T y=NUM):x(x),y(y){
    }
    void print() const;
    T max_norm()const{
        return abs(x)>abs(y)?abs(x):abs(y);
    }
    const Vector_2d<T>& operator=(const Vector_2d<T>& op);
    const Vector_2d<T> operator*(T a){
        return Vector_2d<T>(a*x,a*y);
    }
    template<typename V>
    friend const Vector_2d<V>operator+(const Vector_2d<V>& op1,const Vector_2d<V>& op2);
};
template<typename V>
const Vector_2d<V>operator+(const Vector_2d<V>& op1,const Vector_2d<V>& op2){
    Vector_2d<V> temp;
    temp.x=op1.x+op2.x;
    temp.y=op1.y+op2.y;
    return temp;
}
template<typename T>
const Vector_2d<T>& Vector_2d<T>::operator=(const Vector_2d<T>& op){
    x=op.x;
    y=op.y;
    return *this;
}
template<typename T>
void Vector_2d<T>::print() const{
    cout<<"("<<x<<","<<y<<")"<<endl;
}
//int main(){
//    Vector_2d<int> v(2,3);
//    v.print();
//    Vector_2d<double> wd(3.14,2.7);
//    wd.print();
//}
