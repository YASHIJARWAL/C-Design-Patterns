#include<iostream>
using namespace std;

class Circle;
class Rectangle;


class Visitor{
    public:
    virtual void visit(Circle &circle)=0;
    virtual void visit(Rectangle &rectangle)=0;
    virtual ~Visitor()=default;
};


class Shape{
    public:
    virtual void accept(Visitor &visitor)=0;
    virtual ~Shape()=default;
};


class Circle: public Shape{
    public:
    void accept(Visitor &visitor) override{
        visitor.visit(*this);
    }
};
class Rectangle:public Shape{
    public:
    void accept(Visitor &visitor) override{
        visitor.visit(*this);
    }
};

class AreaVisitor: public Visitor{
    public:
    void visit(Circle &circle) override{
        cout<<"visited circle"<<endl;
    }  
    void visit(Rectangle &rectangle) override{
        cout<<"visited rectangle"<<endl;
    }
};
class PerimeterVisitor: public Visitor{
    void visit(Circle &circle) override{
        cout<<"radius of circle:"<<3.14*2*7<<" for radius 7"<<endl;
    }
    void visit(Rectangle &rectangle) override{
        cout<<"perimeter of rect: "<< 2*(5+4)<<"for length 5 and breadth 4"<<endl;
    }
};
int main(){
    AreaVisitor vis;
    PerimeterVisitor vis2;
    Circle circle;
    Rectangle rectangle;
    circle.accept(vis);
    rectangle.accept(vis);
    circle.accept(vis2);
    rectangle.accept(vis2);
}
