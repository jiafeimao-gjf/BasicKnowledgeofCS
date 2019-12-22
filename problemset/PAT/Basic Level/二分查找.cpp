#include <stdio.h>
int getanother(int id,int _peoples[],int i,int j){
	if(((i - j) == 1 || (j - i) == 1) && (_peoples[i] != id && _peoples[j] != id)){
		printf("没找到:%d %d\n",i,j);
		return -1; 
	}
	if(id > _peoples[(i+j)/2]){
		printf("上半区:%d %d\n",(i+j)/2,j);
		return getanother(id,_peoples,(i+j)/2,j);
	}else if(id < _peoples[(i+j)/2]){
		printf("下半区:%d %d\n",i,(i+j)/2);
		return getanother(id,_peoples,i,(i+j)/2);
	}else if(id == _peoples[(i+j)/2]){
		printf("找到了:%d\n",(i+j)/2);
		return (i+j)/2;
	}
}
int main(){
	int a[10] = {0,1,2,13,14,15,16,17,18,19} ;
	printf("%d",getanother(5,a,0,9));
	return 0;
} 
