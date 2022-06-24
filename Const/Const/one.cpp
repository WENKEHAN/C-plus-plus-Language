#include<iostream>
using namespace std;
int Max(const int& a, const int& b) {
	return a > b ? a : b;
}
int main() {
	int a, b;
	cin >> a >> b;
	cout << Max(a, b) << endl;
	return 0;
}