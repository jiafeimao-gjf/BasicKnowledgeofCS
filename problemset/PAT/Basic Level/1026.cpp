//1026 Ê±¼ä×ª»» 
#include <stdio.h>

int main(){
	int c1,c2;
	scanf("%d %d",&c1,&c2);
	int times = c2-c1+1;
	int hh,mm,ss;
	hh=mm=ss=0;
	if(times%100>=50){
		times = times/100+1;
	}else{
		times = times/100;
	}
	
	ss = times%60;
	times = times/60;
	mm = times%60;
	times = times/60;
	hh = times;
	
	printf("%02d:%02d:%02d",hh,mm,ss);
	 
	return 0;
} 
