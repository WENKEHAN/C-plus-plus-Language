#if 0
#include <iostream>
#include <string>
#include<fstream>
#include<unordered_map>
/*C++ 当中3个重要文件读写的类
ifstream 文件读取流
ofstream 文件写入流
fstream 文件读取和写入流

*/
using namespace std;
class ReadFile {
public:
	//将文件读取到字符串中
	string Read(const string& filename) {
		//读取文件获取明文
		/*open 有两个参数 第一个参数 地址 ，第二个 文件的操作模式
		in 读取
		out 写入
		app 追加
		ate 打开定位到文件末尾
		trunc 打开文件后，截断之前的内容，从头开始写
		*/

		cout << "读取文件内容" << endl;
		char c;
		string src;
		ifstream refile;
		refile.open(filename, ios::in);
		if (!refile.is_open()) {
			cout << "文件不存在" << endl;
			return src;
		}
		//.eof判断文件是否为空或者文件是否到末尾
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
		cout << "保密文件" << endl;
		ofstream wrfile;
		wrfile.open(filename);
		if (!wrfile.is_open()) {
			cout << "文件不存在" << endl;
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
	//维持对其它对象的引用
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
