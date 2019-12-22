//自定义结构体与STL容器混用 
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
struct node{
	string name;
	int gp,gm,gf,g;
};
bool cmp(node a,node b){
	return a.g != b.g ? a.g > b.g : a.name < b.name;
}
map<string,int> idx;
int main(){
	int p,m,n,score;
	int cnt = 1;
	cin>>p>>m>>n;
	vector<node> v,ans;
	string name;
	for(int i = 0;i < p;i++){
		cin>>name>>score;
		if(score >= 200){
			node stu = {name,score,-1,-1,0};
			v.push_back(stu);
			idx[name] = cnt++;//idx中的默认Value为0 
		}
	} 
	for(int i = 0;i < m;i++){
		cin>>name>>score;
		if(idx[name] != 0)//exist
		v[idx[name] - 1].gm = score; 
	} 
	for(int i = 0;i < n;i++){
		cin>>name>>score;
		if(idx[name] != 0){//exist
			int t = idx[name] - 1;
			v[t].gf = v[t].g = score;
			if(v[t].gm > v[t].gf) v[t].g = int(v[t].gm*0.4 + v[t].gf*0.6 + 0.5);
		}
	}
	for(int i = 0;i < v.size();i++){
		if(v[i].g >= 60) ans.push_back(v[i]);
	} 
	sort(ans.begin(),ans.end(),cmp);
	for(int i = 0;i < ans.size();i++){
		printf("%s %d %d %d %d\n",ans[i].name.c_str(),ans[i].gp,ans[i].gm,ans[i].gf,ans[i].g);
	}
	return 0;
}
