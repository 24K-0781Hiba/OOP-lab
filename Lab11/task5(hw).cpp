#include <iostream>
#include <vector>
#include <stdexcept>
using namespace std;

class StackUnderflowException : public exception {
public:
    const char* what() const noexcept override {
        return "StackUnderflowException: Stack is empty.";
    }
};

template <typename T>
class Stack {
private:
    vector<T> elements;
public:
    void push(const T& value) {
        elements.push_back(value);
    }
    void pop() {
        if (elements.empty()) {
            throw StackUnderflowException();
        }
        elements.pop_back();
    }

    T top() const {
        if (elements.empty()) {
            throw StackUnderflowException();
        }
        return elements.back();
    }

    bool isEmpty() const {
        return elements.empty();
    }

    size_t size() const {
        return elements.size();
    }
};

int main() {
    Stack<int> s;
    try {
        s.push(10);
        s.push(780);
        s.push(30);

        cout << "Top: " << s.top() << endl;//should print 10
        s.pop();

        cout << "Top after pop: " << s.top() << endl;//should priny 780
        s.pop();
        s.pop();

        //this will throw exception (stack is now empty)
        s.pop();
    } catch (const StackUnderflowException& e) {
        cerr << e.what() << endl;
    }
    return 0;
}
