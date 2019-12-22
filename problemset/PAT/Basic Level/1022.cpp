/*1022. D进制的A+B (20)

输入两个非负10进制整数A和B(<=2^30-1)，输出A+B的D (1 < D <= 10)进制数。

输入格式：

	输入在一行中依次给出3个整数A、B和D。

输出格式：

	输出A+B的D进制数。

//就是求一个10进制数转化成另一个进制的数字
	
*/
	
#include <stdio.h>

int main(){
	int a,b,c,k = 0;
	int number[31];number[0] = 0;
	scanf("%d %d %d",&a,&b,&c);
	if(c == 10){
		printf("%d\n",a+b);
	}else{
		int sum = a+b;
		for(int i = 0;sum != 0;i++){
			//printf("%d\n",sum);
			number[i] = sum%c;//c^i的系数 
			sum /= c;
			if(sum == 0){
				number[i+1] = '\0';	
				k = i;
			}
		}
		for(int i = k;i >= 0;i--){
			printf("%d",number[i]);
		}
		printf("\n");
	}

	return 0;
} 
