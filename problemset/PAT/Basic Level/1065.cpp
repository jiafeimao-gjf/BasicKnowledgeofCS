//1065 单身狗
/**
3
11111 22222
33333 44444
55555 66666
0
10
55555 44444 10000 88888 22222 11111 23333 54654 15651 88885
*/ 
#include <iostream>
#include <cstdio>
using namespace std;

typedef struct {
	int id;
	int isalone;
}PEOPLE;

void Merge(PEOPLE A[], int left, int mid, int right)// 合并两个已排好序的数组A[left...mid]和A[mid+1...right]
{
    int len = right - left + 1;
    PEOPLE *temp = new PEOPLE[len];       // 辅助空间O(n)
    int index = 0;
    int i = left;                   // 前一数组的起始元素
    int j = mid + 1;                // 后一数组的起始元素
    while (i <= mid && j <= right)
    {
        temp[index++] = A[i].id <= A[j].id ? A[i++] : A[j++];  // 带等号保证归并排序的稳定性
    }
    while (i <= mid)
    {
        temp[index++] = A[i++];
    }
    while (j <= right)
    {
        temp[index++] = A[j++];
    }
    for (int k = 0; k < len; k++)
    {
        A[left++] = temp[k];
    }
    delete temp;
}
void MergeSortIteration(PEOPLE A[], int len)    // 非递归(迭代)实现的归并排序(自底向上)
{
    int left, mid, right;// 子数组索引,前一个为A[left...mid]，后一个子数组为A[mid+1...right]
    for (int i = 1; i < len; i *= 2)        // 子数组的大小i初始为1，每轮翻倍
    {
        left = 0;
        while (left + i < len)              // 后一个子数组存在(需要归并)
        {
            mid = left + i - 1;
            right = mid + i < len ? mid + i : len - 1;// 后一个子数组大小可能不够
            Merge(A, left, mid, right);
            left = right + 1;               // 前一个子数组索引向后移动
        }
    }
}
//二分查找 
int getanother(int id,PEOPLE _peoples[],int i,int j){
	if(((i - j) == 1 || (j - i) == 1) && (_peoples[i].id != id && _peoples[j].id != id)){
		return -1; 
	}
	if(id > _peoples[(i+j)/2].id){
		return getanother(id,_peoples,(i+j)/2,j);
	}else if(id < _peoples[(i+j)/2].id){
		return getanother(id,_peoples,i,(i+j)/2);
	}else if(id == _peoples[(i+j)/2].id){
		return (i+j)/2;
	}
}

int main(){
	int m,n;
	int doubles[50001][2];
	PEOPLE peoples [10001];
	
	for(int i = 0;i < 10001; i++){
		peoples[i].isalone = 1;
	}
	scanf("%d",&n);
	for(int i = 0;i < n; i++){
		scanf("%d %d\n",&doubles[i][0],&doubles[i][1]);
	}
	scanf("%d",&m);
	for(int i = 0;i < m; i++){
		scanf("%d",&peoples[i].id);
	}
	
	if(m == 0){
		printf("0\n");
		return 0;
	}
	
	if(m != 0){
		//将前来排队的人按照id,从小到大排序
		MergeSortIteration(peoples,m);
	}

	if(n == 0 && m != 0){//一份结婚证都没有 
		printf("%d\n",m);
		for(int i = 0;i < m; i++){//全是光棍一条 
			printf("%05d",peoples[i].id);
			if(i != m-1) printf(" ");
		}
		printf("\n");
		return 0;
	}
	if(m != 0){//有人来参加宴会找老婆 
		int cnt = 0;
		for(int i = 0;i < m; i++){
			if(peoples[i].isalone){//此人为光棍 
				for(int j = 0;j < n; j++){//找结婚证去喽 
					if(peoples[i].id == doubles[j][0] || peoples[i].id == doubles[j][1]){//找到结婚证
						//换个地方再找另一半的住处
						int place = -2;
						if(peoples[i].id == doubles[j][0]){
							place = getanother(doubles[j][1],peoples,0,m-1);
						}else{
							place = getanother(doubles[j][0],peoples,0,m-1);
						}
						if(place != -1){
							//双宿双飞
							peoples[place].isalone = 0;
							peoples[i].isalone = 0;
							break;
						}else {
							cnt++;//找到一个光棍
						}
						break;//换下一个光棍找伴侣 
					}else if(j == n-1){//没有结婚证 
						//cout<<peoples[i].id<<" 没有结婚证"<<endl; 
						cnt++;//找到一个光棍 
					}
				}
			}
		}
		printf("%d\n",cnt);
		for (int i = 0;i < m;i++){
			if(peoples[i].isalone){//此人乃是光棍一条 
				printf("%05d",peoples[i].id);//报上名来 
				if(i != m-1) printf(" ");
			}
		}
		printf("\n");
	}
	return 0;
}
