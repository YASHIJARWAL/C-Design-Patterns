#include<iostream>
using  namespace std;
class LoggerHandler{
    protected:
    LoggerHandler * nextLog;
    public:
    LoggerHandler():nextLog(nullptr){}
    virtual void handlingLog(int priority)=0;
    virtual void setNext(LoggerHandler*nextLog)=0;
    ~LoggerHandler()=default;
};
class InfoLogger : public LoggerHandler{
    public:
    void setNext(LoggerHandler *nextLog) override{
        this->nextLog=nextLog;
    }
    void handlingLog(int priority) override{
        if(priority==1){
            cout<<"this is an info log"<<endl;
        }
        else if(nextLog!=nullptr){
            cout<<"handled by next log"<<endl;
            nextLog->handlingLog(priority);
        }
    }
};
class TraceLogger : public LoggerHandler{
    public:
    void setNext(LoggerHandler *nextLog) override{
        this->nextLog=nextLog;
    }
    void handlingLog(int priority) override{
        if(priority==0){
            cout<<"this is a trace log"<<endl;
        }
        else if(nextLog!=nullptr){
            cout<<"handled by next log"<<endl;
            nextLog->handlingLog(priority);
        }
    }
};
class DebugLogger : public LoggerHandler{
    public:
    void setNext(LoggerHandler *nextLog) override{
        this->nextLog=nextLog;
    }
    void handlingLog(int priority) override{
        if(priority==2){
            cout<<"this is a debug log"<<endl;
        }
        else if(nextLog!=nullptr){
            cout<<"handled by next log"<<endl;
            nextLog->handlingLog(priority);
        }
    }
};
class ErrorLogger : public LoggerHandler{
    public:
    void setNext(LoggerHandler *nextLog) override{
        this->nextLog=nextLog;
    }
    void handlingLog(int priority) override{
        if(priority==4){
            cout<<"this is an error log"<<endl;
        }
        else if(nextLog!=nullptr){
            cout<<"handled by next log"<<endl;
            nextLog->handlingLog(priority);
        }
    }
};
class WarnLogger : public LoggerHandler{
    public:
    void setNext(LoggerHandler *nextLog) override{
        this->nextLog=nextLog;
    }
    void handlingLog(int priority) override{
        if(priority==3){
            cout<<"this is a warning log"<<endl;
        }
        else if(nextLog!=nullptr){
            cout<<"handled by next log"<<endl;
            nextLog->handlingLog(priority);
        }
    }
};
class FatalLogger : public LoggerHandler{
    public:
    void setNext(LoggerHandler *nextLog) override{
        this->nextLog=nextLog;
    }
    void handlingLog(int priority) override{
        if(priority==5){
            cout<<"this is a fatal log"<<endl;
        }
        else if(nextLog==nullptr){
            cout<<"wrong priority set"<<endl;
        }
    }
};
int main(){
    TraceLogger traceLogger;
    InfoLogger infoLogger;
    DebugLogger debugLogger;
    WarnLogger warnLogger;
    ErrorLogger errorLogger;
    FatalLogger fatalLogger;
    traceLogger.setNext(&infoLogger);
    infoLogger.setNext(&debugLogger);
    debugLogger.setNext(&warnLogger);
    warnLogger.setNext(&errorLogger);
    errorLogger.setNext(&fatalLogger);
    traceLogger.handlingLog(0);
    traceLogger.handlingLog(1);
    traceLogger.handlingLog(2);
    traceLogger.handlingLog(3);
    traceLogger.handlingLog(4);
    traceLogger.handlingLog(5);
    traceLogger.handlingLog(6);
}