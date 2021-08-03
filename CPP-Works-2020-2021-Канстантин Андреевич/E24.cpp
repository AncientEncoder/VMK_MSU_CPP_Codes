#include <iostream>
#include<cstring>
using namespace std;
class Flower{
public:
    Flower(const char *nameFlower,int Blutenblatt):nameFlower(nameFlower),Blutenblatt(Blutenblatt){
        if (strcmp(nameFlower, "white")==0) {
            White++;
        }else if(strcmp(nameFlower, "pink")==0){
            Pink++;
        }else{
            rule();
        }
    }
    Flower(int Blutenblatt):Blutenblatt(Blutenblatt){
        rule();
    }
    Flower(const char *nameFlower):nameFlower(nameFlower){
        Blutenblatt=10;
        if (strcmp(nameFlower, "white")==0) {
            White++;
        }else if(strcmp(nameFlower, "pink")==0){
            Pink++;
        }else{
            rule();
        }
    }
    Flower(){
        Blutenblatt=10;
        rule();
    }
    void rule(){
        if (White < Pink){
                nameFlower = "white";
                White++;
            }else if (White >Pink){
                        nameFlower = "pink";
                        Pink++;
                    }else if (Blutenblatt% 2 == 0){
                        nameFlower = "pink";
                        Pink++;
                    }
                    else if (Blutenblatt % 2 != 0){
                        nameFlower = "white";
                        White++;
                    }
    }
    static void  Print_flowers(){{
            cout << "White: " << White << " Pink: " << Pink << endl;
        }
    }
    ~Flower(){
        if (strcmp(nameFlower, "pink")==0) {
            Pink--;
        }else{
            White--;
        }
    }
private:
    const char* nameFlower;
    int Blutenblatt;
    static int Pink;
    static int White;
};
int Flower::White=0;
int Flower::Pink=0;
int main()
{
       Flower fl1("white", 3);
       Flower fl2("pink", 5);
       Flower fl3("white", 7);
       Flower::Print_flowers();
       Flower fl4("green");
       Flower::Print_flowers();
       Flower fl5("blue", 17);
       Flower::Print_flowers();
       Flower fl6;
       Flower::Print_flowers();
       Flower fl7;
       Flower::Print_flowers();
    cout<<"all";
       return 0;
}
