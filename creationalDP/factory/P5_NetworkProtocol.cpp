#include<iostream>
#include <memory>
using namespace std;
class Protocol{
    public:
    virtual void protocol()=0;
};
class HTTPProtocol: public Protocol{
    void protocol() override{
        cout<<"HTTP protocol in use"<<endl;
    }
};
class TCPProtocol: public Protocol{
    void protocol() override{
        cout<<"TCP protocol in use"<<endl;
    }
};
class UDPProtocol: public Protocol{
    void protocol() override{
        cout<<"UDP protocol in use"<<endl;
    }
};
class ProtocolCreator{
    public:
    virtual unique_ptr<Protocol>protocolCreator()=0;
    void execute(){
        protocolCreator()->protocol();
    }
};
class HTTPProtocolCreator: public ProtocolCreator{
    unique_ptr<Protocol> protocolCreator() override{
        return make_unique<HTTPProtocol>();
    }
};
class TCPProtocolCreator: public ProtocolCreator{
    unique_ptr<Protocol> protocolCreator() override{
        return make_unique<TCPProtocol>();
    }
};
class UDPProtocolCreator: public ProtocolCreator{
    unique_ptr<Protocol> protocolCreator() override{
        return make_unique<UDPProtocol>();
    }
};
int main(){
    unique_ptr<HTTPProtocolCreator>http = make_unique<HTTPProtocolCreator>();
    unique_ptr<TCPProtocolCreator>tcp = make_unique<TCPProtocolCreator>();
    unique_ptr<UDPProtocolCreator>udp = make_unique<UDPProtocolCreator>();
    http->execute();
    tcp->execute();
    udp ->execute();

}