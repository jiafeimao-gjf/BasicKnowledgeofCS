#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
vector<int> pre,in;
int getpost(int rt,int l,int r){
	if(l > r) return in[r];
	int k = l;
	while(in[k] != pre[rt]) k++;
	if(k > l) return getpost(rt+1,l,k-1);
	else return getpost(rt+1,k+1,r);
}
int main(){
	int n;
	scanf("%d",&n);
	pre.resize(n);
	in.resize(n);
	for(int i = 0;i < n;i++){
		scanf("%d",&pre[i]);
	}
	for(int i = 0;i < n;i++){
		scanf("%d",&in[i]);
	} 
	cout<<getpost(0,0,n-1)<<endl;
	return 0;
}
