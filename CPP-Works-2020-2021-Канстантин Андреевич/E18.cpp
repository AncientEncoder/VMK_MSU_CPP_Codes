#include <iostream>
#include<cstring>
using namespace std;
class event{ //base
public:
    event(const string& name, int jahr,int monat,int tag):name(name),jahr(jahr),monat(monat),tag(tag){
    }
    void change_date(int jahr,int monat,int tag){
        this->jahr=jahr;
        this->monat=monat;
        this->tag=tag;
    }
    virtual void print_res(){
        cout<<name<<" "<<jahr<<" "<<monat<<" "<<tag;
    }
    virtual void change_grade(int g_exam){}
    virtual void change_grade(bool g_test){}
protected:
    int jahr;
    int monat;
    int tag;
    string name;
};

class test:public event{
public:
    test(const string& name,int jahr,int monat,int tag,bool g_test):event(name,jahr, monat,tag),g_test(g_test){
    }
    void change_grade(bool g_test){
        this->g_test=g_test;
    }
    void print_res(){
        event::print_res();
        if (g_test==true) {
            cout<<" true"<<endl;
        }else{
            cout<<" false"<<endl;
        }
    }
private:
    bool g_test;
};

class exam:public event{
public:
    exam(const string& name,int jahr,int monat,int tag,int g_exam):event(name,jahr,monat,tag),g_exam(g_exam){
    }
    void change_grade(int g_exam){
        this->g_exam=g_exam;
    }
    void print_res(){
        event::print_res();
        cout<<" Grade "<<g_exam<<endl;
    }
private:
    int g_exam;
};
//int main()
//{
//        const int NUM =7;
//        event *session[NUM];
//
//        session[0]=new test("MS Office",2020,12,23,true);
//        session[1]=new exam("Operation System",2021,1,15,2);
//        session[2]=new test("Practicum",2020,12,25,false);
//        session[3]=new exam("Differential equation",2021,1,20,3);
//        session[4]=new test("Theory of probability",2020,12,29,true);
//        session[5]=new exam("Philosophy",2021,1,24,5);
//        session[6]=new exam("C++",2021,1,11,4);
//
//        for (int i=0;i<NUM;i++)
//                session[i]->print_res();
//
//        session[2]->change_date(2021,2,24);
//        session[2]->change_grade(true);
//
//        session[1]->change_date(2021,2,13);
//        session[1]->change_grade(3);
//
//        cout<<endl;
//        for (int i=0;i<NUM;i++)
//                session[i]->print_res();
//
//        for (int i=0;i<NUM;i++)
//        delete session[i];
//        return 0;
//}
