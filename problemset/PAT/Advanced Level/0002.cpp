#include <cstdio>

int main(){
	double a[1001],b[1001],c[1001];
	int k;
	for(int i = 0;i < 1001;i++){
		a[i] = b[i] = c[i] = 0.0;
	}
	scanf("%d",&k);
	int exponent;
	double coefficient;
	for(int i = 0;i < k;i++){
		scanf("%d %lf",&exponent,&coefficient);
		a[exponent] = coefficient;
	}
	scanf("%d",&k);
	for(int i = 0;i < k;i++){
		scanf("%d %lf",&exponent,&coefficient);
		b[exponent] = coefficient;
	}
	
	
	int cnt = 0;
	for(int i = 0;i < 1001;i++){
		c[i] = a[i] + b[i];
		if(c[i] != 0.0){
			cnt++;
		}
	}
	printf("%d",cnt);
	for(int i = 1000;i >= 0;i--){
		if(c[i] != 0.0){
			printf(" %d %0.1f",i,c[i]);
		}
	}
	printf("\n");
	return 0;
} 
