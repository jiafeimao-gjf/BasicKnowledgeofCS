#include <cstdio>
#include <set>//�����࣬���м��������������� 
using namespace std;
int book[50001];//��¼Ԫ�ص�Ƶ�� 
struct node{//Ԫ�صĽṹ�� 
	int value,cnt;
	node(int a,int b):value(a),cnt(b){}
	bool operator < (const node &a) const {
		return (cnt != a.cnt)? cnt > a.cnt:value < a.value;
	}
};
int main(){
	int n,k,num;
	scanf("%d %d",&n,&k);
	set<node> s;
	for(int i = 0;i < n;i++){
		scanf("%d",&num);
		if(i!=0){
			printf("%d:",num);
			int tempCnt = 0;
			for(set<node>::iterator it = s.begin();tempCnt < k && it != s.end();it++){//���ǰK��Ԫ�� 
				printf(" %d",it->value);
				tempCnt++;
			}
			printf("\n");
		}
		//����Ԫ�ص�Ƶ������ 
		set<node>::iterator it = s.find(node(num,book[num]));
		if(it != s.end()) s.erase(it);
		book[num]++;
		s.insert(node(num,book[num]));
	}
	return 0;
} 
