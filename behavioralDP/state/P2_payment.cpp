#include <iostream>
#include <memory>
using namespace std;

class Context;

class State {
public:
    virtual void pay(Context& context) = 0;
    virtual void send(Context& context) = 0;
    virtual void retry(Context& context) = 0;
    virtual void refund(Context& context) = 0;

    virtual ~State() = default;
};

class Processing;
class Success;
class Retry;
class Refund;
class Cancel;

class Context {
    unique_ptr<State> state;

public:
    Context(unique_ptr<State> initialState)
        : state(move(initialState)) {}

    void change(unique_ptr<State> newState) {
        state = move(newState);
    }

    void pay() {
        state->pay(*this);
    }

    void send() {
        state->send(*this);
    }

    void retry() {
        state->retry(*this);
    }

    void refund() {
        state->refund(*this);
    }
};


class Refund : public State {
public:
    void pay(Context&) override {
        cout << "Payment already refunded" << endl;
    }

    void send(Context&) override {
        cout << "Payment already refunded" << endl;
    }

    void retry(Context&) override {
        cout << "Cannot retry refunded payment" << endl;
    }

    void refund(Context&) override {
        cout << "Already refunded" << endl;
    }
};
class Pay : public State {
public:
    void pay(Context&) override {
        cout << "Payment initiated" << endl;
    }

    void send(Context& context) override;

    void retry(Context&) override {
        cout << "Payment hasn't failed yet" << endl;
    }

    void refund(Context&) override {
        cout << "Payment hasn't been made yet" << endl;
    }
};
class Success : public State {
public:
    void pay(Context&) override {
        cout << "Payment already completed" << endl;
    }

    void send(Context&) override {
        cout << "Payment already completed" << endl;
    }

    void retry(Context&) override {
        cout << "No retry required" << endl;
    }

    void refund(Context& context) override {
        cout << "Refund initiated" << endl;
        context.change(make_unique<Refund>());
    }
};
class Processing : public State {
public:
    void pay(Context&) override {
        cout << "Payment is already processing" << endl;
    }

    void send(Context& context) override ;

    void retry(Context&) override {
        cout << "Payment is already processing" << endl;
    }

    void refund(Context&) override {
        cout << "Cannot refund while processing" << endl;
    }
};


class Retry : public State {
public:
    void pay(Context&) override {
        cout << "Payment failed. Retry instead." << endl;
    }

    void send(Context& context) override {
        cout << "Retrying payment..." << endl;
        context.change(make_unique<Processing>());
    }

    void retry(Context&) override {
        cout << "Retrying payment..." << endl;
    }

    void refund(Context&) override {
        cout << "Cannot refund failed payment" << endl;
    }
};

void Processing::send(Context &context){
    cout << "Payment processing..." << endl;

        // Example decision
        bool success = true;

        if (success) {
            context.change(make_unique<Success>());
        } else {
            context.change(make_unique<Retry>());
        }
}

void Pay::send(Context& context) {
    cout << "Sending payment for processing..." << endl;
    context.change(make_unique<Processing>());
}
int main() {
    Context payment(make_unique<Pay>());

    payment.pay();
    payment.send();

    return 0;
}