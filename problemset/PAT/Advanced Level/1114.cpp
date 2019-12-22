#include <iostream>
#include <cstdio>
using namespace std;

struct people{
	int f,m,k,estate,area;
	int children[5];
};

people peo[10000];
int ufset[10000];
int find(int a){
	int r = a;
	while(ufset[r] != r){
		r = ufset[r];
	}
	return r;
}

void join(int a,int b){
	int aa = find(a),bb = find(b);
	if(aa==bb){
		if(aa>bb){
			ufset[aa] = bb;
		}else{
			ufset[bb] = aa;
		}
	}
}
int main(){
	int N;
	
	for(int i = 0;i < 10000;i++){
		ufset[i] = -1;
	}
	cin>>N;
	for(int i = 0;i < N;i++){
		int id;
		cin>>id;
		cin>>peo[id].f>>peo[id].m>>peo[id].k;
		int minchild = 10000;
		for(int j = 0;j < peo[id].k;j++){
			cin>>peo[id].children[j];
			if(peo[id].children[j] < minchild){
				minchild = peo[id].children[j];
			}
		}
		for(int j = 0;j < peo[id].k;j++){
			if(peo[id].children[j] != minchild)
			ufset[peo[id].children[j]] = minchild;
		}
		if(minchild != 10000){
			if(peo[id].f != -1) ufset[peo[id].f] = minchild;
			if(peo[id].m != -1) ufset[peo[id].m] = minchild;
			ufset[minchild] = minchild;
		}else{
			if(peo[id].f != -1) ufset[peo[id].f] = id;
			if(peo[id].m != -1) ufset[peo[id].m] = id;
			ufset[id] = id;
		}
		cin>>peo[id].estate>>peo[id].area;
	}
	for(int i = 0;i < 10000;i++){
		if(ufset[i] == i) printf("%04d",i);
	}
	return 0;
}
