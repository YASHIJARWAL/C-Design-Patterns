#include<iostream>
#include <memory>
using namespace std;
class Logger{
    public:
    virtual void log()=0;
    virtual ~Logger()=default;
};
class FileLogger:public Logger{
    public:
    void log() override{
        cout<<"logging to the file"<<endl;
    }
};
class ConsoleLogger: public Logger{
    void log() override{
        cout<<"logging to the console"<<endl;
    }
};
class LogManager{
    protected:
    unique_ptr<Logger>loggerMethod;
    public:
    LogManager(unique_ptr<Logger>logger):loggerMethod(move(logger)){}
    virtual void operation(){
        loggerMethod->log();
    }
};
class AuditLogger: public LogManager{
    public: 
    AuditLogger(unique_ptr<Logger>logger):LogManager(move(logger)){}
    void operation() override{
        cout<<"this is audit logger"<<endl;
        loggerMethod->log();
    }
};
class ApplicationLogger: public LogManager{
    public:
    ApplicationLogger(unique_ptr<Logger>logger):LogManager(move(logger)){}
    void operation() override{
        cout<<"this is an application logger"<<endl;
        loggerMethod->log();
    }
};
int main(){
    unique_ptr<Logger>logger = make_unique<FileLogger>();
    unique_ptr<LogManager>manager = make_unique<ApplicationLogger>(move(logger));
    manager->operation();
}