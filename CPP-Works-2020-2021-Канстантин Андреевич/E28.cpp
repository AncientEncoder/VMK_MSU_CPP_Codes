//#include <iostream>
//#include<cstring>
//using namespace std;

template<typename T>
T maxn (T p[], int index){
    T max;
    max=p[0];
    for (int i=0; i<index; i++) {
        if (p[i]>max) {
            max=p[i];
        }
    }
    return max;
}
const char* maxn(const char* p[],int x){
    const char* max=p[0];
    for (int i=0; i<x; i++) {
        if (strlen(p[i])>strlen(max)) {
            max=p[i];
        }
    }
    return max;
}
//int main()
//{
//    int arri[6] = {1, 2, 5, 3, 1, -1};
//    double arrd[4] = {2.3, -1.3, 8.7, 4.5};
//    const char * arrc[5] = { "second", "third", "long string", "first","ano"};
//
//    cout << "max of integer = " << maxn(arri, 6) << endl;
//    cout << "max of double = " << maxn(arrd, 4) << endl;
//    cout << "max string is " << maxn(arrc, 5) << endl;
//
//    return 0;
//}
