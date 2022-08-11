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
		/*1.���㵱ǰ��ض���ı���
		2.Vertex,Edge�������鶼�ñ仯
		3.�����ƶ���ά������к���||�����һ���и��ǵ�һ�У������һ�и��ǵ�ǰ��
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
		
		////������������Ҫɾ���Ķ���������ǰ�ƶ�
		//for (int i = p1; i <NumVertex-1; i++) {
		//	Vertex[i] = Vertex[i + 1];
		//}
		////����ǰ��������֮����к�����������ƶ�
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

		//���Ƿ���
		//�����һ�����㸲��Ҫɾ���Ķ���
		Vertex[p1] = Vertex[NumVertex - 1];
		//�����һ�и���Ҫɾ�������Ӧ����
		for (int i = 0; i < NumVertex; i++) {
			Edge[i][p1] = Edge[i][NumVertex - 1];
		}
		for (int i = 0; i < NumVertex; i++) {
			Edge[p1][i] = Edge[p1][NumVertex - 1];
		}

		//�����һ�и���Ҫɾ�������Ӧ����
		NumVertex--;
		NumEdge -= DelEdge;
	}

private:
	int MaxVertex;//�����������
	int NumVertex;//�����ʵ�ʸ���
	char * Vertex;//�洢������Ϣ
	int Edge[SIZE][SIZE];//�洢����ߵ���Ϣ��
	int NumEdge;//�ߵ�ʵ������
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