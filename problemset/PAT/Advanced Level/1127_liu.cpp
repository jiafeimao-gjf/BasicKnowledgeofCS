#include <iostream>
#include <vector>
#include <queue>
using namespace std;
vector<int> in,post;//��������ͺ���������� 
vector<int> result[35];//�洢ÿһ��Ĵ������ҵ�����
int n,tree[35][2],root;
struct node{//��¼��Ӧ�ڵ����� 
	int index,depth;
};
void dfs(int &index,int inLeft,int inRight,int postLeft,int postRight){//�ݹ齨�� 
	if(inLeft > inRight) return;
	index = postRight;//����ĸ����Ҳ� 
	int i = inLeft;//Ϊʲô��0��ʼ�������Ǵ�inLeft 
	while(in[i] != post[postRight]) i++;
	dfs(tree[index][0],inLeft,i - 1,postLeft,postLeft + (i - inLeft) - 1);//�������ݹ� 
	dfs(tree[index][1],i + 1,inRight,postLeft + (i - inLeft),postRight - 1);
}
void bfs(){//������� 
	queue<node> q;
	q.push(node{root, 0});
	while(!q.empty()){
		node temp = q.front(); //��ö���Ԫ�� 
		q.pop();
		result[temp.depth].push_back(post[temp.index]);//���������ҵ�˳��洢��Ӧ��εĽڵ� 
		if(tree[temp.index][0] != 0)//�������ǿգ���� 
			q.push(node{tree[temp.index][0],temp.depth + 1});
		if(tree[temp.index][1] != 0)//�������ǿգ���� 
			q.push(node{tree[temp.index][1],temp.depth + 1});
	}
}
int main(){
	cin>>n;
	in.resize(n + 1);post.resize(n + 1);
	for(int i = 1;i <= n; i++) cin >> in[i];
	for(int i = 1;i <= n; i++) cin >> post[i];
	dfs(root,1,n,1,n);
	bfs();
	printf("%d",result[0][0]);//��һ��ֻ��һ�����ڵ� 
	for(int i = 1;i < 35; i++){
		if(i % 2 == 1){//������������� 
			for(int j = 0;j < result[i].size(); j++){
				printf(" %d",result[i][j]);
			}
		}else{//ż����������� 
			for(int j = result[i].size() - 1;j >= 0; j--){
				printf(" %d",result[i][j]);
			}
		}
	}
	return 0;	
}
