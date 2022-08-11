#include<iostream>
#include<queue>
#define SIZE 10
using namespace std;
class Edge {
public:
	Edge() :next() {}
	Edge(int dv) :m_destvalue(dv), next(nullptr) {}
	int m_destvalue;
	Edge* next;
	
};
class Vertex{
public:
	Vertex() :m_list(nullptr) {}
	Vertex(char v) :m_value(v), m_list(nullptr) {}
	
	char m_value;
	Edge* m_list;

};
class Graph {
public:
	Graph(){
		MaxVertex = SIZE;
		NumVertex = NumEdger = 0;
		//Verarr = new Vertex[SIZE];
	}
	~Graph(){
		//if (Verarr != nullptr) {
		//	delete[]Verarr;
		//	Verarr = nullptr;
		//}
	}
	void InsertVertex(char v) {
		if (NumVertex >=MaxVertex) {
			return;
		}
		Verarr[NumVertex++].m_value = v;
	}
	void InsertEdge(char v1,char v2){
		int p1 = GetVertex(v1);
		int p2 = GetVertex(v2);
		if (p1 ==-1 || p2 == -1) {
			return;
		}
		//v1->v2
		Edge* p = new Edge(p2);
		
		p->next = Verarr[p1].m_list;
		Verarr[p1].m_list = p;
		//v2->v1
		p = new Edge(p1);
		p->next = Verarr[p2].m_list;
		Verarr[p2].m_list = p;
		NumEdger++;
	}
	void PrintGraph(){
		Edge* p = nullptr;
		for (int i = 0; i < NumVertex; i++) {
			cout << i<<" : " << Verarr[i].m_value << "->";
			p = Verarr[i].m_list;
			while (p!=nullptr) {
				cout << p->m_destvalue << "->";
				p = p->next;
			}
			cout << "nullptr"<<endl;
		}
	}
	/*void Print()
	{
		for (int i = 0; i < NumVertex; ++i) {
			Edge* p = Verarr[i].m_list;

			cout << Verarr[i].m_value << ": ";
			
			while (p!= nullptr)
			{
				cout << p->m_destvalue<< " ";
				p = p->next;
			}

			cout << endl;
		}
	}*/
	int GetVertex(char v){
		for (int i = 0; i < NumVertex; i++) {
			if (Verarr[i].m_value==v)
			{
				return i;
			}
		}
		return -1;
	}
	void DeleteEdge(char v1, char v2) {
		/*删除边
		首先找到这两个顶点所在的下标
		其次v1对应的链表中 找到p2-删除p2
		
		*/
		int p1 = GetVertex(v1);
		int p2 = GetVertex(v2);
		Edge* p = nullptr, * pf = nullptr;
		//删除v1-v2
		p = Verarr[p1].m_list;
		while (p != nullptr&&p->m_destvalue!=p2) {
			pf = p;
			p = p->next;
		}
		if (p == nullptr) {
			return;
		}
		if (pf == nullptr) {
			//说明是头结点
			Verarr[p1].m_list = p->next;
		}
		else {
			pf->next = p->next;
		}
		//删除v2->v1
		delete p;
		pf = nullptr;
		p = Verarr[p2].m_list;
		while (p != nullptr && p->m_destvalue != p1) {
			pf = p;
			p = p->next;
		}
		if (p == nullptr){
			return;
		}
		//如果pf为空-说明删除的是头结点
		if (pf == nullptr) {
			Verarr[p2].m_list = p->next;
		}
		else {
			pf->next = p->next;
		}
		delete(p);
		p =nullptr;
		NumEdger--;
	}
	//删除对应的顶点
	void DeleteVertex(char v) {
		/*要删除顶点，首先删除与顶点相对应的边*/
		int index = GetVertex(v);
		if (index == -1) {
			return;
		}
		Edge* p = nullptr;
		char destvalue;
		//p 指向要删除顶点的链表
		p = Verarr[index].m_list;
		while (p != nullptr) {
			//获得相关联的的顶点
			destvalue = Verarr[p->m_destvalue].m_value;
			DeleteEdge(v, destvalue);
			p = Verarr[index].m_list;
		}
		/*删除相对应的边之后，删除对应的顶点--使用-用最后一个去覆盖删除的那一个
		最后修改每一个--链表中对应边的下标
		*/
		NumVertex--;
		//最后一个覆盖对应删除的
		Verarr[index].m_list = Verarr[NumVertex].m_list;
		Verarr[index].m_value = Verarr[NumVertex].m_value;
		//修改
		Edge* q = nullptr;
		p = Verarr[index].m_list;
		while (p) {
			int k = p->m_destvalue;
			q = Verarr[k].m_list;//找到与其顶点对应的边链表
			while (q) {
				if (q->m_destvalue = NumVertex) {
					q->m_destvalue = index;
					break;
				}
				q = q->next;
			}
			p = p->next;
		}
	}
	void DFS(int k, bool* viste) {
		//先访问当前结点
		cout << Verarr[k].m_value << " ";
		viste[k] = true;
		Edge* p = Verarr[k].m_list;//p指向单链表
		while (p) {
			//从没有被访问过的结点开始
			if (!viste[p->m_destvalue]) {
				DFS(p->m_destvalue, viste);
			}
			//如果当前结点被访问，则从下一个邻接顶点开始
			p = p->next;
		}
		cout << endl;
	}
	void DFS(char v) {
		bool *viste = new bool[NumVertex];
		for (int i = 0; i < NumVertex; i++) {
			viste[i] = false;
		}
		int index = GetVertex(v);
		DFS(index, viste);
		delete[]viste;
		viste = nullptr;
	}
	void BFS(char v) {
		bool* visited = new bool[NumVertex];
		for (int i = 0; i < NumVertex; i++) {
			visited[i] = false;
		}
		int index = GetVertex(v);
		if (index == -1)
			return;
		queue<int>q;
		q.push(index);
		int front;
		Edge* p = nullptr;
		cout << v << " ";
		visited[index] = true;
		while (!q.empty()) {
			front = q.front();
			q.pop();
			p = Verarr[front].m_list;
			while (p != nullptr) {
				if (!visited[p->m_destvalue]) {
					//如果当前结点没有被访问过，那么就将当前结点入栈--并输出结点，将结点设为访问过
					q.push(p->m_destvalue);
					cout << Verarr[p->m_destvalue].m_value << " ";
					visited[p->m_destvalue] = true;
				}
				p = p->next;
			}
		}
		cout << endl;
	}
private:
	//Vertex* Verarr;//顶点数组
	Vertex Verarr[10];
	int MaxVertex;//最大顶点的个数
	int NumVertex;//顶点的实际个数
	int NumEdger;//顶点的实际边数
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

	cout << endl;
	//g.DeleteEdge('a', 'c');
	//g.DeleteVertex('a');
	cout << "------DFS------" << endl;
	g.DFS('a');
	cout << "------BFS-------" << endl;
	g.BFS('a');


	return 0;
}