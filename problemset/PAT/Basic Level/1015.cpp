//1015. �²��� (25) �����һ�㷽���ľ������ⷽ������ɲ��˵� 

//�����ı���������,���ò������� 
 
 /*
 �����1�и���3�����������ֱ�Ϊ��
 		N��<=105����������������
 		L��>=60����Ϊ¼ȡ��ͷ����ߣ����·ֺͲŷ־�������L�Ŀ��������ʸ񱻿���¼ȡ��
 		H��<100����Ϊ����¼ȡ�ߡ���
	 �·ֺͲŷ־������ڴ��ߵı�����Ϊ���ŵ�ȫ���������࿼�����²��ִܷӸߵ�������
	 �ŷֲ������·ֵ��ߵ�һ�࿼�����ڡ���ʤ�š���Ҳ���ܷ����򣬵����ڵ�һ�࿼��֮��
	 �²ŷ־�����H�����ǵ·ֲ����ڲŷֵĿ������ڡ��ŵ¼����������С���ʤ�š��ߣ����ܷ����򣬵����ڵڶ��࿼��֮��
	 �����ﵽ�����L�Ŀ���Ҳ���ܷ����򣬵����ڵ����࿼��֮��
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
//#include <iostream>
//using namespace std;

typedef struct {
	int id;
	int G;
	int T;
	int type;
}STU_INFO;

STU_INFO stu_info[100001];
STU_INFO stu_acc[100001];
int cnt = 0;

//����һ���Ƚ��� 
bool cmp(STU_INFO a, STU_INFO b)
{
    bool flag1 = (a.type < b.type);//���β�һ�������ñȷ��� 
    bool flag2 = (a.type == b.type) && (a.G + a.T) > (b.G + b.T);//ͬһ���Σ������ֲܷ�ͬ 
    bool flag3 = (a.type == b.type) && (a.G + a.T) == (b.G + b.T) && (a.G > b.G);//ͬһ���Σ��ܷ���ͬ�����ǵ�����ͬ 
    bool flag4 = (a.type == b.type) && (a.G + a.T) == (b.G + b.T) && (a.G == b.G) && (a.id < b.id);// //ͬһ���Σ��ܷ���ͬ������Ҳ��ͬ������ѧ����ǰ 
    return flag1 | flag2 | flag3 | flag4;
}

/*
//�����㷨 ����ƨ 
void add(int i){
	if(cnt == 0){//��¼ȡ����Ϊ0 
		stu_acc[cnt++] = stu_info[i];
	}else{//��¼ȡ��������0 
		for(int j = cnt-1;j>=0;j--){
			if(!cmp(stu_info[i],stu_acc[j])) {//�ҵ�һ���ɼ����Լ��ߵ� 
				if(j==cnt-1){//�Լ������һ�� 
					stu_acc[cnt++] = stu_info[i];
				}else{
					for(int l = cnt;l>j+1;l--){
						stu_acc[l] = stu_acc[l-1];
					}
					stu_acc[j+1] = stu_info[i];
					cnt++;	
				}
				break;
			}else if(j == 0){//�Լ��ǵ�һ�� 
				for(int l = cnt;l>0;l--){
					stu_acc[l] = stu_acc[l-1];
				}
				stu_acc[0] = stu_info[i];
				cnt++;
				break;
			} 
		} 
	} 
}

//ֱ�Ӳ������� 
void insertSort(STU_INFO *_stu_acc,int _cnt){
	for(int i = 1;i < _cnt;i++){
		STU_INFO key = _stu_acc[i];
		int j = i - 1;
		while(j>=0 && cmp(key,stu_acc[j])){
			_stu_acc[j+1] = _stu_acc[j];
			j--;
		}
		_stu_acc[j+1] = key;
	}
}*/

//���ֲ�������
void insertSort(STU_INFO *_stu_acc,int _cnt){
	for(int i = 1;i < _cnt;i++){
		STU_INFO key = _stu_acc[i];
		int left = 0;
		int right = i -1;
		while(left <= right){
			int mid = (left + right) / 2;
			if(!cmp(stu_acc[mid],key)){
				right = mid -1;
			}else{
				left = mid + 1;
			}
		}
		for(int j = i-1;j >= left; j--){
			_stu_acc[j+1] = _stu_acc[j]; 
		}
		_stu_acc[left] = key;
	} 
	
}
/*
//��������
void Swap(STU_INFO _stu_info[],int i,int j){
	STU_INFO temp = _stu_info[i];
	_stu_info[i] = _stu_info[j];
	_stu_info[j] = temp;
} 

//���ֺ������ҵ���ֵԪ�ص�λ�� 
int Partition(STU_INFO _stu_info[],int left,int right){
	STU_INFO pivot = _stu_info[right];//Ĭ��ѡ�����һ��Ԫ����Ϊ
							// ��������һ��Ϊ������ֵ 
	int tail = left - 1;
	for(int i = left;i < right; i++){
		if(!cmp(pivot,_stu_info[i])){//��Ԫ��С�ڵ��ڻ�׼Ԫ�ص�ֵ 
			Swap(_stu_info,++tail,i);
		}
	}
	Swap(_stu_info,tail + 1,right);
	
	return tail + 1; //���ػ�׼Ԫ�ص�λ�� 
}

void QuickSort(STU_INFO _stu_info[],int left,int right){
	if (left >= right){
		return;
	}
	int pivot_index = Partition(_stu_info,left,right);//�ø�����������׼Ԫ�ص�λ�� 
	QuickSort(_stu_info,left,pivot_index - 1);//�ݹ�ǰ���� 
	QuickSort(_stu_info,pivot_index + 1,right);//�ݹ����� 
}
*/


int main(){
	int n,l,h;
	//cin>>n>>l>>h;
	scanf("%d %d %d",&n,&l,&h);
	for(int i = 0;i<n;i++){
		//cin>>stu_info[i].id>>stu_info[i].G>>stu_info[i].T;
		scanf("%d %d %d",&stu_info[i].id,&stu_info[i].G,&stu_info[i].T);
	}

	for(int i = 0;i<n;i++){
		if(stu_info[i].G >= l && stu_info[i].T >= l){//���ʸ�¼ȡ 
			if(stu_info[i].G >= h && stu_info[i].T >= h){//�²�ȫ�� 
				stu_info[i].type = 1;
			}else if(stu_info[i].G >= h && stu_info[i].T < h){//��ʤ�� 
				stu_info[i].type = 2;
			}else if(stu_info[i].G < h && stu_info[i].T < h && stu_info[i].G > stu_info[i].T){//���ŵ¼����������С���ʤ�š���
				stu_info[i].type = 3;
			}else{ //�²ż��� 
				stu_info[i].type = 4;
			}
			stu_acc[cnt++] = stu_info[i];//����¼ȡ�� 
		}
	}

	//���������㷨
	insertSort(stu_acc,cnt); 
	//QuickSort(stu_acc,0,cnt-1);
	//cout <<cnt<<endl; 
	printf("%d\n",cnt);
	for(int i = 0;i < cnt;i++){
		//cout<<stu_acc[j].id<<' '<<stu_acc[j].G<<' ' <<stu_acc[j].T<<endl;
		printf("%d %d %d\n",stu_acc[i].id,stu_acc[i].G,stu_acc[i].T);
	}
	return 0; 
} 

/*
14 60 80
10000001 64 90
10000002 90 60
10000011 85 80
10000003 85 80
10000004 80 85
10000005 82 77
10000006 83 76
10000007 90 78
10000008 75 79
10000009 59 90
10000010 88 45
10000012 80 100
10000013 90 99
10000014 66 60
*/
 
  
