//1017. A除以B (20),模拟除法运算 ,要考虑除法的细节 

/*
会出现的情况：
	1、一位不够除，两位肯定够吗？
	2、出现连续的0，怎么办？
	3、对于这种情况1/5
*/ 

#include <stdio.h>

int main(){
	char a[1001];
	char q[1001];
	int b;
	scanf("%s %d",a,&b);
	int temp_r = 0;
	if(b == 1){
		printf("%s %d",a,0);
		return 0;
	}
	if(a[0] == '0'){
		printf("%d %d",0,0);
		return 0;
	}
	if(a[1] == '\0'){
		printf("%d %d",(a[0]-'0')/b,(a[0]-'0')%b);
		return 0;
	}
	for(int i = 0,j = 0;a[i] != '\0';i++){
		int m = a[i] - '0';
		if((m + temp_r*10) == 0){//如果该位和上次的余数和为0，则商为0 
			q[j++] = '0';//商增加一位0 
		}else if((m + temp_r*10) >= b){//该位数字大于等于除数 
			q[j++] = (m + temp_r*10) / b + '0';//记录该位的商，加上上次的余数
			//printf("m + temp_r*10 = %d\n",m + temp_r*10); 
			temp_r = (m + temp_r*10) % b;//更新余数
		}else{//该位数小于除数b，但是大于0 ,此时temp_r肯定为0 
			if(j > 0) {//如果不是第一位商 
				q[j++] = '0';//商增加一位0 
			}
			if(a[i+1] != '\0'){//下一位还有数字
				int n = a[i+1] - '0';i++;
				q[j++] = (m*10 + n)/b + '0';//将两位合在一起
				//printf("m*10 + n = %d\n",m*10 + n); 
				temp_r = (m*10 + n)%b ;//更新余数 
			}else{//下一位没有数字了 
				temp_r = m;
			}
		}
		if(a[i+1] == '\0'){//如果下一位没有数字了 
			q[j] = '\0';//给商字符串添加终结符 
		}
	}
	printf("%s %d\n",q,temp_r);
	return 0;
}
