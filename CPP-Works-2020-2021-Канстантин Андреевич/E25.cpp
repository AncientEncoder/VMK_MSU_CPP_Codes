#include <iostream>
#include <cstring>
using namespace std;
class Err{
public:
    Err(char errType,const char* errInfo,const char* Team,int id=0):errType(errType),errInfo(errInfo),Team(Team),id(id){
    }
    const char* errInfo;
    const char* Team;
    int id;
    char errType;
};
class Player{
public:
    Player(const char* group,int tag):group(group){
        if (tag<=0) {
            throw Err('b',"Wrong number",group,tag);
        }else{
            if (strcmp(group, "CSKA")==0||strcmp(group, "Zenit")==0) {
                if (strcmp(group, "CSKA")==0) {
                    if (cska[0]>=11) {
                        throw Err('a',"Too many players","CSKA",-1);
                    }
                    for (int i=1; i<12; i++) {
                        if (cska[i]==tag) {
                            throw Err('b',"Double number","CSKA",tag);
                        }
                    }
                    for (int i=1; i<12; i++) {
                        if (cska[i]==0) {
                            cska[i]=tag;
                            break;
                        }
                    }
                    cska[0]++;
                    id=tag;
                }
                if (strcmp(group, "Zenit")==0) {
                    if (zenit[0]>=11) {
                        throw Err('a',"Too many players","Zenit",-1);
                    }
                    for (int i=1; i<12; i++) {
                        if (zenit[i]==tag) {
                            throw Err('b',"Double number","Zenit",tag);
                        }
                    }
                    for (int i=1; i<12; i++) {
                        if (zenit[i]==0) {
                            zenit[i]=tag;
                            break;
                        }
                    }
                    zenit[0]++;
                    id=tag;
                }
            }else{
                throw Err('a',"Wrong name",group,-1);
            }
        }
    }
    void Print(){
        if (strcmp(group, "CSKA")==0) {
            cout<<group<<" "<<id<<endl;
        }else{
            cout<<group<<" "<<id<<endl;
        }
    }
    static void Print_teams(){
        if (zenit[0]!=0) {
            cout<<"Zenit:";
            for (int i=1;i<12;i++) {
                if (zenit[i]!=0) {
                    cout<<" "<<zenit[i];
                }
            }
            cout<<endl;
        }
        if (cska[0]!=0) {
            cout<<"CSKA:";
            for (int i=1; i<12; i++) {
                if (cska[i]!=0) {
                    cout<<" "<<cska[i];
                }
            }
            cout<<endl;
        }
    }
    ~Player(){
        if (strcmp(group, "CSKA")==0) {
            cska[0]--;
            for (int i=1; i<12; i++) {
                if (id==cska[i]) {
                    cska[i]=0;
                    break;
                }
            }
        }else{
            zenit[0]--;
            for (int i=1; i<12; i++) {
                if (id==zenit[i]) {
                    zenit[i]=0;
                    break;
                }
            }
        }
    }
private:
    const char* group;
    int id;
    static int cska[12];//0 for all players
    static int zenit[12];
};
int Player::cska[12]={0};
int Player::zenit[12]={0};
//void Players()
//{
//    Player pl1("CSKA", 199);
//    Player pl2("CSKA", 12);
//    Player pl13("CSKA", 13);
//    Player pl31("CSKA", 14);
//    Player pl41("CSKA", 1);
//    Player pl51("CSKA", 17);
//    Player pl61("CSKA", 16);
//    Player pl121("Zenit", 130);
//    Player pl71("CSKA", 18);
//    Player pl81("CSKA", 19);
//    Player pl881("CSKA", 22);
//    Player pl771("CSKA", 23);
//
//
//        Player::Print_teams();
//}
int main(int argc,char*argv[]){
    try {
        Players();
    } catch (Err err) {
        if (err.errType=='a') {
            cerr<<"Exception: "<<err.errInfo<<" in team "<<err.Team<<endl;
        }else{
            cerr<<"Exception: "<< err.errInfo<<" in team "<<err.Team <<" Error number: "<<err.id<< endl;
        }
    }
}
