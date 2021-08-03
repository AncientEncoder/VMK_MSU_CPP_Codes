#include <list>
#include <iostream>
#include <iterator>
#include <cstdlib>
#include<cstring>
#include <algorithm>
using namespace std;
    bool is_in(list<int> &Container,list<int>::iterator &Iterator,int Object){
        for (Iterator=Container.begin(); Iterator!=Container.end(); Iterator++) {
            if (*Iterator==Object) {
                return true;
            }
        }
        return false;
    }
    int get_max(list<int> &Container,list<int>::iterator &Iterator){
        int maxObject;
        Iterator=Container.begin();
        maxObject=*Iterator;
        for (Iterator=Container.begin(); Iterator!=Container.end(); Iterator++) {
            if (maxObject<*Iterator) {
                maxObject=*Iterator;
            }
        }
        return maxObject;
    }
    void print(const int Object){
        cout<<Object<<" ";
    }
void mf(list<int> &Container,list<int>::iterator &Iterator){
    int maxObj=get_max(Container, Iterator);
    for (Iterator=Container.begin(); Iterator!=Container.end(); Iterator++) {
        if (*Iterator==maxObj) {
            break;
        }
    }
    Container.erase(Iterator);
    Container.push_front(maxObj);
}
void me(list<int> &Container,list<int>::iterator &Iterator){
    int maxObj=get_max(Container, Iterator);
    for (Iterator=Container.begin(); Iterator!=Container.end(); Iterator++) {
        if (*Iterator==maxObj) {
            break;
        }
    }
    Container.erase(Iterator);
    Container.push_back(maxObj);
}
int main(int argc,char*argv[]){
    list<int> listov;
    int aparm=0;
    auto Iterator=listov.begin();
    while (cin>>aparm) {
        listov.push_back(aparm);
    }
    char *transAparm;
    if (argc==2) {
        if (strcmp(argv[1], "-sa")==0) {
            listov.sort();
        }else if (strcmp(argv[1], "-sd")==0){
            listov.sort();
            listov.reverse();
        }else if (strcmp(argv[1], "-mf")==0){
            mf(listov, Iterator);
        }else if (strcmp(argv[1], "-me")==0){
            me(listov, Iterator);
        }
    }else if(argc==3){
        if (strcmp(argv[1], "-ae")==0) {
            listov.push_back(strtol(argv[2], &transAparm, 10));
        }else if (strcmp(argv[1], "-af")==0){
            listov.push_front(strtol(argv[2], &transAparm, 10));
        }else if (strcmp(argv[1], "-d")==0){
            if (is_in(listov, Iterator, strtol(argv[2], &transAparm, 10))) {
                listov.erase(Iterator);
            }
        }
    }else if (argc==4){
        if (strcmp(argv[1], "-ib")==0) {
            if (is_in(listov, Iterator, strtol(argv[3], &transAparm, 10))) {
                listov.insert(Iterator, strtol(argv[2], &transAparm, 10));
            }
        }else if (strcmp(argv[1], "-ia")==0){
            if (is_in(listov, Iterator, strtol(argv[3], &transAparm, 10))) {
                listov.insert(++Iterator, strtol(argv[2], &transAparm, 10));
            }
        }
    }else{
        for_each(listov.begin(), listov.end(), print);
    }
    for_each(listov.begin(), listov.end(), print);
    return 0;
}
