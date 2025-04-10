#include <iostream>

using namespace std;

// prepare OOP
class A {
public:
    A() {
        cout << "A create" << '\n';
    }

   virtual ~A() {
        cout << "Destruct A" << '\n';
    }

    virtual void Draw() {
        cout << "Draw from A" << '\n';
    }
};

class B : A {
public:
    B() {
        cout << "B create" << '\n';
    }

    virtual ~B() {
        cout << "Destruct B" << '\n';
    }

    void Draw() override {
        cout << "Draw from B" << '\n';
    }
};


void print(int a){
    cout << a << '\n';
}
void print(double a){
    cout << a << '\n';
}

int main() {
    cout << "OK" << '\n';
    A a;
    B b;
    a.Draw();
    b.Draw();
//    delete b;
//    delete a;
    print(3);
    print(3.14);
}