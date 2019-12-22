#include <cstdio>
#include <vector>
using namespace std;
bool isMirror = false;
vector<int> pre,post;
void getpost(int root,int tail){
	if(root > tail) return;
	int i = root + 1,j = tail;
	if(!isMirror){
		while(i <= tail && pre[root] > pre[i]) i++;//�������ң��ҵ���һ�����ڵ��ڸ��Ľڵ� 
		while(j > root && pre[root] <= pre[j]) j--;//���������ҵ���һ��С�ڸ��Ľڵ� 
	}else{
		while(i <= tail && pre[root] <= pre[i]) i++;
		while(j > root && pre[root] > pre[j]) j--;
	}
	//i Ϊ��root,j Ϊ��tail 
	if(i - j != 1) return;//�����϶������������� 
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
