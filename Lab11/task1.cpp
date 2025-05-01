#include <iostream>
#include <any>
#include <stdexcept>
#include <string>

using namespace std;

class BadTypeException : public exception {
public:
    const char* what() const noexcept override {
        return "BadTypeException: Type mismatch during retrieval.";
    }
};

class TypeSafeContainer {
private:
    any data;

public:
    template <typename T>
    void store(const T& value) {
        data = value;
    }

    template <typename T>
    T get() const {
        if (!data.has_value()) {
            throw BadTypeException();
        }

        try {
            return any_cast<T>(data);
        } catch (const bad_any_cast&) {
            throw BadTypeException();
        }
    }
    void clear() {
        data.reset();
    }
    bool isEmpty() const {
        return !data.has_value();
    }
};

int main() {
    TypeSafeContainer container;
    container.store<string>("Hello, world!");
    try {
        string s = container.get<string>(); //shuld work
        cout << "Retrieved: " << s << endl;
        int n = container.get<int>(); //throws BadTypeException
        cout << "Number: " << n << endl;
    } catch (const BadTypeException& e) {
        cerr << e.what() << endl;
    }
    return 0;
}
