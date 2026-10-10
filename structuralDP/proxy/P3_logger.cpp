#include <iostream>
#include <memory>
using namespace std;

class Logger{
    public:
    virtual void operation()=0;
    virtual ~Logger()=default;
};
class RealLogger: public Logger{
    public:
    void operation() override{
        cout<<"operation begins"<<endl;
    }
};
class ProxyLogger: public Logger{
    unique_ptr<Logger>realLogger;
    public:
    ProxyLogger():realLogger(nullptr){}
    void operation() override{
        if(realLogger==nullptr){
            realLogger = make_unique<RealLogger>();
            cout<<"request recieved"<<endl;
        }
        realLogger->operation();
        cout<<"proxy completed"<<endl;
    }
};
int main(){
    unique_ptr<Logger>proxyLogger = make_unique<ProxyLogger>();
    proxyLogger->operation();
    proxyLogger->operation();
}