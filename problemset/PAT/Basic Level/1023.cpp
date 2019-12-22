//1023. 组个最小数 (20)
#include <stdio.h>

int main(){
	int nums[10];
	int n,k=0;
	while(k<10){
		scanf("%d",&nums[k++]); 
	}
	if(nums[0]>0){
		for(int i = 1;i < k;i++){
			if(nums[i] > 0){
				nums[i]--;
				printf("%d",i);
				break;
			}
		}
	}
	for(int i = 0;i < k;i++){
		if(nums[i] > 0){
			for(int j = 0;j < nums[i];j++){
				 printf("%d",i);
			}
		}
	}
	printf("\n");
	return 0;
}
