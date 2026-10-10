#include<iostream>
using namespace std;
class UDPPackage;
class TCPPackage;
class HTTPPackage;
class Visitor{
    public:
    virtual void visit(HTTPPackage * http)=0;
    virtual void visit(TCPPackage *tdp)=0;
    virtual void visit(UDPPackage *udp)=0;
    virtual ~Visitor()=default;
};
class NetworkPackage{
    public:
    virtual void accept(Visitor *visitor)=0;
    virtual ~NetworkPackage()=default;
};
class UDPPackage: public NetworkPackage{
    public:
    void accept(Visitor *visitor) override{
        visitor->visit(this);
    }
};
class TCPPackage: public NetworkPackage{
    public:
    void accept(Visitor *visitor) override{
        visitor->visit(this);
    }
};
class HTTPPackage: public NetworkPackage{
    public:
    void accept(Visitor *visitor) override{
        visitor->visit(this);
    }
};
class LoggingVisitor: public Visitor{
    public:
    void visit(HTTPPackage *http) override{
        cout<<"logging to http package"<<endl;
    }
    void visit(TCPPackage *tdp) override{
        cout<<"logging to tdp package"<<endl;
    }
    void visit(UDPPackage *udp) override{
        cout<<"logging to udp package"<<endl;
    }
};
class SecurityVisitor: public Visitor{
    public:
    void visit(HTTPPackage *http) override{
        cout<<"security maintainance in http"<<endl;
    }
    void visit(TCPPackage *tdp) override{
        cout<<"security maintainance in tdp"<<endl;
    }
    void visit(UDPPackage *udp) override{
        cout<<"security maintainance in udp"<<endl;
    }
};

int main(){
    HTTPPackage http;
    UDPPackage udp;
    TCPPackage tcp;
    LoggingVisitor logger;
    SecurityVisitor security;
    http.accept(&security);
    http.accept(&logger);
    tcp.accept(&security);
    tcp.accept(&logger);
    udp.accept(&security);
    udp.accept(&logger);

}