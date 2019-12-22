//

#include <cstdio>
#include <stdlib.h>
#include <iostream>
using namespace std;
int main(){
//	for(int i = 0;i < 127;i++){
//		printf("%c--",i);
//	}
	char name[5];
	int y,m,d;
	
	scanf("%s %d/%d/%d",name,&y,&m,&d);
	printf("%s %d/%d/%d\n",name,y,m,d);
	return 0;
} 

//
//#include <iostream>
//using namespace std;
//
//int main(){
//	for(int i = 0;i < 127;i++){
//		cout<<(char)i<<' ';
//	}
//	return 0;
//} 
