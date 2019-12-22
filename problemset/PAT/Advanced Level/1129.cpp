#include <stdio.h>
//12 2
//3 5 7 5 5 3 2 1 8 3 8 12
int main(){
	int N,K;
	int a[50001];
	int freq[50001]; 
	scanf("%d %d",&N,&K);
	for(int i = 0;i < N;i++){
		scanf("%d",&a[i]);
		freq[i]=0;	
	}
	int order[11] = {0,0,0,0,0,0,0,0,0,0,0};
	int c = 1;
	order[0] = a[0];
	freq[order[0]]++;
	for(int i = 1;i < N;i++){
		printf("%d:",a[i]);
		 for(int l = 0;l < c;l++){
		 	printf(" %d",order[l]);
		 	if(l==c-1){
		 		printf("\n");
		 	}
		 }
		 freq[a[i]]++;
		 int isexit = -1;
		 for(int j = 0;j < c;j++){
		 	if(order[j]==a[i]){
		 		isexit = j;
		 		break;
		 	}
		 	if(j == c - 1 && c < K + 1){
		 		if(c < K){
		 			c++;
					order[c - 1] = a[i];
		 		}
				if(j == K - 1){
					if(freq[order[j]] == freq[a[i]] && order[j] > a[i]){
						order[c - 1] = a[i];	
					}
					if(freq[order[j]] < freq[a[i]]){
						order[c - 1] = a[i];
					}
		 		}
		 	}
		 }
		 while(isexit > 0){
	 		if(freq[order[isexit-1]] <= freq[order[isexit]] && freq[order[isexit]] > 1){
	 			int t = order[isexit-1];
	 			order[isexit-1] = order[isexit];
	 			order[isexit] = t;
	 		}
	 		isexit--;
		 }
	}
	return 0;
} 
