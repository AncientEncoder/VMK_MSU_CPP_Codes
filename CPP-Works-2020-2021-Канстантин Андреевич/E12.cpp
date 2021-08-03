#include <iostream>
#include <fstream>
#include <cstring>
#include<cerrno>
#include<cstdio>
using namespace std;
class FileException{
    char *filename;
    string comment;
    int err_code;
    char *strdup(const char *str);
public:
    FileException(const char *arv_file,const char *arg_comm);
    FileException(const FileException &other);
    ~FileException();
    char *GetFilename(){
        return filename;
    }
    string GetComment(){
        return comment;
    }
    int getErrCode(){
        return err_code;
    }
};
FileException::FileException(const char *arg_file,const  char* arg_comm){
    filename=strdup(arg_file);
    comment=arg_comm;
    err_code=errno;
}
FileException::FileException(const FileException& other){
    filename=strdup(other.filename);
    comment=other.comment;
    err_code=other.err_code;
}
FileException::~FileException(){
    delete[] filename;
}
char* FileException::strdup(const char *str){
    char *res=new char[strlen(str)+1];
    strcpy(res, str);
    return res;
}
int count_symbls(char *filename){
    int count=0;
    ifstream fin(filename);
    if (!fin.is_open()) {
        throw FileException(filename,"can't open file");//
    }
    while (fin.get()!=EOF) {
        count++;
    }
    fin.close();
    return count;
}
int main(int argc,char* argv[]){
    if (argc<2) {
        cerr<<"no file"<<endl;
    }
    int n;try{
        n=count_symbls(argv[1]);
        cout<<"File "<<argv[1]<<" contains "<<n<<" symbols "<<endl;
    }catch(FileException &ex){ //copy from func c_s
        cerr<<"Exception: "<<ex.GetComment()<<" "<<ex.GetFilename();
        cerr<<" Error code: "<<strerror(ex.getErrCode())<<endl;
        return 1;
    }
    ofstream fout("data.txt");
    if (!fout.is_open()) {
        cerr<<"cant't open file data.txt"<<endl;
        return 2;
    }else{
        fout<<"File "<<argv[1]<<" contains "<<n<<" symbles "<<endl;
        fout.close();
    }
    return 0;
}
