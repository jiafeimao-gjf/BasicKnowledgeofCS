#include <cstdio>
#include <vector>
using namespace std;
bool isMirror = false;
vector<int> pre,post;
void getpost(int root,int tail){
	if(root > tail) return;
	int i = root + 1,j = tail;
	if(!isMirror){
		while(i <= tail && pre[root] > pre[i]) i++;//自左向右，找到第一个大于等于根的节点 
		while(j > root && pre[root] <= pre[j]) j--;//自右向左，找到第一个小于根的节点 
	}else{
		while(i <= tail && pre[root] <= pre[i]) i++;
		while(j > root && pre[root] > pre[j]) j--;
	}
	//i 为新root,j 为新tail 
	if(i - j != 1) return;//不符合二叉搜索树定义 
	getpost(root + 1, j);
	getpost(i,tail);
	post.push_back(pre[root]); 
}
int main(){
	int n;
	scanf("%d",&n);
	pre.resize(n);
	for(int i = 0; i < n; i++){
		scanf("%d",&pre[i]);
	}
	getpost(0,n - 1);
	if(post.size() != n){
		isMirror = true;
		post.clear();
		getpost(0,n - 1);
	}
	if(post.size() == n){
		printf("YES\n%d",post[0]);
		for(int i = 1; i < n;i++){
			printf(" %d",post[i]);
		}
	}else{
		printf("NO");
	}
	return 0;
} 
