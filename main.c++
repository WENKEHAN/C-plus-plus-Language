#include<iostream>
using namespace std;
int MAX(int& a, int& b) {
    return a > b ? a : b;
}
int main(){
    int a, b;
    cin >> a >> b;
    cout << MAX(&a, &b) << endl;
    return 0;
}