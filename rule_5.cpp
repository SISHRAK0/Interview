#include <iostream>
#include <cstring>

using namespace std;

class MyString {
private:
    char *data;
public:
    MyString(const char *str = "") {
        data = new char[strlen(str) + 1];
        strcpy(data, str);
        cout << "Constructor: " << data << '\n';
    }

    MyString(const MyString &other) {
        data = new char[strlen(other.data) + 1];
        strcpy(data, other.data);
        cout << "Copy: " << data << '\n';
    }

    MyString &operator=(const MyString &other) {
        if (this != &other) {
            delete[] data;
            data = new char[strlen(other.data) + 1];
            strcpy(data, other.data);
        }
        cout << "Operator= " << data << '\n';
        return *this;
    }

    MyString(MyString &&other) noexcept: data(other.data) {
        other.data = nullptr;
        cout << "Перемещение конструктора" << '\n';
    }

    MyString &operator=(MyString &&other) noexcept {
        if (this != &other) {
            delete[] data;
            data = other.data;
            other.data = nullptr;
            cout << "Перемещение присваивания" << '\n';
        }
        return *this;
    }

    ~MyString() {
        if (data) {
            cout << "Destructor " << data << '\n';
        } else {
            cout << "Destructor nullptr" << '\n';
        }
        delete[] data;
    }
};

int main() {
    MyString s1("Hello");
    MyString s2 = s1;
    MyString s3 = s2;
    s3 = std::move(s1);
    return 0;
}
