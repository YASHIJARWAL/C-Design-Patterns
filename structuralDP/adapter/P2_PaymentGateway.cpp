#include<iostream>
#include <memory>
using namespace std;
class Target{
    public:
    virtual void pay()=0;
    virtual~Target()=default;
};
class ThirdPartyPayment{
    public:
    void payUsingThirdParty(){
        cout<<"this payment is being done using third party"<<endl;
    }
};
class Payment: public Target{
    unique_ptr<ThirdPartyPayment>ThirdParty;
    public:
    Payment(unique_ptr<ThirdPartyPayment>Target):ThirdParty(move(Target)){}
    void pay() override{
        ThirdParty->payUsingThirdParty();
    }
};
class Client{
    public:
    void execute(Target &target){
        target.pay();
    }
};
int main(){
    auto thirdParty= make_unique<ThirdPartyPayment>();
    Payment Payadapter(move(thirdParty));
    Client client;
    client.execute(Payadapter);
}