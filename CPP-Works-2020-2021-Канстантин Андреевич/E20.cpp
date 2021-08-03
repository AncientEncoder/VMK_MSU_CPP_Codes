#include <iostream>
using namespace std;
class Parser{
public:
    int trans_x(char undo_x){
        switch (undo_x) {
            case 'a':
                return 1;
            case 'b':
                return 2;
            case 'c':
                return 3;
            case 'd':
                return 4;
            case 'e':
                return 5;
            case 'f':
                return 6;
            case 'g':
                return 7;
            case 'h':
                return 8;
            default:
                return -1;
                break;
        }
    }
    int trans_y(char undo_y){
        switch (undo_y) {
            case '1':
                return 1;
            case '2':
                return 2;
            case '3':
                return 3;
            case '4':
                return 4;
            case '5':
                return 5;
            case '6':
                return 6;
            case '7':
                return 7;
            case '8':
                return 8;
            default:
                return -1;
                break;
        }
    }
protected:
    int start_i[2];
    int end_i[3];
};
class Figure{
public:
    virtual bool move(char name, int x_s,int y_s,int x_e,int y_e){
        if (x_s<=0||y_s<=0||x_e<=0||y_e<=0) {
            return false;
        }else{
            switch (name) {
                case 'K'://king
                    if ((abs(x_s-x_e)<=1)&&(abs(y_s-y_e)<=1)) {
                        return true;
                    }else{
                        return false;
                    }
                    break;
                case 'Q'://queen
                    if ((x_s==x_e)||(y_s==y_e)||(abs(x_s-x_e)==abs(y_s-y_e))) {
                        return true;
                    }else{
                        return false;
                    }
                    break;
                case 'N':
                    if (((abs(x_s-x_e)==1)&&(abs(y_s-y_e)==2))||((abs(x_s-x_e)==2)&&(abs(y_s-y_e)==1))) {
                        return true;
                    }else{
                        return false;
                    }
                    break;
                case 'B':
                    if (abs(x_s-x_e)==abs(y_s-y_e)) {
                        return true;
                    }else{
                        return false;
                    }
                    break;
                case 'R':
                    if (x_s==x_e||y_s==y_e) {
                        return true;
                    }else{
                        return false;
                    }
                    break;
                default:
                    return false;
                    break;
            }
        }
        return false;
    }
};
class ChessChecker:public Parser,public Figure{
public:
    ChessChecker(){
    }
    void setup(){
        cin >> name>>start>>end;
        start_i[0]=Parser::trans_x(start[0]);
        start_i[1]=Parser::trans_y(start[1]);
        end_i[0]=Parser::trans_x(end[0]);
        end_i[1]=Parser::trans_y(end[1]);
        if(move(name, start_i[0], start_i[1], end_i[0], end_i[1])){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }
    }
private:
    char name;
    char start[2];
    char end[2];
};
int main(int argc,char* argv[]){
    ChessChecker chesschecker;
    chesschecker.setup();
    return 0;
}
