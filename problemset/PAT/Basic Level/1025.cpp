#include <iostream>
#include <cstdio>
using namespace std;
//ÿK���ڵ㷴ת���ֶη�ת,ͷ�巨��ת���ڷ�תÿһ��֮ǰ����Ҫ��¼�öη�ת֮���β���
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
	int p = head;//pΪ��һ���ڵ����� 
	int r,nr; 
	for(int i = 0; i < (n/k);i++){
		int q = nodes[p][1];	//��¼�ڶ����ڵ� 
		for(int j = 1;j < k;j++){	//ͷ�巨
			int t = nodes[q][1];//��ʱ�洢�������ڵ� 
			nodes[q][1] = p;//���ڶ��������ڵ�һ�����ǰ��
			p = q;//���µ�һ���ڵ�
			q = t;//���µڶ������
		}//�˳�ѭ����pΪ�µ�ͷ��� 
		if(i == 0){//��1�η�ת��
			r = head;//��¼��1�ε�β������� 
			head = p;//����ͷ�������
		} else{//���ǵ�1��
			nodes[r][1] = p;//����i-1�ε����һ��������i�ε���ͷ������� 
			r = nr;//����
		}
		p = q;//����ͷ������� 
		nr = p;//p��㽫������һ�ε�β���	
	}
	if(n%k == 0){//���� 
		nodes[r][1] = -1;
	}else {//��������
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
