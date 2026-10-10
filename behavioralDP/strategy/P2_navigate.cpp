#include <iostream>
#include <memory>
using namespace std;
class NavigationStrategy{
    public:
    virtual void navigate()=0;
    virtual ~NavigationStrategy()=default;
};
class CarStrategy: public NavigationStrategy{
    public:
    void navigate() override{
        cout<<"navigated using a car"<<endl;

    }
};
class BikeStrategy: public NavigationStrategy{
    public:
    void navigate() override{
        cout<<"navigated using a bike"<<endl;
    }
};
class ScooterStrategy:public NavigationStrategy{
    public:
    void navigate() override{
        cout<<"navigated using a scooter"<<endl;
    }
};
class NavigationProcessor{
    private:
    unique_ptr<NavigationStrategy>navigationStrategy;
    public:
    NavigationProcessor(unique_ptr<NavigationStrategy>strategy):navigationStrategy(move(strategy)){}
    void navDetails(double km){
        navigationStrategy->navigate();
        genDetails(km);
    }
    void genDetails(double km){
        cout<<"navigating distance: "<<km<<endl;
    }
    void setStrategy(unique_ptr<NavigationStrategy>strategy){
        navigationStrategy = move(strategy);
    }
};
int main(){
    NavigationProcessor processor(make_unique<BikeStrategy>());
    processor.navDetails(200);
    processor.setStrategy(make_unique<CarStrategy>());
    processor.navDetails(300);
    processor.setStrategy(make_unique<ScooterStrategy>());
    processor.navDetails(400);
}