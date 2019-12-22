#include <cstdio>
#include <iostream>
using namespace std;
//大整数回文数判断
int p(int n){
	if(n < 10) return n;
	string num = "";
	int t = n;
	while(t != 0){
		num += (t % 10) + '0';
		t /= 10;
	}
	n = 0;
	for(int i = 0;i < num.length();i++){
		n *= 10; 
		if(num[i] != '0') n += (num[i] - '0');
	}
	return n; 
} 
int main(){
	int n;
	bool isFound = false;
	scanf("%d",&n);
	for(int i = 0;i < 10;i++){
		int m = p(n);
		if(n == m){
			isFound = true;
			printf("%d is a palindromic number.\n",n);
			break;
		}else{
			int nn = n + m;
			printf("%d + %d = %d\n",n,m,nn);
			n = nn;
		}
	}
	if(!isFound){
		printf("Not found in 10 iterations.\n");
	}
	return 0;
}
