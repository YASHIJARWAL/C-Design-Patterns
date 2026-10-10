#include <iostream>
#include <memory>
#include <vector>
#include <algorithm>
using namespace std;

class Component {
public:
    virtual void Print(int userPin) = 0;
    virtual ~Component() = default;
};

class File : public Component {
    string name;
    int requiredPin;

public:
    File(string name, int requiredPin) {
        this->name = name;
        this->requiredPin = requiredPin;
    }

    void Print(int userPin) override {
        if (userPin == requiredPin) {
            cout << "added a file: " << name << endl;
        }
        else {
            cout << "permission denied for file: " << name << endl;
        }
    }
};

class Directory : public Component {
    string name;
    int requiredPin;
    vector<shared_ptr<Component>> children;

public:
    Directory(string name, int requiredPin) {
        this->name = name;
        this->requiredPin = requiredPin;
    }

    void add(shared_ptr<Component> component) {
        children.push_back(component);
    }

    void deleteEl(shared_ptr<Component> component) {
        children.erase(
            remove(children.begin(), children.end(), component),
            children.end()
        );
    }

    void Print(int userPin) override {
        if (userPin == requiredPin) {
            cout << "added a directory: " << name << endl;

            for (auto &child : children) {
                child->Print(userPin);
            }

            cout << "directory terminates" << endl;
        }
        else {
            cout << "permission denied for directory: " << name << endl;
        }
    }
};

int main() {

    auto directory = make_shared<Directory>("directory 1", 100);

    auto file1 = make_shared<File>("file 1", 200);
    auto file2 = make_shared<File>("file 2", 100);

    auto directory2 = make_shared<Directory>("directory 2", 100);

    auto file3 = make_shared<File>("file 3", 100);

    directory2->add(file3);
    directory2->add(file2);

    directory->add(file1);
    directory->add(directory2);

    directory->Print(100);

    return 0;
}