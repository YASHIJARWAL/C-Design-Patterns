#include<iostream>
#include <memory>
using namespace std;
class FileOperation{
    public:
    virtual void operate()=0;
};
class Appender:public FileOperation{
    public:
    void operate() override{
        cout<<"append operation"<<endl;
        append();
    }
    virtual void append()=0;
};
class Logger: public FileOperation{
    public:
    void operate() override{
        cout<<"logging operation"<<endl;
        log();
    }
    virtual void log()=0;
};
class FileLogger: public Logger{
    public:
    void log() override{
        cout<<"logging the file"<<endl;
    }
};
class CloudLogger : public Logger{
    public:
    void log() override{
        cout<<"logging the cloud"<<endl;
    }
};
class ConsoleLogger: public Logger{
    public:
    void log() override{
        cout<<"logging the console"<<endl;
    }
};
class FileAppender: public Appender{
    public:
    void append() override{
        cout<<"appending the file"<<endl;
    }
};
class CloudAppender: public Appender{
    public:
    void append() override{
        cout<<"appending the cloud"<<endl;
    }
};
class ConsoleAppender : public Appender{
    public:
    void append() override{
        cout<<"appending the console"<<endl;
    }
};
class LoggingFactory{
    public:
    virtual unique_ptr<Logger>logger()=0;
    virtual unique_ptr<Appender>appender()=0;
};
class FileLoggingFactory:public LoggingFactory{
    public:
    unique_ptr<Logger> logger() override{
        return make_unique<FileLogger>();
    }
    unique_ptr<Appender> appender() override{
        return make_unique<FileAppender>();
    }
};
class ConsoleLoggingFactory:public LoggingFactory{
    public:
    unique_ptr<Logger> logger() override{
        return make_unique<ConsoleLogger>();
    }
    unique_ptr<Appender> appender() override{
        return make_unique<ConsoleAppender>();
    }
};
class CloudLoggingFactory: public LoggingFactory{
    public:
    unique_ptr<Logger> logger() override{
        return make_unique<CloudLogger>();
    }
    unique_ptr<Appender> appender() override{
        return make_unique<CloudAppender>();
        
    }
};
int main(){
    unique_ptr<CloudLoggingFactory>cloud= make_unique<CloudLoggingFactory>();
    cloud->appender()->operate();
    cloud->logger()->operate();
    
}