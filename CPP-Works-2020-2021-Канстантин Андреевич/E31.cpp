#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
using namespace std;

void Show(const int ptr){
    cout<< ptr<<" ";
}

bool Compare (int r1, int r2){
    if (abs(r1) < abs(r2))
        return true;
    else
        return false;
}

int main(){
    const int NUM = 5;
    std::vector<int>vi(NUM);
    for (int i =0; i< NUM; i++)
        vi[i] = 3 - 2*i;
    for (int i = 0; i< NUM; i++)
        cout<< vi[i]<<" ";
    cout<<endl;
    
    vector<int>::iterator pd;
    pd = vi.begin();
    *pd = 7;
    pd++;
    *pd=4;
    
    for(pd = vi.begin(); pd!= vi.end(); pd++)
        cout<<*pd<<" ";
    cout<<endl;
    
    list<int> li = {11,12,13,14,15,16};
    list<int>::iterator pl;
    
    for(pl = li.begin(); pl!= li.end(); pl++)
        cout<< *pl<< " ";
    cout<<endl;
    
    list<int>::const_iterator cpl;
   // cpl = li.begin();
   // *cpl = 7; // error
   cout << "list "<<li.size()<<" vector "<<vi.size()<<endl;
    li.push_back(9);
    vi.push_back(7);
    li.push_front(5);
   // vi.push_front(8);//error
    vi.erase(vi.begin(), vi.begin()+2);
    pl = li.begin(); pl++; pl++;
    li.erase(li.begin(),pl);
    
    for (cpl = li.begin(); cpl != li.end(); cpl++)
        cout<<*cpl<<" ";
    cout<<endl;
    
    for(vector<int>::const_iterator cpd = vi.begin(); cpd != vi.end(); cpd++)
        cout<<*cpd<<" ";
    cout<<endl;
    
    for_each(vi.begin(), vi.end(), Show); cout<<endl;
    for_each(li.begin(), li.end(), Show); cout<<endl;
    for_each(vi.rbegin(), vi.rend(), Show); cout<<endl;
    
    sort(vi.begin(), vi.end());
    for_each(vi.begin(), vi.end(), Show); cout<<endl;
    sort(vi.begin(),vi.end(), Compare);
    for_each(vi.begin(), vi.end(), Show); cout<<endl;
    return 0;
}
