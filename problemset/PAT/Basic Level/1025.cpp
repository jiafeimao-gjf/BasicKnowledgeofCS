#include <iostream>
#include <cstdio>
using namespace std;
//每K个节点反转，分段反转,头插法反转，在反转每一段之前，需要记录该段反转之后的尾结点
/*
00100 7 3
00000 4 99999
00100 1 12309
68237 6 44444
44444 7 -1
33218 3 00000
99999 5 68237
12309 2 33218
*/ 
int main(){
	int nodes[100001][2];
	int head,n,k,add,data,next;
	cin>>head>>n>>k;
	for(int i = 0;i < n;i++){
		cin>>add>>data>>next;
		nodes[add][0] = data;
		nodes[add][1] = next;
	}
	int p = head;//p为第一个节点索引 
	int r,nr; 
	for(int i = 0; i < (n/k);i++){
		int q = nodes[p][1];	//记录第二个节点 
		for(int j = 1;j < k;j++){	//头插法
			int t = nodes[q][1];//临时存储第三个节点 
			nodes[q][1] = p;//将第二个结点插在第一个结点前面
			p = q;//更新第一个节点
			q = t;//跟新第二个结点
		}//退出循环后，p为新的头结点 
		if(i == 0){//第1段反转后
			r = head;//记录第1段的尾结点索引 
			head = p;//更新头结点索引
		} else{//不是第1段
			nodes[r][1] = p;//将第i-1段的最后一个结点与第i段的新头结点相连 
			r = nr;//跟新
		}
		p = q;//更新头结点索引 
		nr = p;//p结点将会变成下一段的尾结点	
	}
	if(n%k == 0){//整除 
		nodes[r][1] = -1;
	}else {//不能整除
		nodes[r][1] = p;
	}
	int t = head;
	while(nodes[t][1] != -1){
		printf("%05d %d %05d\n",t,nodes[t][0],nodes[t][1]);
		t = nodes[t][1];
	}
	printf("%05d %d %d\n",t,nodes[t][0],nodes[t][1]);
	return 0;
} 
