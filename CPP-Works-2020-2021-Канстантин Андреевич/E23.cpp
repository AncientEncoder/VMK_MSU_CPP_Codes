#include <iostream>
#include <cstring>
using namespace std;
class Vect_base{
public:
    Vect_base(int x=0):x(x){
    }
protected:
    int x;
};//err base
class Vec_2d final:public Vect_base{
public:
    Vec_2d(int x=0,int y=0):Vect_base(x),y(y){
    }
    friend istream& operator >> (istream& cin, Vec_2d &os );
    friend ostream& operator << (ostream& cout,const Vec_2d os);
private:
    int y;
};
istream& operator >> (istream& input,Vec_2d &os){
    input>>os.x;
    if (cin.get()=='\n') {
        cerr << "Exception: one coordinate" << endl;
        throw Vect_base();
    }
    input>>os.y;
    if (os.x<0||os.y<0) {
        if (os.x<0) {
            cerr << "Exception: negative coordinate:" << os.x << endl;
        }else{
            cerr << "Exception: negative coordinate:" << os.y<< endl;
        }
        throw Vect_base();
    }
    return input;
}
ostream& operator << (ostream& print,const Vec_2d os){
    print<<"("<<os.x<<","<<os.y<<")"<<endl;
    return print;
}
int main(int argc,char* argv[]){
    try {
        Vec_2d vec;
        cin>>vec;
        cout<<vec;
    } catch (Vect_base) {
    }catch(...){
        cerr<<"unknow error"<<endl;
    }
    return 0;
}
