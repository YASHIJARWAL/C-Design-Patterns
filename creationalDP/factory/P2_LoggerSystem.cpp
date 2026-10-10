#include<iostream>
#include <memory>
using namespace std;
class Logger{
    protected:
    string msg;
    public:
    virtual void log(string msg)=0;
};
class FileLogger:public Logger{
    public:
    void log(string msg) override{
        this->msg = msg;
        cout<<this->msg<<endl;
    }
};
class ConsoleLogger: public Logger{
    public: 
    void log(string msg) override{
        this->msg = msg;
        cout<<this->msg<<endl;
    }
};
class LoggerCreator{
    public:
    virtual unique_ptr<Logger>logger()=0;
    void execute(string msg){
        auto log = logger();
        log->log(msg);
    }
};
class FileLoggerCreator: public LoggerCreator{
    public:
    unique_ptr<Logger> logger() override{
        return make_unique<FileLogger>();
    }
};
class ConsoleLoggerCreator:public LoggerCreator{
    public:
    unique_ptr<Logger> logger() override{
        return make_unique<ConsoleLogger>();
    }
};
int main(){
    unique_ptr<ConsoleLoggerCreator>console = make_unique<ConsoleLoggerCreator>();
    unique_ptr<FileLoggerCreator>file = make_unique<FileLoggerCreator>();
    file->execute("file executed");
    console->execute("console executed");
}