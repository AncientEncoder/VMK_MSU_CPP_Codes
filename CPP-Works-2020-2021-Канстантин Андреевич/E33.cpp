#include <vector>
#include <algorithm>
#include <iterator>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;

void irb(vector<vector<int>> &mart,int x,int y,int *container,int insert_line){
    if (insert_line>y||insert_line<=0) {
        return;
    }
    mart.push_back({});
    for (int i=0; i<x; i++) {
        mart[y].push_back(0);
    }
    for (int i=y;i>=insert_line ; i--) {
        for (int j=0; j<x; j++) {
            mart[i][j]=mart[i-1][j];
        }
    }
    for (int i=0; i<x; i++) {
        mart[insert_line-1][i]=container[i];
    }
}
void ira(vector<vector<int>> &mart,int x,int y,int *container,int insert_line){
    if (insert_line>y||insert_line<=0) {
        return;
    }
    mart.push_back({});
    for (int i=0; i<x; i++) {
        mart[y].push_back(0);
    }
    for (int i=y;i>insert_line ; i--) {
        for (int j=0; j<x; j++) {
            mart[i][j]=mart[i-1][j];
        }
    }
    for (int i=0; i<x; i++) {
        mart[insert_line][i]=container[i];
    }
}
void icb(vector<vector<int>> &mart,int x,int y,int *container,int insert){
    if (insert>x||insert<0) {
        return;
    }
    for (int i=0;i<y; i++) {
        mart[i].push_back(0);
        for (int j=x; j>=insert; j--) {
            mart[i][j]=mart[i][j-1];
        }
        mart[i][insert-1]=container[i];
    }
}

void ica(vector<vector<int>> &mart,int x,int y,int *container,int insert){
    if (insert>x||insert<0) {
        return;
    }
    for (int i=0;i<y; i++) {
        mart[i].push_back(0);
        for (int j=x; j>insert; j--) {
            mart[i][j]=mart[i][j-1];
        }
        mart[i][insert]=container[i];
    }
}
void dr(vector<vector<int>> &mart,int x,int y,int del){
    if (del>y||del<=0) {
        return;
    }
    for (int i=del-1;i<y-1 ; i++) {
        for (int j=0; j<x; j++) {
            mart[i][j]=mart[i+1][j];
        }
    }
    mart.pop_back();
}
void dc(vector<vector<int>> &mart,int x,int y,int del){
    if (del>x||del<=0) {
        return;
    }
    for (int i=0;i<y; i++) {
        for (int j=del-1; j<x-1; j++) {
            mart[i][j]=mart[i][j+1];
        }
        mart[i].pop_back();
    }
}
void sr(vector<vector<int>> &mart,int x,int y,int change1,int change2){
    change2--;
    change1--;
    if (change1>y||change2>y||change1<0||change2<0||change2==change1) {
        return;
    }
    int aparm[x];
    for (int i=0; i<x; i++) {
        aparm[i]=mart[change1][i];
    }
    for (int i=0; i<x; i++) {
        mart[change1][i]=mart[change2][i];
    }
    for (int i=0; i<x; i++) {
        mart[change2][i]=aparm[i];
    }
}
void sc(vector<vector<int>> &mart,int x,int y,int change1,int change2){
    change2--;
    change1--;
    if (change1>y||change2>y||change1<0||change2<0||change2==change1) {
        return;
    }
    int aparm[y];
    for (int i=0; i<y; i++) {
        aparm[i]=mart[i][change2];
    }
    for (int i=0; i<y; i++) {
        mart[i][change2]=mart[i][change1];
    }
    for (int i=0; i<y; i++) {
        mart[i][change1]=aparm[i];
    }
}
void tr(vector<vector<int>> &mart,int x,int y) {
    vector<vector<int>> tr;
    for (int i=0; i<x; i++) {
        tr.push_back({});
        for (int j=0; j<y; j++) {
            tr[i].push_back(0);
        }
    }
    for (int i=0; i<y; i++) {
        for (int j=0; j<x; j++) {
            tr[j][i]=mart[i][j];
        }
    }
    mart.clear();
    int aparm=y;
    y=x;
    x=aparm;
    for (int i=0; i<y; i++) {
        mart.push_back({});
        for (int j=0; j<x; j++) {
            mart[i].push_back(tr[i][j]);
        }
    }
    tr.clear();
}

void print(vector<vector<int>> mart) {
    for (int i = 0; i < mart.size(); i++) {
        for (int j = 0; j < mart[i].size(); j++)
            cout << mart[i][j] << " ";
        cout << endl;
    }
}
int main(int argc,char* argv[]){
    vector<vector<int>> mart;
    int x;
    int y;
    int aparm;
    char *ptr;
    cin>>y;
    cin>>x;
    for (int i=0;i<y; i++) {
        mart.push_back({});
        for (int j=0; j<x; j++) {
            cin>>aparm;
            mart[i].push_back(aparm);
        }
    }
    if (argc==2) {
        if (strcmp(argv[1], "-t")==0) {
            tr(mart, x, y);
        }
    }else if(argc==3){
        if (strcmp(argv[1], "-irb")==0) {
            int aparms[x];
            for (int i=0; i<x; i++) {
                cin>>aparms[i];
            }
            irb(mart, x, y, aparms,(int)strtol(argv[2], &ptr, 10));
        }else if (strcmp(argv[1], "-ira")==0) {
            int aparms[x];
            for (int i=0; i<x; i++) {
                cin>>aparms[i];
            }
            ira(mart, x, y, aparms,(int)strtol(argv[2], &ptr, 10));
        }else if (strcmp(argv[1], "-icb")==0) {
            int aparms[y];
            for (int i=0; i<y; i++) {
                cin>>aparms[i];
            }
            icb(mart, x, y, aparms,(int)strtol(argv[2], &ptr, 10));
        }else if (strcmp(argv[1], "-ica")==0) {
            int aparms[y];
            for (int i=0; i<y; i++) {
                cin>>aparms[i];
            }
            ica(mart, x, y, aparms,(int)strtol(argv[2], &ptr, 10));
        }else if (strcmp(argv[1], "-dr")==0) {
            dr(mart, x, y, (int)strtol(argv[2], &ptr, 10));
        }else if (strcmp(argv[1], "-dc")==0) {
            dc(mart, x, y, (int)strtol(argv[2], &ptr, 10));
        }
    }else if (argc==4){
        if (strcmp(argv[1], "-sc")==0) {
            sc(mart, x, y, (int)strtol(argv[2], &ptr, 10), (int)strtol(argv[3], &ptr, 10));
        }else if (strcmp(argv[1], "-sr")==0){
            sr(mart, x, y, (int)strtol(argv[2], &ptr, 10), (int)strtol(argv[3], &ptr, 10));
        }else{
            print(mart);
        }
    }
    print(mart);
    return 0;
}
