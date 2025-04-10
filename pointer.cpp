#include <iostream>

using namespace std;

int change(int &val) {
    return val *= 2;
}

int main() {
    int val = 42;
    int *ptr = &val;
    int &pi = val;
    val++;

    std::cout << "Исходное значение var: " << val << "\n";
    std::cout << "Значение через указатель: " << *ptr << "\n";
    cout << ptr << '\n';
    cout << &val << '\n';
    cout << pi << '\n';
    change(val);
    cout << val << '\n';
    cout << pi << '\n';

    int *massivchik = new int[5];
    for (int i = 0; i < 5; i++) {
        massivchik[i] = i * i;
    }
    for(int i = 0; i < 5;i++){
        cout << massivchik[i] << " ";
    }
    delete[] massivchik;

    ptr = nullptr;
    cout << ptr << '\n';

}