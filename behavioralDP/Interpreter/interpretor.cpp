#include<iostream>
#include <memory>
using namespace std;
class Context{
    public:
    string input;
    Context(string input):input(input){}
};
class Expression{
    public:
    virtual void interpret()=0;
    virtual ~Expression()=default;
};
class TerminalExpression:public Expression{
    public:
    void interpret() override{
        cout<<"expression is being interpretted ..."<<endl;
    }
};
class NonTerminalExpression:public Expression{
    unique_ptr<Expression>expression;
    public: 
    NonTerminalExpression(unique_ptr<Expression>newExpression):expression(move(newExpression)){}
    void interpret() override{
        cout<<"non terminal expression is being interpretted ..."<<endl;
        expression->interpret();
    }

};
int main(){
    Context context("input");
    unique_ptr<Expression>expression = make_unique<NonTerminalExpression>(make_unique<TerminalExpression>());
    expression->interpret();
}