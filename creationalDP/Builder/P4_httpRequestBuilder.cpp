#include<iostream>
#include <stdexcept>
#include <string>
#include <unordered_map>
using namespace std;
class HTTPRequest{
    string method;
    string url;
    unordered_map<string,string> headers;
    string body;
    int timeout=30;
    public: 
    HTTPRequest(string method , string url , unordered_map<string,string>headers,string body,int timeout){
        this->method = method;
        this->body = body;
        this->url = url;
        this->headers = headers;
        this->timeout = timeout;
    }
    void show(){
        cout<<this ->url<<"\t"<<this->method<<"\t"<<this->body<<"\t"<<this->timeout<<"\t";
        for(auto& h:this->headers){
            cout<<h.first<<"\t"<<h.second<<endl;
        }
    }
};
class Builder{
    string method;
    string body;
    string url;
    int timeout;
    unordered_map<string, string> header;
    public:
    Builder& buildMethod(string method){
        this->method =method;
        return *this;
    }
    Builder& buildURL(string url){
        this->url=url;
        return *this;
    }
    Builder& buildHeaders(string key , string value){
        header[key]=value;
        return *this;
    }
    Builder& buildTimeout(int timeout){
        this->timeout=timeout;
        return *this;
    }
    Builder &buildBody(string body){
        this->body = body;
        return *this;
    }
    HTTPRequest build(){
        if(url.empty()){
            throw runtime_error("error detected , no url");
        }
        return HTTPRequest(method,url,header,body,timeout);
    }
};

int main(){
    HTTPRequest request = Builder().buildURL("url built").build();
    request.show();
}