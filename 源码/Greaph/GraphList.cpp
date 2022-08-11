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
		/*ɾ����
		�����ҵ��������������ڵ��±�
		���v1��Ӧ�������� �ҵ�p2-ɾ��p2
		
		*/
		int p1 = GetVertex(v1);
		int p2 = GetVertex(v2);
		Edge* p = nullptr, * pf = nullptr;
		//ɾ��v1-v2
		p = Verarr[p1].m_list;
		while (p != nullptr&&p->m_destvalue!=p2) {
			pf = p;
			p = p->next;
		}
		if (p == nullptr) {
			return;
		}
		if (pf == nullptr) {
			//˵����ͷ���
			Verarr[p1].m_list = p->next;
		}
		else {
			pf->next = p->next;
		}
		//ɾ��v2->v1
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
		//���pfΪ��-˵��ɾ������ͷ���
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
	//ɾ����Ӧ�Ķ���
	void DeleteVertex(char v) {
		/*Ҫɾ�����㣬����ɾ���붥�����Ӧ�ı�*/
		int index = GetVertex(v);
		if (index == -1) {
			return;
		}
		Edge* p = nullptr;
		char destvalue;
		//p ָ��Ҫɾ�����������
		p = Verarr[index].m_list;
		while (p != nullptr) {
			//���������ĵĶ���
			destvalue = Verarr[p->m_destvalue].m_value;
			DeleteEdge(v, destvalue);
			p = Verarr[index].m_list;
		}
		/*ɾ�����Ӧ�ı�֮��ɾ����Ӧ�Ķ���--ʹ��-�����һ��ȥ����ɾ������һ��
		����޸�ÿһ��--�����ж�Ӧ�ߵ��±�
		*/
		NumVertex--;
		//���һ�����Ƕ�Ӧɾ����
		Verarr[index].m_list = Verarr[NumVertex].m_list;
		Verarr[index].m_value = Verarr[NumVertex].m_value;
		//�޸�
		Edge* q = nullptr;
		p = Verarr[index].m_list;
		while (p) {
			int k = p->m_destvalue;
			q = Verarr[k].m_list;//�ҵ����䶥���Ӧ�ı�����
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
		//�ȷ��ʵ�ǰ���
		cout << Verarr[k].m_value << " ";
		viste[k] = true;
		Edge* p = Verarr[k].m_list;//pָ������
		while (p) {
			//��û�б����ʹ��Ľ�㿪ʼ
			if (!viste[p->m_destvalue]) {
				DFS(p->m_destvalue, viste);
			}
			//�����ǰ��㱻���ʣ������һ���ڽӶ��㿪ʼ
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
					//�����ǰ���û�б����ʹ�����ô�ͽ���ǰ�����ջ--�������㣬�������Ϊ���ʹ�
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
	//Vertex* Verarr;//��������
	Vertex Verarr[10];
	int MaxVertex;//��󶥵�ĸ���
	int NumVertex;//�����ʵ�ʸ���
	int NumEdger;//�����ʵ�ʱ���
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