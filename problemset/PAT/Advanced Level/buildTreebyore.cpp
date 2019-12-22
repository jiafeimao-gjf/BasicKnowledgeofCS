#include <cstdio>

struct BTree{
	int val;
	int l,r;
	BTree(){
		val = 0;
		l = r = -1;
	}
};
BTree bt[1000];
int pre[1000];
int rt = 0;
void Build(int root,int tail){
	if(root > tail) return;
	
}
void inorder(int root){
	if(root != -1){
		inorder(bt[root].l);
		printf("%d ",bt[root].val);
		inorder(bt[root].r);
	}
} 
int main(){
	int n;
	scanf("%d",&n);
	for(int i = 0;i < n;i++){
		scanf("%d",(pre + i));
	}
	Build(0,n-1);
	inorder(0);
	printf("\n");
	return 0;
} 
