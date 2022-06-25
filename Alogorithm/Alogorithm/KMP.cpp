#include"ALgorith.h"
template<class T >
int KMP_search(const T& s1, const T& s2, const int& pos) {
	int a = int new[s2.length()]{ 0 };
	a[0] = -1, a[1] = 0;
	int j = 1;
	int k = next[j];
	while (j + 1 < s2.length()) {
		if (s2[j] == sub[k]||k==-1) {
			a[++j] = ++k;
		}else {
			k = a[k];
		}
	}
	unsigned int i = pos, j = 0;
	while (i < s1.length() && j < s2.length()) {
		if (s1[i] == s2[j]||j==-1)
		{
			i++;
			j++;
		}
		else {
			j = a[j];
		}
	}
	if (j == s2.length()) {
		return i - j;
	}
	return -1;

}
//×Ö·û´®Æ¥Åä
template<class T >
int Bf_search(const T  &s1, const T &s2,const int &pos) {
	 unsigned int i =pos , j = 0;
	while (i < s1.length() && j < s2.length()) {
		if (s1[i]==s2[j])
		{
			i++;
			j++;
		}
		else {
			i = i - j + 1;
			j = 0;
		}
	}
	if (j == s2.length()) {
		return i - j;
	}
	return -1;
}

int main() {
	string a = "abacabcdef";
	string b = "def";
	//cout << Bf_search(a, b,5) << endl << endl;
	KMP_search(a, b,0);
	return 0;
	
}