#include<iostream>
#include <memory>
using namespace std;
class Light{
    public:
    virtual void operation()=0;
    virtual ~Light()=default;
};
class RedLight:public Light{
    void operation() override{
        cout<<"red light"<<endl;
    }
};
class YellowLight:public Light{
    void operation() override{
        cout<<"yellow light"<<endl;
    }
};
class GreenLight: public Light{
    void operation() override{
        cout<<"green light"<<endl;
    }
};
class TrafficLight{
    unique_ptr<Light>changeColor;
    public:
    TrafficLight(unique_ptr<Light>color):changeColor(move(color)){}
    void operate(){
        changeColor->operation();
    }
    void colorChange(unique_ptr<Light>light){
        changeColor=move(light);
    }
};
int main(){
    TrafficLight trafficLight(make_unique<GreenLight>());
    trafficLight.operate();
    trafficLight.colorChange(make_unique<YellowLight>());
    trafficLight.operate();
}