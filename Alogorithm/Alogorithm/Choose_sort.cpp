#include<iostream>
#include<list>
using namespace std;
void Quick_sort(int *arr,int n) {

}
//基数排序
void Radix_sort(int* arr, int n) {

}
//int main() {
//	list<int>my_list;
//
//}

//简单选择排序
void Choose_sort(int *arr, int n) {
	for (int i = 0; i < n-1; i++) {
		int min =i;
		for (int j = i; j < n; j++) {
			if (arr[j] < arr[min]) {
				min = j;
			}
		}
		if (i != min) {
			int temp = arr[i];
			arr[i] = arr[min];
			arr[min] = temp;
		}
	}
}
#if 0
//int main() {
//	int n;
//	cin >> n;
//	int arr[100];
//	for (int i = 0; i < n; i++) {
//		int x;
//		cin >> x;
//		arr[i] = x;
//	}
//	Choose_sort(arr, n);
//	for (int i = 0; i < n; i++) {
//		cout << arr[i] << " ";
//	}
//	system("pause");
//
//	return 0;
//}
#endif
