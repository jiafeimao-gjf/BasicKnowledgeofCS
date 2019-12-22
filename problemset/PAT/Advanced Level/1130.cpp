#include <string>
#include <iostream>
using namespace std;

struct tree{
	string data;
	int left,right;
};

struct tree Btree[21];
int root;
bool inorder(int rt){
	if(rt != -1 ){
		int tag = 0;
		if(Btree[rt].right != -1 && rt != root) tag = 1;
		if(tag) cout<<"(";
		if(inorder(Btree[rt].left)){
			cout<<Btree[rt].data;
			if(inorder(Btree[rt].right)){
				if(tag) cout<<")";
				return true;
			}
		}
	}
	return true;
}
int main(){
	int N;
	cin>>N;
	int ufset[21];
	for(int i = 1;i < 21;i++){
		ufset[i] = -1;
	}
	for(int i = 1;i <= N;i++){
		cin>>Btree[i].data>>Btree[i].left>>Btree[i].right;
		if(ufset[Btree[i].left] != -1) ufset[Btree[i].left] = i;
		if(ufset[Btree[i].right] != -1) ufset[Btree[i].right] = i;
	}
	for(int i = 1;i <= N;i++){
		if(ufset[i] == -1){
			root = i;
			break;
		}
	}
	inorder(root);
	return 0;
}

