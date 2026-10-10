#include<iostream>
using namespace std;
class House{
    string roof;
    string flooring;
    int windows;
    int doors;
    int washroom;
    int bedroom;
    public: 
    void getRoof(string roof){
        this->roof = roof;
    }
    void getflooring(string flooring){
        this->flooring = flooring;
    }
    void getWindows(int windows){
        this->windows = windows;
    }
    void getDoors(int doors){
        this->doors = doors;
    }
    void getWashroom(int washroom){
        this->washroom = washroom;
    }
    void getBedroom(int bedroom){
        this->bedroom = bedroom;
    }
    void show(){
        cout<<"bedroom: "<<this->bedroom<<"\t washroom: "<<this->washroom<<"\t doors: "<<this->doors<<"\twindows: "<<this->windows<<"\t flooring: "<<this->flooring;
        cout<<"\t roof: "<<this->roof<<endl;
    }
};
class Builder{
    public: 
    virtual void buildRoof()=0;
    virtual void buildWashroom()=0;
    virtual void buildBedroom()=0;
    virtual void buildWindows()=0;
    virtual void buildDoors()=0;
    virtual void buildFloor()=0;
    virtual House* getHouse()=0;
};
class HouseBuilder: public Builder{
    House * house;
    public:
    HouseBuilder(){
        this->house = new House();
    }
    void buildRoof() override{
        house->getRoof("wooden");
    }
    void buildWashroom() override{
        house->getWashroom(3);
    }
    void buildDoors() override{
        house->getDoors(8);
    }
    void buildBedroom() override{
        house->getBedroom(3);
        
    }
    void buildFloor() override{
        house->getflooring("marble");

    }
    void buildWindows() override{
        house->getWindows(6);
        
    }
    House* getHouse() override{
        return house;
    }
};
class Director{
    public:
    void construct(Builder *builder){
        builder->buildRoof();
        builder->buildFloor();
        builder->buildBedroom();
        builder->buildWashroom();
        builder->buildWindows();
        builder->buildDoors();
    }
};
int main(){
    HouseBuilder builder;
    Director director;
    director.construct(&builder);
    House *house;
    house = builder.getHouse();
    house->show();
}