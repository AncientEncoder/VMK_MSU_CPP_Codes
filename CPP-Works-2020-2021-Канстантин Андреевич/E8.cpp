#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;

class mstring {
public:
    mstring();
    mstring(const mstring &instance);
    mstring(const char *instance);

    int length() {
        return (int)strlen(inhalt);
    }

    bool empty() {
        if (inhalt[0] == inhalt[strlen(inhalt)])
            return true;
        else
            return false;
    }

    void add(char instance);
    void add(const char *instance);
    void insert(char instance, int index);
    void insert(const char *instance, int index);
    void del(int index);
    void del(int starten, int enden);
    void print();

    ~mstring() {
        delete[]inhalt;
    }
private:
    char *inhalt;
};

mstring::mstring() {
    inhalt = new char[1];
    inhalt[0]='\0';
}

mstring::mstring(const mstring &instance) {
    this->inhalt = new char[strlen(instance.inhalt)];
    strcpy(this->inhalt, instance.inhalt);
}

mstring::mstring(const char *str) {
    this->inhalt = new char[strlen(str)];
    strcpy(this->inhalt, str);
}

void mstring::add(char instance) {
    int lange = (int)strlen(inhalt);
   inhalt=(char*)realloc(inhalt,lange+1);
    inhalt[lange]=instance;
}

void mstring::add(const char *instance) {
    int l1 = (int)strlen(inhalt);
    int l2 = (int)strlen(instance);
    char *tmp = new char[l1 + l2 + 1];
    strcpy(tmp, inhalt);
    strcpy(tmp + l1, instance);
    inhalt = new char[strlen(tmp) + 1];
    strcpy(inhalt, tmp);
}

void mstring::insert(char instalnce, int index) {
    int lange = (int)strlen(inhalt);
    char *re_instance = new char[lange + 1];
    int re_index;
    for (re_index = 0; re_index < index; re_index++) {
        re_instance[re_index] = inhalt[re_index];
    }
    re_instance[re_index] = instalnce;
    for (re_index=index+1; re_index < lange + 1; re_index++) {
        re_instance[re_index] = inhalt[re_index-1];
    }
    strcpy(inhalt, re_instance);
}

void mstring::insert(const char *instance, int index) {
//    int re_lange=(int)strlen(instnace);
//    int lange=(int)strlen(inhalt);
//    char *re_inhalt=new char[lange+re_lange+1];
//    int lg_index;
//    for (lg_index=0; lg_index<index; lg_index++) {
//        re_inhalt[lg_index]=inhalt[lg_index];
//    }
//    for (lg_index=index; lg_index<index+re_lange; lg_index++) {
//        re_inhalt[lg_index]=instnace[lg_index-index];
//    }
//    for (lg_index=index+re_lange; lg_index<lange+re_lange; lg_index++) {
//        re_inhalt[lg_index]=inhalt[lg_index-re_lange];
//    }
//    inhalt=(char*)realloc(inhalt,lange+re_lange+1);
//    strcpy(inhalt, re_inhalt);
    int re_lange=(int)strlen(instance);
    int lange=(int)strlen(inhalt);
    inhalt=(char*)realloc(inhalt,lange+re_lange+1);
    char *re_inhalt=new char[lange=index];
    strcpy(re_inhalt,(inhalt+index));
    strcpy((inhalt+index), instance);
    strcat(inhalt, re_inhalt);
}

void mstring::del(int index) {
    int lange = (int)strlen(inhalt);
    if (lange==index) {
        inhalt[index-1]='\0';
    }
    for (int i=index; i<lange; i++) {
        inhalt[i]=inhalt[i+1];
    }
}

void mstring::del(int starten, int enden) {
    int lange = (int)strlen(inhalt);
    char *NueStr = new char[lange - enden];
    strcpy(NueStr, (inhalt+enden+1));
    strcpy((inhalt+starten), NueStr);
}

void mstring::print() {
    cout << inhalt << endl;
}
int main()
{
        mstring s ("hello world");
        mstring s1 = s;
        mstring s2;
        cout <<s.length() << endl;
        if (s2.empty())
        {
          s.add('!');
          s2.add("HI!");
          s.print();
          s2.print();
        }
        if (!s1.empty())
        {
           s1.insert(' ',5);
           s1.insert('m',6);
           s1.insert('y',7);
           s.insert(" my",5);
           s.print();
           s1.print();
        }
        s.del(9);
        s1.del(5,7);
        s.print();
        s1.print();
        return 0;
}
