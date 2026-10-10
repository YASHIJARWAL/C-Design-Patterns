#include<iostream>
using namespace std;

class Rectangle;
class Circle;

class Visitor{
    public:
    virtual void calcArea(Rectangle &rect,int l ,int b)=0;
    virtual void calcArea(Circle &circle,int r)=0;
    virtual ~Visitor()=default;
};

class Shape{
    public:
    virtual void accept(Visitor &vis)=0;
    virtual ~Shape()=default;
};
class AreaVisitor: public Visitor{
    public: 
    void calcArea(Rectangle &rect,int l ,int b) override{
        cout<<"the area is "<< l*b<<endl;
    }
    void calcArea(Circle &circle,int r) override{
        cout<<"the area is "<<3.14*r*r<<endl;
    }
};
class Rectangle:public Shape{
    int l;
    int b;
    public:
    void setLen(int l){
        this->l = l; 
    }
    void setBreadth(int b){
        this->b =b ;
    }
    void accept(Visitor &vis) override{
        vis.calcArea(*this,l,b);
    }
};
class Circle: public Shape{
    int r;
    public:
    void setRadius(int r){
        this->r = r;
    }
    void accept(Visitor &vis) override{
        vis.calcArea(*this,r);
    }
};
int main(){
    Rectangle r;
    Circle c ;
    AreaVisitor av;
    r.setBreadth(7);
    r.setLen(3);
    r.accept(av);
    c.setRadius(14);
    c.accept(av);
}