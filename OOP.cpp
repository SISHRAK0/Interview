#include <iostream>

using namespace std;

class A {
public:
    A() {
        cout << "AA" << '\n';
    }

    ~A() {
        cout << "AA die" << '\n';
    }

    virtual void Draw() {
        cout << "draw a" << '\n';
    }
};

class B : public A {
public:
    B() {
        cout << "hello from b" << '\n';
        this->val = -10;
    }

    B(int a) {
        this->val = a;
    }

    int getVal() {
        return this->val;
    }

    virtual ~B() {
        cout << "b die" << '\n';
    }

    void Draw() override {
        cout << "draw b" << '\n';
        cout << this->val << '\n';
    }

private:
    int val;
};


class Person {
private:
    std::string name;
    int age;
public:
    // Конструктор с инициализацией списка членов
    Person(const std::string &name, int age) : name(name), age(age) {
        std::cout << "Создан объект Person: " << name << "\n";
    }
    // Деструктор
    ~Person() {
        std::cout << "Удален объект Person: " << name << "\n";
    }
    // Константный метод доступа
    const std::string& getName() const {
        return name;
    }
    int getAge() const {
        return age;
    }
};

int main(){
    auto a = new A;
    auto b = new B;
    auto b2 = new B(3);
    B b3(10);
    a->Draw();
    b->Draw();
    b->getVal();
    b2->getVal();
    b2->Draw();

    Person alice("Alice", 30);
    std::cout << "Имя: " << alice.getName() << ", Возраст: " << alice.getAge() << "\n";

    delete a;
    delete b;
    delete b2;
}
