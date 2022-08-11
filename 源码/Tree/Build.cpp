#include<iostream>
#include<vector>
using namespace std;
class Node {
public:
    Node(int v) :val(v), left(nullptr), right(nullptr) {}
    int val;
    Node* left;
    Node* right;
    //���캯��д��ǰ��ͺ��������
};
class Tree {
public:
    vector<int>pro;
    vector<int>mid;
    vector<int>tr;
public:
    //���ַ���ʱ�Ĵ���
/*    Node *Create(string &s,int k)
    {
        if(k<s.length()){
            if(s[k] == '*')
                return nullptr;
            else
            {
                Node *root = new Node(s[k]);
                root->left = Create(s,++k);
                root->right = Create(s,++k);
                return root;
            }
        }
    }*/
    Node* Creat(int*& str)
    {
        if (*str == -1)
            return nullptr;
        else
        {
            Node* root = new Node(*str);
            root->left = Creat(++str);
            root->right = Creat(++str);
            return root;
        }
    }
    //������ǰ��ı���
    vector<int> &ProTraver(Node* const& root) {
        if (root == nullptr) {
            return pro;
        }
        pro.push_back(root->val);
        ProTraver(root->left);
        ProTraver(root->right);
        return pro;
    }
    //�������
    vector<int> InTraver(Node* const& root) {
        if (root == nullptr) {
            return mid;
        }
        InTraver(root->left);
        mid.push_back(root->val);
        InTraver(root->right);
        return mid;
    }
    //��������
    vector<int> Traver(Node* const& root) {
        if (root == nullptr) {
            return tr;
        }
        Traver(root->left);
        Traver(root->right);
        tr.push_back(root->val);
        return tr;
    }
    //ͨ��ǰ���������������ָ�������
    Node* Create(vector<int>& Pro, int Pstart, int Pend, vector<int>& In, int Instart, int Inend) {
        if (Pstart > Pend) {
            return nullptr;
        }
        int rootval = Pro[Pstart];
        int temp = 0;
        for (int i = 0; i < In.size(); i++) {
            if (In[i] == rootval) {
                temp = i;
                break;
            }
        }
        //�������Ӧ��ƫ����--��Ӧ���������ĸ���
        int leftsize = temp - Instart;
        Node* Newroot = new Node(rootval);
        Newroot->left = Create(Pro, Pstart + 1, Pstart + leftsize, In, Instart, temp - 1);
        Newroot->right = Create(Pro, Pstart + leftsize + 1, Pend, In, temp + 1, Inend);
        return Newroot;
    }
    void PerOrder(Node *node,int path_sum,int sum,vector<int>&path,vector<vector<int> >&ret){
        if (!node) {
            return;
        }
        path_sum = path_sum + node->val;//��ÿһ��·���ϵĽ��ֵ����
        path.push_back(node->val);//��ջ����ǰ��㱣������ʱ·��
        //�жϵ�ǰ�Ƿ�Ҷ�ӽ���Լ����Ƿ����Ҫ��
        if (node->left == nullptr && node->right == nullptr && path_sum == sum) {
            ret.push_back(path);
        }
        PerOrder(node->left, path_sum, sum, path, ret);
        PerOrder(node->right, path_sum, sum, path, ret);
        path_sum = path_sum - node->val;
        path.pop_back();
    }
    void Ance(Node* root, vector<Node*>& temp, int nums, vector<Node*>& ret, int& flag)
    {
        //���������ս������ҵ�·�������˳�
        if (root == NULL || flag == 1)
        {
            return;
        }
        temp.push_back(root);//����ǰ�����ջ
        if (root->val == nums) //�ҵ���ǰ��㣬���·�������ñ��
        {
            flag = 1;
            ret = temp;
        }
        Ance (root->left, temp, nums, ret, flag);
        Ance(root->right, temp, nums, ret, flag);

        temp.pop_back();
    }

};
int main() {
    Tree tree;
    int  s[] = { 1,2,4,3,-1,-1,6,-1,-1,7,-1,-1,5,-1,8,-1,-1 };
    int* ch = s;
    Node* root2 = tree.Creat(ch);
    //vector<int>Pro = tree.ProTraver(root2);
    //vector<int>Mid = tree.InTraver(root2);
    //vector<int>Tre = tree.Traver(root2);
    //cout << endl;
    //Node* root1 = tree.Create(Pro, 0, Pro.size() - 1, Mid, 0, Mid.size() - 1);
    tree.mid.clear();
    vector<int>res =tree.InTraver(root2);
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }
    vector<int>path;
    vector<vector<int> >ret;
    tree.PerOrder(root2,0,14,path,ret);
    cout << "��Ϊ12��·��" << endl;
    for (int i = 0; i < ret.size(); i++) {
        for (int j = 0; j < ret[i].size(); j++) {
            cout << ret[i][j] << " ";
        }
        cout << endl;
    }
    vector<Node *>temp;
    vector<Node*>r;
    int flag = 0;
    tree.Ance(root2, temp, 7, r, flag);
    
    cout << endl;
    return 0;
}