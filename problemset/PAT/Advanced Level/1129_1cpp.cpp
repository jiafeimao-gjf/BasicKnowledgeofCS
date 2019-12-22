#include <cstdio>
#include <set>//集合类，具有集合特征，可排序 
using namespace std;
int book[50001];//记录元素的频率 
struct node{//元素的结构体 
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
			for(set<node>::iterator it = s.begin();tempCnt < k && it != s.end();it++){//输出前K个元素 
				printf(" %d",it->value);
				tempCnt++;
			}
			printf("\n");
		}
		//更新元素的频率属性 
		set<node>::iterator it = s.find(node(num,book[num]));
		if(it != s.end()) s.erase(it);
		book[num]++;
		s.insert(node(num,book[num]));
	}
	return 0;
} 
