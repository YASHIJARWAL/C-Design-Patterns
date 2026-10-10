#include<iostream>
#include <memory>
using namespace std;
class Image{
    public:
    virtual void snapshot()=0;
    virtual ~Image()=default;
};
class RealImage: public Image{
    public:
    void snapshot() override{
        cout<<"this is the real image"<<endl;
    }
};
class ProxyImage:public Image{
    unique_ptr<Image>proxyImage;
    public:
    void snapshot() override{
        if(proxyImage == nullptr){
            proxyImage = make_unique<RealImage>();
        }
        proxyImage->snapshot();
        cout<<"the proxy has been checked"<<endl;
    }
};
int main(){
    unique_ptr<Image>newImage = make_unique<ProxyImage>();
    newImage->snapshot();
}