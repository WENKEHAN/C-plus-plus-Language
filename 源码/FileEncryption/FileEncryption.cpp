#if 0
#include <iostream>
#include <string>
#include<fstream>
#include<unordered_map>
/*C++ ����3����Ҫ�ļ���д����
ifstream �ļ���ȡ��
ofstream �ļ�д����
fstream �ļ���ȡ��д����

*/
using namespace std;
class ReadFile {
public:
	//���ļ���ȡ���ַ�����
	string Read(const string& filename) {
		//��ȡ�ļ���ȡ����
		/*open ���������� ��һ������ ��ַ ���ڶ��� �ļ��Ĳ���ģʽ
		in ��ȡ
		out д��
		app ׷��
		ate �򿪶�λ���ļ�ĩβ
		trunc ���ļ��󣬽ض�֮ǰ�����ݣ���ͷ��ʼд
		*/

		cout << "��ȡ�ļ�����" << endl;
		char c;
		string src;
		ifstream refile;
		refile.open(filename, ios::in);
		if (!refile.is_open()) {
			cout << "�ļ�������" << endl;
			return src;
		}
		//.eof�ж��ļ��Ƿ�Ϊ�ջ����ļ��Ƿ�ĩβ
		while (!refile.eof()) {
			refile.get(c);
			src.push_back(c);
		}
		refile.close();
		cout << src << endl;
		return src;
	}

};
class Encryption {

};
class WritFile {
public:
	void Writ(const string& filename,const string &src) {
		cout << "�����ļ�" << endl;
		ofstream wrfile;
		wrfile.open(filename);
		if (!wrfile.is_open()) {
			cout << "�ļ�������" << endl;
			return;
		}
		for (auto s : src) {
			wrfile.put(s);
		}
		wrfile.close();
		return;
	}
};
class EncryptFacade {
	//ά�ֶ��������������
private:
	ReadFile reader;
	WritFile writer;
public:
	void FileEncrypt(string filenameSrc, string filenameDes) {
		string plainStr = reader.Read(filenameSrc);
		writer.Writ(filenameDes,plainStr);
	}
};
int main() {
	EncryptFacade ef;
	ef.FileEncrypt("src.txt", "des.txt");
	return 0;
}
#endif
