#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
vector<int> pre,in;
void getpost(int rt,int l,int r){
	if(l > r) return;
	int k = l;
	while(in[k] != pre[rt]) k++;
	getpost(rt+1,l,k-1);
	getpost(rt+1+k-l,k+1,r);//Ìø¹ý×ó×ÓÊ÷ rt+1+k-l
	printf("%d ",in[k]);
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
//	cout<<getpost(0,0,n-1)<<endl;
	getpost(0,0,n-1);
	printf("\n"); 
	return 0;
}
