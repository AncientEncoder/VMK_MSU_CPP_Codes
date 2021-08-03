class Triangle{
public:
    Triangle(double arg_a, double arg_b, double arg_c){
        a = arg_a; b = arg_b;
        c = arg_c;
    }
    double area() {
        double p = (a+b+c) * 0.5;
        return sqrt(p*(p-a)*(p-b)*(p-c));
    }
private:
    double a, b, c;
};

class Prisma: Triangle{
public:
    Prisma(double a, double b, double c, double arg_h):
    Triangle(a,b,c), H(arg_h) {
    }
    double volume() {return area()*H;}
private:
    double H;
};
