//1015. 德才论 (25) 这道题一般方法的就题论题方法是完成不了的 

//这道题的本质是排序,采用插入排序 
 
 /*
 输入第1行给出3个正整数，分别为：
 		N（<=105），即考生总数；
 		L（>=60），为录取最低分数线，即德分和才分均不低于L的考生才有资格被考虑录取；
 		H（<100），为优先录取线——
	 德分和才分均不低于此线的被定义为“才德全尽”，此类考生按德才总分从高到低排序；
	 才分不到但德分到线的一类考生属于“德胜才”，也按总分排序，但排在第一类考生之后；
	 德才分均低于H，但是德分不低于才分的考生属于“才德兼亡”但尚有“德胜才”者，按总分排序，但排在第二类考生之后；
	 其他达到最低线L的考生也按总分排序，但排在第三类考生之后。
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

//构造一个比较器 
bool cmp(STU_INFO a, STU_INFO b)
{
    bool flag1 = (a.type < b.type);//批次不一样，不用比分数 
    bool flag2 = (a.type == b.type) && (a.G + a.T) > (b.G + b.T);//同一批次，但是总分不同 
    bool flag3 = (a.type == b.type) && (a.G + a.T) == (b.G + b.T) && (a.G > b.G);//同一批次，总分相同，但是德育不同 
    bool flag4 = (a.type == b.type) && (a.G + a.T) == (b.G + b.T) && (a.G == b.G) && (a.id < b.id);// //同一批次，总分相同，德育也相同，但是学号在前 
    return flag1 | flag2 | flag3 | flag4;
}

/*
//插入算法 ，狗屁 
void add(int i){
	if(cnt == 0){//已录取人数为0 
		stu_acc[cnt++] = stu_info[i];
	}else{//已录取人数大于0 
		for(int j = cnt-1;j>=0;j--){
			if(!cmp(stu_info[i],stu_acc[j])) {//找到一个成绩比自己高的 
				if(j==cnt-1){//自己是最后一名 
					stu_acc[cnt++] = stu_info[i];
				}else{
					for(int l = cnt;l>j+1;l--){
						stu_acc[l] = stu_acc[l-1];
					}
					stu_acc[j+1] = stu_info[i];
					cnt++;	
				}
				break;
			}else if(j == 0){//自己是第一名 
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

//直接插入排序 
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

//二分插入排序
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
//快速排序
void Swap(STU_INFO _stu_info[],int i,int j){
	STU_INFO temp = _stu_info[i];
	_stu_info[i] = _stu_info[j];
	_stu_info[j] = temp;
} 

//划分函数，找到中值元素的位置 
int Partition(STU_INFO _stu_info[],int left,int right){
	STU_INFO pivot = _stu_info[right];//默认选择最后一个元素作为
							// 将排序区一分为二的中值 
	int tail = left - 1;
	for(int i = left;i < right; i++){
		if(!cmp(pivot,_stu_info[i])){//该元素小于等于基准元素的值 
			Swap(_stu_info,++tail,i);
		}
	}
	Swap(_stu_info,tail + 1,right);
	
	return tail + 1; //返回基准元素的位置 
}

void QuickSort(STU_INFO _stu_info[],int left,int right){
	if (left >= right){
		return;
	}
	int pivot_index = Partition(_stu_info,left,right);//得该排序区到基准元素的位置 
	QuickSort(_stu_info,left,pivot_index - 1);//递归前半区 
	QuickSort(_stu_info,pivot_index + 1,right);//递归后半区 
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
		if(stu_info[i].G >= l && stu_info[i].T >= l){//有资格被录取 
			if(stu_info[i].G >= h && stu_info[i].T >= h){//德才全尽 
				stu_info[i].type = 1;
			}else if(stu_info[i].G >= h && stu_info[i].T < h){//德胜才 
				stu_info[i].type = 2;
			}else if(stu_info[i].G < h && stu_info[i].T < h && stu_info[i].G > stu_info[i].T){//“才德兼亡”但尚有“德胜才”者
				stu_info[i].type = 3;
			}else{ //德才兼亡 
				stu_info[i].type = 4;
			}
			stu_acc[cnt++] = stu_info[i];//放入录取池 
		}
	}

	//调用排序算法
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
 
  
