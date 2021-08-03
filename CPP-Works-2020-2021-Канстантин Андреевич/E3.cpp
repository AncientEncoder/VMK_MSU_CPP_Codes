class Complex{
public:
    Complex(double a=0,double b=0){
        re=a;
        im=b;
    }
    double modulo(){
        return sqrt(re*re+im*im);
    }
    double argument(){
        return atan2(im,re);
    }
    double get_re(){
        return re;
    }
    double get_im(){
        return im;
    }
private:
    double re;
    double im;
};
