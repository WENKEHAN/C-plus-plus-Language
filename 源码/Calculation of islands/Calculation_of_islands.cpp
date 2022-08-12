#include<iostream>
#include<vector>
#include<queue>
/*
1.计算小岛
  计算岛屿的数量---用一个二维数组来代表一张地图，在这张地图上有字符'1'和字符'0'，其中'0'代表水，
  '1'代表小岛的土地,小岛被水所包围着，当小岛土地'1'在水平和垂直方向相连时，可以认为是同一块土地，
  计算这个地图上有几座小岛。
例如：
11100
11000
00100
00011
对于上面这幅地图来说，有3个小岛
又如：
11110
11010
11100
00000
对于此幅地图来说，有1个小岛*/
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
		//将遍历过的元素置为0
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
	cout << "岛屿的数量为:	" << cont << endl;
	return 0;
}