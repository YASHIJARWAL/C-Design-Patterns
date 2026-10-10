#include<iostream>
#include <memory>
using namespace std;
class Device{
    public:
    virtual void notify()=0;
    virtual ~Device()=default;
};
class Phone: public Device{
    public:
    void notify() override{
        cout<<"notifying on phone"<<endl;
    }
};
class Laptop: public Device{
    void notify() override{
        cout<<"notifying on laptop"<<endl;
    }
};
class Medium{
    protected:
    unique_ptr<Device>device;
    public:
    Medium(unique_ptr<Device>device):device(move(device)){}
    virtual void operation(){
        device->notify();
    }
    virtual ~Medium()=default;
};
class Email: public Medium{
    public:
    Email(unique_ptr<Device>EmailDevice):Medium(move(EmailDevice)){}
    void operation() override{
        cout<<"sending on Email"<<endl;
        device->notify();
    }
};
class SMS: public Medium{
    public:
    SMS(unique_ptr<Device>SMSDevice):Medium(move(SMSDevice)){}
    void operation() override{
        cout<<"sending on sms"<<endl;
        device->notify();
    }
};
int main(){
    unique_ptr<Device>newDevice = make_unique<Phone>();
    unique_ptr<Medium>newMedium = make_unique<Email>(move(newDevice));
    newMedium->operation();
}