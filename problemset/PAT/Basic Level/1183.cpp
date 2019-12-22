#include <cstdio>
#include <map>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
struct node{
	int cha;
	int times;
};
vector<node> record;
map<int,int> index;
bool cmp(node a,node b){
	return a.cha > b.cha;
} 
int main(){
	int n,num;
	scanf("%d",&n);
	int cnt = 0;
	for(int i = 1;i <= n;i++){
		scanf("%d",&num);
		int res = abs(i - num);
		if(index.find(res) == index.end()){
			index[res] = cnt;
			record.push_back(node{res,1});
			cnt++;
		}else{
			record[index[res]].times++;
		}
	}
	sort(record.begin(),record.end(),cmp);
	for(int i = 0;i < record.size();i++){
		if(record[i].times >= 2) 
		printf("%d %d\n",record[i].cha,record[i].times);
	}
	return 0;
}
