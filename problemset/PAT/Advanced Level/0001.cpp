#include <iostream> 
#include <cstdio>
#include <stack>
#include <cmath>
using namespace std;
int main(){
	int a,b;
	scanf("%d %d",&a,&b);
	int c = a + b;
	if(c==0){
		printf("%d\n",c);
		return 0;
	} 
	if(c < 0){
		printf("-");
		c = abs(c);
	}
	stack<int> inter;
	int cnt = 0;
	while(c > 0){
		inter.push(c % 10);
		cnt++;
		c /= 10;
		if(cnt%3==0 && c!=0) inter.push(-1);
	}
	while(!inter.empty()){
		if(inter.top() != -1){
			printf("%d",inter.top());
			inter.pop();
		}else{
			printf(",");
			inter.pop();
		}
	}
	printf("\n");	
	return 0;
}
