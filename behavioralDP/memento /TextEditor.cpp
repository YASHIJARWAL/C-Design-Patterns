#include<iostream>
#include <string>
#include <vector>
using namespace std;

//|----------------------|
//|       Memento        |
//|----------------------|

class EditorMemento{
    private:
    string text;
    int cursorPos;
    public:
    EditorMemento(string text , int cursorPos):text(text),cursorPos(cursorPos){}
    string getText()const{
        return text;
    }
    int getCursorPos()const{
        return cursorPos;
    }
};

//|----------------------|
//|      Originator      |
//|----------------------|

class TextEditor{
    private:
    string text;
    int cursorPos;
    public: 
    TextEditor(): text(""),cursorPos(0){}
    void write(const string &newText){
        text+=newText;
        cursorPos+=newText.length();
    }
    EditorMemento save(){
        return EditorMemento(text,cursorPos);
    }
    void Restore(const EditorMemento& memento){
        text = memento.getText();
        cursorPos = memento.getCursorPos();
    }
    void show() const{
        cout<<"text: "<<text<<"\t";
        cout<<"cursorPos: "<<cursorPos<<"\t";
    }
};

//|----------------------|
//|      caretaker       |
//|----------------------|

class History{
    private:
    vector<EditorMemento> history;
    public:
    void save(const EditorMemento &memento){
        history.push_back(memento);
    }
    EditorMemento undo(){
        EditorMemento previousState = history.back();
        history.pop_back();
        return previousState;
    }
};

//|----------------------|
//|        Client        |
//|----------------------|

int main(){
    TextEditor editor; 
    History history;
    editor.write("hello");
    history.save(editor.save());
    editor.write("world");
    cout<<"before undo:"<<endl;
    editor.show();
    cout<<"\n";
    cout<<"after undo:"<<endl;
    EditorMemento previousState = history.undo();
    editor.Restore(previousState);
    editor.show();

}