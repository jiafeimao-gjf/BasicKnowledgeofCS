// 	1016	部分A+B (15)
#include <stdio.h>
#include <math.h> //求幂函数pow(x,y) 
int main(){
	char a[11],b[11];
	int Da,Db;
	long long Pa = 0,Pb = 0;
	scanf("%s %d %s %d",a,&Da,b,&Db);
	int i = 0,j = 0;
	while(a[i] != '\0'){
		if(a[i] - '0' == Da){
			Pa += Da*pow(10,j++);
		}
		i++;
	}
	//printf("%ld\n",Pa);
	i = 0;j = 0;
	while(b[i] != '\0'){
		if(b[i] - '0' == Db){
			Pb += Db*pow(10,j++);
		}
		i++;
	}
	//printf("%ld\n",Pb);
	printf("%ld\n",Pa + Pb);
	return 0;  
}
