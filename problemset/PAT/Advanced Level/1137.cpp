//1137 map or struct
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
map<string,vector<int> > stu;
typedef pair<string,vector<int> > PAIR;
//struct ComByValue{
//	bool operator()(const PAIR &a,const PAIR &b) const{
//		return a.second[4] > b.second[4];
//	}
//};
bool ComByValue(const PAIR &a,const PAIR &b){
	return a.second[3] != b.second[3]? a.second[3] > b.second[3] : a.first < b.first;
}
int main(){
	int p,m,n;
	cin>>p>>m>>n;
	string name;
	int p1;
	for(int i = 0;i < p;i++){
		cin>>name>>p1;
		stu[name].resize(3);
		if(p1 >= 200) {
			stu[name][0] = p1;
			stu[name][1] = -1;
			stu[name][2] = -1;	
		}
	}
	for(int i = 0;i < m;i++){
		cin>>name>>p1;
		if(stu.find(name) != stu.end()) stu[name][1] = p1;
	}
	for(int i = 0;i < n;i++){
		cin>>name>>p1;
		if(stu.find(name) != stu.end()) {
			stu[name][2] = p1;
		}
	}
	map<string,vector<int> > nstu;
	for(map<string,vector<int> >::iterator it = stu.begin();it != stu.end();it++){
		if(it->second[2] < it->second[1] && (int)(it->second[1]*0.4 + it->second[2]*0.6 + 0.5) >= 60){
			name = it->first;
			nstu[name].resize(4);
			nstu[name][0] = it->second[0];
			nstu[name][1] = it->second[1];
			nstu[name][2] = it->second[2];
			nstu[name][3] = (int)(it->second[1]*0.4 + it->second[2]*0.6 + 0.5);
		}else if(it->second[2] >= 60){
			name = it->first;
			nstu[name].resize(4);
			nstu[name][0] = it->second[0];
			nstu[name][1] = it->second[1];
			nstu[name][2] = nstu[name][3] = it->second[2];
		}
	}
	stu.clear();
	vector<PAIR> nnstu(nstu.begin(),nstu.end());
	sort(nnstu.begin(),nnstu.end(),ComByValue);
	for(int i = 0;i != nnstu.size();i++){
		cout<<nnstu[i].first<<" "<<nnstu[i].second[0]<<" "<<nnstu[i].second[1]
		<<" "<<nnstu[i].second[2]<<" "<<nnstu[i].second[3]<<endl;
	}
	return 0;
} 
