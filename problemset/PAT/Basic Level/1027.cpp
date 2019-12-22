//1027 ´òÓ¡É³Â©
#include <stdio.h>
#include <math.h>

int main(){
	int N;
	char ch;
	scanf("%d %c",&N,&ch);
	
	if(N<7){
		printf("%c\n",ch);
		printf("%d",N-1);
		return 0;
	}
	int k = -1+(int)sqrt(4+2*(N-1))/2;
//	printf("%d ",k);
	
	int blank = 0;
	for(int i = k;i > 0 ;i--){
		for(int l = 0;l<blank;l++){
			printf(" ");
		}
		blank++;
		for(int j = 0;j < 2*i+1;j++){
			printf("%c",ch);		
		}
		printf("\n");
	}
	for(int l = 0;l<blank;l++){
			printf(" ");
	}
	blank--;
	printf("%c\n",ch);
	for(int i = 1;i <= k;i++){
		for(int l = 0;l<blank;l++){
			printf(" ");
		}
		blank--;
		for(int j = 0;j < 2*i+1;j++){
			printf("%c",ch);
		}
		printf("\n");
	}
	
	printf("%d",N-(2*k*k+4*k)-1);
	return 0;  
} 
