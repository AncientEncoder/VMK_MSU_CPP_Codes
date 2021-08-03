//#include <iostream>
//#include <cstring>
//using namespace std;

const double pi=3.1415926;
class cbase{
public:
    cbase(double x,double y,double z):x(x),y(y),z(z){
    }
    void move(int x,int y,int z){
        this->x=x;
        this->y=y;
        this->z=z;
    }
    virtual void print(){
        cout<<"("<<x<<","<<y<<","<<z<<") ";
    }
protected:
    double x;
    double y;
    double z;
};

class ball:public cbase{
public:
    ball(double x,double y,double z,double r):cbase(x,y,z),r(r){
    }
    void print(){
        cbase::print();
        cout<<"r="<<r<<endl;
    }
    double area(){
        return 4*pi*r*r;
    }
    double volume(){
        return 4/3*pi*r*r*r;
    }
private:
    double r;
};
class cube:public cbase{
public:
    cube(double x,double y,double z,double l):cbase(x,y,z),l(l){
    }
    void print(){
        cbase::print();
        cout<<"l="<<l<<endl;
    }
    double area(){
        return l*l*6;
    }
    double volume(){
        return l*l*l;
    }
private:
    double l;
};
class cylinder:public cbase{
public:
    cylinder(double x,double y,double z,double r,double h):cbase(x,y,z),r(r),h(h){
    }
    void print(){
        cbase::print();
        cout<<"r="<<r<<" h="<<h<<endl;
    }
    double area(){
        return r*r*pi*2+pi*2*r*h;
    }
    double volume(){
        return r*r*pi*h;
    }
private:
    double h;
    double r;
};
//int main()
//{
//        ball ba(1,2,3,3);
//        cube cu(2,1,3,2);
//        cylinder cy(3,1,2,3,4);
//        ba.print();
//        cout << "area ball = " << ba.area() << endl;
//        cout << "volume ball = " << ba.volume() << endl;
//        cu.print();
//        cout << "area cube = " << cu.area() << endl;
//        cout << "volume cube = " << cu.volume() << endl;
//        cy.print();
//        cout << "area cylinder = " << cy.area() << endl;
//        cout << "volume cylinder = " << cy.volume() << endl;
//        ba.move(0,0,0);
//        ba.print();
//        cu.move(-2,-5,-7);
//        cu.print();
//        cy.move(5,-9,1);
//        cy.print();
//
//        return 0;
//}
