//1028 人口普查 

#include <stdio.h>
#include <string.h>
/*
10
hh 2014/9/7
John 2001/05/12
Tom 1814/09/06
Ann 2121/01/30
James 1814/09/05
Steve 1967/11/20
ee 2011/9/6
ss 2011/9/7
cvvc 2011/9/5
dd 2014/9/6
*/
int old[3] = {2014,9,7};
int young[3] = {1814,9,5};

int cmp(int y,int m,int d){
	if(y < 1814||(y == 1814 && m < 9)||(y == 1814 && m == 9 && d <= 5)){//1814/9/6以前 
		return 0;
	}
	if(y > 2014||(y == 2014 && m > 9)||(y == 2014 && m == 9 && d >= 7)){//2014/9/6以后 
		return 0;
	}
	if(old[0] > y||(y == old[0] && old[1]  > m)||(y == old[0] && m == old[1] && old[2] > d)){//大于最大值 
		old[0] = y;
		old[1] = m;
		old[2] = d;
		return 1;
	}
	if(young[0] < y||(y == young[0] && young[1] < m)||(y == young[0] && m == young[1] && young[2] < d)){  
		young[0] = y;
		young[1] = m;
		young[2] = d;
		return 2;
	}
	return 444;
}

int main(){
	int N;
	scanf("%d",&N);
	char older[6],younger[6];
	older[0] = younger[0] = '\0';
	char name[6];
	int y,m,d;
	int cnt = 0;
	for(int i = 0;i < N;i++){
		scanf("%s %d/%d/%d",name,&y,&m,&d);
		int res = cmp(y,m,d);
//		printf("res = %d\n",res);
		if(res){
			if(cnt == 0){
				old[0] = young[0] = y;
				old[1] = young[1] = m;
				old[2] = young[2] = d;
				strcpy(older,name);
				strcpy(younger,name);
			}
			cnt++;
			if(res == 1){
				strcpy(older,name);
			}
			if(res == 2){
				strcpy(younger,name);
			}
		}
//		printf("%d %s %s\n",cnt,older,younger);
//		printf("older:%s %d/%d/%d\n",older,old[0],old[1],old[2]);
//		printf("older:%s %d/%d/%d\n",younger,young[0],young[1],young[2]);
	}
	if(cnt >= 1){
		printf("%d %s %s\n",cnt,older,younger);	
	}else{
		printf("%d\n",cnt,older);
	}
	return 0;
} 
