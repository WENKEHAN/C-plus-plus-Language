#include<iostream>
#include<vector>
#include<queue>
/*
1.����С��
  ���㵺�������---��һ����ά����������һ�ŵ�ͼ�������ŵ�ͼ�����ַ�'1'���ַ�'0'������'0'����ˮ��
  '1'����С��������,С����ˮ����Χ�ţ���С������'1'��ˮƽ�ʹ�ֱ��������ʱ��������Ϊ��ͬһ�����أ�
  ���������ͼ���м���С����
���磺
11100
11000
00100
00011
�������������ͼ��˵����3��С��
���磺
11110
11010
11100
00000
���ڴ˷���ͼ��˵����1��С��*/
using namespace std;
class Islands {
public:
	void Push(string& s, int &k,vector<char>&temp,vector<vector<char> >&res) {
		int i = 0;
		while(i<s.length()){
			for (int j = 0; j < k; j++) {
				temp.push_back(s[i++]);
			}
			res.push_back(temp);
			temp.clear();
		}
	}
	void DFS(vector<vector<char> > &island,int r,int c) {
		int nr = island.size();
		int nc = island[0].size();
		island[r][c] = '0';
		if (r - 1 >= 0 && island[r - 1][c]=='1')
			DFS(island, r - 1, c);
		if (r + 1 < nr && island[r + 1][c]=='1')
			DFS(island, r + 1, c);
		if (c - 1 >= 0 && island[r][c - 1]=='1')
			DFS(island, r, c - 1);
		if (c + 1 < nc && island[r][c + 1]=='1')
			DFS(island, r, c + 1);
	}
	void BFS(vector<vector<char> >& island, int r, int c) {
		int nr = island.size();
		int nc = island[0].size();
		queue<pair<int, int>>q;
		q.push({ r,c });
		//����������Ԫ����Ϊ0
		island[r][c] = '0';
		while (!q.empty()) {
			auto front = q.front();
			q.pop();
			int l = front.first, r = front.second;
			if (l - 1 >= 0 && island[l - 1][r] == '1') {
				q.push({ l - 1, r });
				island[l - 1][r] = '0';
			}	
			if (l + 1 < nr && island[l + 1][r] == '1')
			{
				q.push({ l + 1, r });
				island[l + 1][r] = '0';
			}
			if (r - 1 >= 0 && island[l][r - 1] == '1') {
				q.push({ l,r - 1 });
				island[l][r - 1] = '0';
			}
			if (r + 1 < nc && island[l][r + 1] == '1') {
				q.push({ l,r + 1 });
				island[l][r + 1] = '0';
			}		
		}

	}
	int countislands(vector<vector<char> >& island) {
		int res = 0;
		int nr = island.size();
		if (!nr) return 0;
		int nc = island[0].size();
		for (int i = 0; i < nr; i++) {
			for (int j = 0; j < nc; j++) {
				if (island[i][j]=='1') {
					res++;
					BFS(island, i, j);
				}
			}
		}
		return res;
	}
};
int main(){
	vector<char>temp;
	vector<vector<char> >res;
	Islands lands;
	string s;
	cin >> s;
	int k = 5;
	lands.Push(s, k, temp, res);
	int cont = 0;
	cont=lands.countislands(res);
	cout << "���������Ϊ:	" << cont << endl;
	return 0;
}