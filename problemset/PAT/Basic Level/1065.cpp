//1065 ����
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

void Merge(PEOPLE A[], int left, int mid, int right)// �ϲ��������ź��������A[left...mid]��A[mid+1...right]
{
    int len = right - left + 1;
    PEOPLE *temp = new PEOPLE[len];       // �����ռ�O(n)
    int index = 0;
    int i = left;                   // ǰһ�������ʼԪ��
    int j = mid + 1;                // ��һ�������ʼԪ��
    while (i <= mid && j <= right)
    {
        temp[index++] = A[i].id <= A[j].id ? A[i++] : A[j++];  // ���Ⱥű�֤�鲢������ȶ���
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
void MergeSortIteration(PEOPLE A[], int len)    // �ǵݹ�(����)ʵ�ֵĹ鲢����(�Ե�����)
{
    int left, mid, right;// ����������,ǰһ��ΪA[left...mid]����һ��������ΪA[mid+1...right]
    for (int i = 1; i < len; i *= 2)        // ������Ĵ�Сi��ʼΪ1��ÿ�ַ���
    {
        left = 0;
        while (left + i < len)              // ��һ�����������(��Ҫ�鲢)
        {
            mid = left + i - 1;
            right = mid + i < len ? mid + i : len - 1;// ��һ���������С���ܲ���
            Merge(A, left, mid, right);
            left = right + 1;               // ǰһ����������������ƶ�
        }
    }
}
//���ֲ��� 
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
		//��ǰ���Ŷӵ��˰���id,��С��������
		MergeSortIteration(peoples,m);
	}

	if(n == 0 && m != 0){//һ�ݽ��֤��û�� 
		printf("%d\n",m);
		for(int i = 0;i < m; i++){//ȫ�ǹ��һ�� 
			printf("%05d",peoples[i].id);
			if(i != m-1) printf(" ");
		}
		printf("\n");
		return 0;
	}
	if(m != 0){//�������μ���������� 
		int cnt = 0;
		for(int i = 0;i < m; i++){
			if(peoples[i].isalone){//����Ϊ��� 
				for(int j = 0;j < n; j++){//�ҽ��֤ȥ� 
					if(peoples[i].id == doubles[j][0] || peoples[i].id == doubles[j][1]){//�ҵ����֤
						//�����ط�������һ���ס��
						int place = -2;
						if(peoples[i].id == doubles[j][0]){
							place = getanother(doubles[j][1],peoples,0,m-1);
						}else{
							place = getanother(doubles[j][0],peoples,0,m-1);
						}
						if(place != -1){
							//˫��˫��
							peoples[place].isalone = 0;
							peoples[i].isalone = 0;
							break;
						}else {
							cnt++;//�ҵ�һ�����
						}
						break;//����һ������Ұ��� 
					}else if(j == n-1){//û�н��֤ 
						//cout<<peoples[i].id<<" û�н��֤"<<endl; 
						cnt++;//�ҵ�һ����� 
					}
				}
			}
		}
		printf("%d\n",cnt);
		for (int i = 0;i < m;i++){
			if(peoples[i].isalone){//�������ǹ��һ�� 
				printf("%05d",peoples[i].id);//�������� 
				if(i != m-1) printf(" ");
			}
		}
		printf("\n");
	}
	return 0;
}
