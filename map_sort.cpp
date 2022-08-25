#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include <sstream>
#include <map>
using  namespace std;
bool cmp(const pair<string,int>&a,const pair<string,int>&b){
    return a.second>b.second;//从大到小
}
int main()	   //
{
    std::map<std::string, int > simap;
    std::string ip;
    std::stringstream stmp;
    for (int i = 0; i < 100000; ++i)
    {
        stmp <<127 << "." << 45 << "." <<23 << "." << rand() % 256;
        ip = stmp.str();
        simap[ip] += 1;
        stmp.clear();
        stmp.str("");
    }
    for (auto& x : simap)
    {
        cout << x.first << " ==> " << x.second << endl;

    }
    //因为map的第一个是通过字典序来进行，所以这里要放入到vector当中队第二个--出现次数继续进行比较
    vector<pair<string,int>>v;
    for(auto &x:simap){
        v.push_back(x);
    }
    sort(v.begin(),v.end(),cmp);
    //获取出现次数最多的10个值
    cout<<"出现次数最多的10个ip地址"<<endl;
    for(int i=0;i<10;i++){
        cout<<v[i].first<<"=>"<<v[i].second<<endl;
    }
    return 0;
}