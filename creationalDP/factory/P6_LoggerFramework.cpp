#include<iostream>
#include <memory>
using namespace std;
class Product{
    public:
    virtual void operate()=0;
};
class Logger:public Product{
    public:
    virtual void log(){
        cout<<"logging"<<endl;
    }
    void operate() override{
        log();
    }
};
class Formatter:public Product{
    virtual void format(){
        cout<<"formatting"<<endl;
    }
    void operate() override{
        format();
    }
};
class Appender:public Product{
    virtual void append(){
        cout<<"appending"<<endl;
    }
    void operate() override{
        append();
    }
};
class Factory{
    public:
    virtual unique_ptr<Product> makeProduct()=0;
};
class FileLoggerFactory:public Factory{
    public:
    unique_ptr<Logger> makeLogger(){
        return make_unique<Logger>();
    }
    unique_ptr<Product> makeProduct() override{
        return makeLogger();
    }
};
class FileAppenderFactory:public Factory{
    public:
    unique_ptr<Appender>makeAppender(){
        return make_unique<Appender>();
    }
    unique_ptr<Product> makeProduct() override{
        return makeAppender();
    }
};
class FileFormatterFactory: public Factory{
    unique_ptr<Formatter>makeFormatter(){
        return make_unique<Formatter>();
    }
    unique_ptr<Product> makeProduct() override{
        return makeFormatter();
    }
};