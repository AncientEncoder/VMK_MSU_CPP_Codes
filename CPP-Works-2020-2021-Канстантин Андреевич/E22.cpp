#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdio>
#include <cerrno>
using namespace std;
class Exception{
    string comment;
public:
    Exception(const char* arg_com):comment(arg_com){
    }
    Exception(const Exception& other) {
    comment = other.comment;
    }
    ~Exception() {}
    string GetComment() const {
    return comment;
    }
};

class FileException : public Exception{
    char * filename;
    char * strdup(const char* str);
public:
    FileException(const char* arg_file, const char* arg_comm) :  Exception(arg_comm){
        filename = strdup(arg_file);
    }
    FileException(const FileException& other) : Exception(other){
        filename = strdup(other.filename);
    }
    char* GetFilename() const {
    return filename;
    }
    ~FileException() {
    delete [] filename;
    }
};

char* FileException::strdup(const char*str){
    char *res = new char[strlen(str)+1];
    strcpy(res,str);
    return res;
}

class FileErrCodeException : public FileException{
    int err_code;
public:
    FileErrCodeException(const char*fn, const char*com) : FileException(fn, com){
        err_code= errno;
    }
    FileErrCodeException(const FileErrCodeException& other) : FileException(other){
    err_code = other.err_code;
    }
    int GetErrCode() const {
    return err_code;
    }
};


int count_symbols(char*filename){
    
    int count = 0;
    ifstream fin(filename);
    if (!fin.is_open())
        throw FileErrCodeException(filename, "can't open file");
    while (fin.get()!= EOF)
            count++;
    if (count==0)
        throw FileException(filename, "is empty");
    fin.close();
    return count;
}


int main(int argc, char**argv){
    try{
        if (argc<2)
            throw Exception("no filename");
    int n;
    n = count_symbols(argv[1]);
    cout<<"File "<<argv[1]<<" contains "<<n<<" symbols "<<endl;
    }
    catch(FileErrCodeException &ex)
    {
        cerr<<"Exception: "<<ex.GetComment()<<" " <<ex.GetFilename();
        cerr<< " Error code: "<<strerror(ex.GetErrCode())<<endl;
        return 1;
    }
    catch (FileException &ex)
    {
        cerr<<"Exception: "<<ex.GetFilename()<<" "<<ex.GetComment()<<endl;
        return 2;
    }
    catch (Exception &ex)
    {
        cerr<<"Exception: "<<ex.GetComment()<<endl;
        return 3;
    }
    return 0;
}
