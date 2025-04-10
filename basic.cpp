#include <iostream>

using namespace std;

int p(){
    return 1 + 2;
}
int main(){

    bool fl = true;
    if(fl){
        cout << p() << '\n';
    }
    cout << fl << '\n';
}