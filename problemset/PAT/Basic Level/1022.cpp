/*1022. D���Ƶ�A+B (20)

���������Ǹ�10��������A��B(<=2^30-1)�����A+B��D (1 < D <= 10)��������

�����ʽ��

	������һ�������θ���3������A��B��D��

�����ʽ��

	���A+B��D��������

//������һ��10������ת������һ�����Ƶ�����
	
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
			number[i] = sum%c;//c^i��ϵ�� 
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
