//1029 ¾É¼üÅÌ 

#include <stdio.h>
#include <string.h>
int main(){
	char should[81];
	char fact[81];
	scanf("%s\n%s",should,fact);
	int len_s = strlen(should);
	int len_f = strlen(fact);
	char badkey[80];badkey[0] = '\0';
	int cnt = 0;
	int l = 0;
	for(int i = 0;i < len_s;i++){
//		printf("i=%d\n",i);
		if(should[i] != fact[l]){
			should[i] = should[i]>='a'?should[i]-32:should[i];
			if(cnt>0){
				for(int j = 0;j < cnt;j++){
					if(badkey[j] == should[i]){
						break;
					}else if(j == cnt-1){
						badkey[cnt++] = should[i];
//						printf("cnt++\n");
					}
				}	
			}else{//cnt == 0
				badkey[cnt++] = should[i];
//				printf("cnt++\n");
			}	
		}else{
			l++;
		}
	}
	badkey[cnt] = '\0';
	printf("%s\n",badkey);
	return 0;
} 
