#include <stdio.h>//1031. 查验身份证(15)
#include <string.h>
int weight[17] = {7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2}; 
char M[11] = {'1','0','X','9','8','7','6','5','4','3','2'};
int main(){
	char id[19];
	int N;
	scanf("%d",&N);
	char notid[101][19];
	int k = 0;
	while(N--){ 
		scanf("%s",id);
		int sum = 0;
		for(int i = 0;i < 17;i++){
			if(id[i]<'0'|| id[i] >'9'){
				strcpy(notid[k++],id);
				break;
			}else{
				sum += weight[i]*(id[i] - '0');
			}
			if(i==16 && id[17] != M[sum%11]){
				strcpy(notid[k++],id);
			}
		}
	}
	if(k==0){
		printf("All passed\n");
	}else{
		for(int i = 0;i < k;i++){
			printf("%s\n",notid[i]);
		}
	}
	return 0;
} 
