#if 0
#include<iostream>
#include<vector>
using namespace std;
#define SIZE 10
class Graph {
public:
	Graph() {
		MaxVertex = SIZE;
		NumVertex = NumEdge = 0;
		Vertex = new char[MaxVertex];
		for (int i = 0; i < MaxVertex; i++) {
			for (int j = 0; j < MaxVertex; j++) {
				Edge[i][j] = 0;
			}
		}
	}
	~Graph() {
		if (Vertex != nullptr) {
			delete[]Vertex;
			Vertex = nullptr;
		}
	}
	void InsertVertex(char v) {
		if (NumVertex >= MaxVertex) {
			return;
		}
		Vertex[NumVertex++] = v;
	}
	int GetVertex(char v) {
		int i ;
		for (i = 0; i < NumVertex; i++) {
			if (v==Vertex[i])
			{
				return i;
			}
		}
		return -1;
	}
	void InsertEdge(char v1, char v2) {
		int p1 = GetVertex(v1);
		int p2 = GetVertex(v2);
		if (p1 == -1 || p2 == -1) {
			return;
		}
		Edge[p1][p2] = 1;
		Edge[p2][p1] = 1;
		NumEdge++;
	}
	void PrintGraph() {
		cout << "  ";
		for (int i = 0; i < NumVertex; i++) {
			cout << Vertex[i] << " ";
		}
		cout << endl;
		for (int i = 0; i < NumVertex; ++i) {
			cout << Vertex[i] << " ";
			for (int j = 0; j < NumVertex; j++) {
				cout << Edge[i][j]<<" ";
			}
			cout << endl;
		}
	}
	void DeleteEdge(char v1, char v2) {
		int p1 =GetVertex(v1);
		int p2 = GetVertex(v2);
		if (p1 == -1 || p2 == -1) return;
		Edge[p1][p2] = 0;
		Edge[p2][p1] = 0;
		NumEdge --;
	}
	void DeleteVertex(char v) {
		/*1.计算当前相关顶点的边数
		2.Vertex,Edge两个数组都得变化
		3.依次移动二维数组的行和列||用最后一个行覆盖第一行，用最后一列覆盖当前列
		*/
		int p1 = GetVertex(v);
		if (p1 == -1) {
			return;
		}
		int DelEdge = 0;
		for (int i = 0; i < NumVertex; i++) {
			if (Edge[p1][i] == 1) {
				DelEdge++;
			}
		}
		
		////将顶点数组中要删除的顶点后面的向前移动
		//for (int i = p1; i <NumVertex-1; i++) {
		//	Vertex[i] = Vertex[i + 1];
		//}
		////将当前顶点所在之后的行和列依次向后移动
		//for (int i = p1; i < NumVertex; i++) {
		//	for (int j = 0; j < NumVertex-1; j++) {
		//		Edge[i][j] = Edge[i][j + 1];
		//	}
		//}
		//for (int i = 0; i < NumVertex-1; i++) {
		//	for (int j = p1; j < NumVertex; j++) {
		//		Edge[i][j] = Edge[i + 1][j];
		//	}
		//}

		//覆盖方法
		//用最后一个顶点覆盖要删除的顶点
		Vertex[p1] = Vertex[NumVertex - 1];
		//用最后一列覆盖要删除顶点对应的列
		for (int i = 0; i < NumVertex; i++) {
			Edge[i][p1] = Edge[i][NumVertex - 1];
		}
		for (int i = 0; i < NumVertex; i++) {
			Edge[p1][i] = Edge[p1][NumVertex - 1];
		}

		//用最后一行覆盖要删除顶点对应的行
		NumVertex--;
		NumEdge -= DelEdge;
	}

private:
	int MaxVertex;//顶点的最大个数
	int NumVertex;//顶点的实际个数
	char * Vertex;//存储顶点信息
	int Edge[SIZE][SIZE];//存储顶点边的信息；
	int NumEdge;//边的实际条数
};
int main() {
	Graph g;
	g.InsertVertex('a');
	g.InsertVertex('b');
	g.InsertVertex('c');
	g.InsertVertex('d');
	g.InsertEdge('a', 'b');
	g.InsertEdge('a', 'c');
	g.InsertEdge('a', 'd');
	g.InsertEdge('b', 'c');
	g.InsertEdge('c', 'd');
	g.PrintGraph();
	g.DeleteEdge('a', 'c');
	g.PrintGraph();
	g.DeleteVertex('d');
	g.PrintGraph();
	return 0;
}
#endif