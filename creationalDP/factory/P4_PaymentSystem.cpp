#include<iostream>
#include <memory>
using namespace std;
class Payment{
    public: 
    virtual void pay()=0;
};
class UPIPayment:public Payment{
    void pay() override{
        cout<<"paying amount using UPI payment"<<endl;
    }
};
class CashPayment: public Payment{
    void pay()override{
        cout<<"paying amount using cash payment"<<endl;
    }
};
class PaymentCreator{
    public:
    virtual unique_ptr<Payment>paymentCreator()=0;
    void execute(){
        auto payment= paymentCreator();
        payment->pay();
    }
};
class UPIPaymentCreator: public PaymentCreator{
    public: 
    unique_ptr<Payment> paymentCreator() override{
        return make_unique<UPIPayment>();
    }
};
class CashPaymentCreator:public PaymentCreator{
    public:
    unique_ptr<Payment> paymentCreator() override{
        return make_unique<CashPayment>();
    }
};
int main(){
    unique_ptr<PaymentCreator>cashCreator= make_unique<CashPaymentCreator>();
    unique_ptr<PaymentCreator>upiCreator2 = make_unique<UPIPaymentCreator>();
    unique_ptr<PaymentCreator>upiCreator = make_unique<UPIPaymentCreator>();
    cashCreator->execute();
    upiCreator->execute();
    upiCreator2->execute();
}