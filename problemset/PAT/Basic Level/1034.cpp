#include <stdio.h>

int gcd(long long x,long long y){
	if(!x&&!y) return -1;
	if (!x || !y) return x > y ? x : y;
	for (long long t; t = x % y; x = y, y = t);
	return y;
}
long long a[3],b[3];
bool isp[3];
long long inum[3],k[3];

void print(int id){
	id = id - 1;
	if(a[id] == 0 && inum[id] == 0){
		printf("0");
	}else if(k[id] == -1){
		printf("Inf");
	}else if(a[id]%b[id] == 0){
		if(isp[id]){
			printf("%lld",inum[id]);	
		}else{
			printf("(-%lld)",inum[id]);
		}
	}else{
		if(isp[id] && inum[id] == 0){
			printf("%lld/%lld",a[id],b[id]);
		}
		if(isp[id] && inum[id] != 0){
			printf("%lld %lld/%lld",inum[id],a[id],b[id]);
		}
		if(!isp[id] && inum[id] == 0){
			printf("(-%lld/%lld)",a[id],b[id]);
		}
		if(!isp[id] && inum[id] != 0){
			printf("(-%lld %lld/%lld)",inum[id],a[id],b[id]);
		}
	}
}
void compute(int i){
	int fuhao = isp[0]^isp[1]?-1:1;
	int fuhao1 = isp[0]?1:-1;
	int fuhao2 = isp[1]?1:-1;
	switch(i){
		case 0:
			printf(" + ");
			a[2] = fuhao1*(a[0]+inum[0]*b[0])*b[1] + fuhao2*(a[1]+inum[1]*b[1])*b[0];
			b[2] = b[0]*b[1];
			break;
		case 1:
			printf(" - ");
			a[2] = fuhao1*(a[0]+inum[0]*b[0])*b[1] - fuhao2*(a[1]+inum[1]*b[1])*b[0];
			b[2] = b[0]*b[1];
			break;
		case 2:
			printf(" * ");
			a[2] = (a[0]+inum[0]*b[0]) * (a[1]+inum[1]*b[1]);
			b[2] = fuhao*b[0]*b[1];
			break;
		case 3:
			printf(" / ");
			a[2] = (a[0]+inum[0]*b[0]) * b[1];
			b[2] = fuhao*(a[1]+inum[1]*b[1]) * b[0];
			break;	
	}
}
int main(){
	
	scanf("%lld/%lld %lld/%lld",&a[0],&b[0],&a[1],&b[1]);

	for(int i = 0;i<2;++i){
		isp[i] = (a[i]*b[i]>=0?true:false);
		a[i] = a[i]>=0?a[i]:-a[i];
		b[i] = b[i]>=0?b[i]:-b[i];
		k[i] = gcd(a[i],b[i]);
		inum[i] = a[i]/b[i];
		b[i] /= k[i];a[i] = a[i]/k[i] - inum[i]*b[i];
	}
	
	for(int i = 0;i < 4;++i){
		print(1);
		compute(i);
		print(2);
		
		isp[2] = (a[2]*b[2]>= 0?true:false);
		a[2] = a[2]>=0?a[2]:-a[2];
		b[2] = b[2]>=0?b[2]:-b[2];

		if(b[2]!=0){
			k[2] = gcd(a[2],b[2]);
			inum[2] = a[2]/b[2];
			b[2] /= k[2];a[2] = a[2]/k[2] - inum[2]*b[2];
			printf(" = ");
			print(3);
			printf("\n");
		}else{
			printf(" = Inf\n");
		}
	}
	return 0;
} 
