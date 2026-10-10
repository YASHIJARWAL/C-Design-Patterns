#include<iostream>
#include <stdexcept>
#include <string>
using namespace std;
class DatabaseConn{
    int port;
    string name;
    string password;
    string dbName;
    bool sslCert;
    public:
    DatabaseConn(int port, string name, string password , string dbName , bool sslCert){
        this->port = port;
        this->password = password;
        this->name = name;
        this->dbName = dbName;
        this->sslCert = sslCert;

    }
    void show(){
        cout<<"running on port: "<<this->port<<" with name: "<<this->name<<" authenticated with password trying to connnect dbName: "<<this->dbName<<" ssl certification: "<<this->sslCert<<endl;
    }
};
class DatabaseReqBuilder{
    int port;
    string name;
    string password;
    string dbName;
    bool sslCert;
    public:
    DatabaseReqBuilder &buildPort(int port){
        this->port = port;
        return *this;
    }
    DatabaseReqBuilder &buildName(string name){
        this->name = name;
        return *this;
    }
    DatabaseReqBuilder &buildPassword(string password){
        this->password = password;
        return  *this;
    }
    DatabaseReqBuilder &buildDbName(string dbName){
        this->dbName = dbName;
        return *this;
    }
    DatabaseReqBuilder &buildSslCert(bool cert){
        this->sslCert = cert;
        return *this;
    }
    DatabaseConn build(){
        if(password.empty()){
            throw  runtime_error("error , no password provided");
        }
        return DatabaseConn(this->port , this->name , this->password , this->dbName , this->sslCert);
    }
};
int main(){
    DatabaseReqBuilder builder;
    DatabaseConn conn = builder.buildName("Yash").buildPassword("abc123").buildPort(8080).buildSslCert(true).buildDbName("myDB").build();
    conn.show();
}