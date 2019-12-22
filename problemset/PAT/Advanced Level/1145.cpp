#include <cstdio>
#include <vector>
#include <sys/timeb.h>
using namespace std;
bool isprime(int a){
	bool isp = true;
	for(int i = 2;i*i-1 <= a;i++){
		if(a % i == 0){
			isp = false;
			break;
		}
	}
	return isp;
}
int main(){
	int msize,n,m,num,cnt = 0;
	scanf("%d %d %d",&msize,&n,&m);
	if(!isprime(msize)){
		int i = msize + 1;
		while(!isprime(i)) i++;
		msize = i;
	}
	vector<int> hash;
	hash.resize(msize);
	for(int i;i < n;i++){
		scanf("%d",&num);
		if(hash[num%msize] == 0){
			hash[num%msize] = num;
			cnt++;
		}else if(cnt < msize && num % msize != 0){
			int j = 1;
			while(hash[hash[num % msize] + j * j] != 0) j++;
			hash[num % msize + j * j] = num;
			cnt++;
		}else{
			printf("%d cannot be inserted.\n",num);
		}
	}
	int key;
	timeb t1;
	for(int i = 0;i < m;i++){
		scanf("%d",&key);
		if(hash[key%msize] == key){
			continue;
		}else if(key%msize != 0){
			int cnt = 0,j = 1;
			while(cnt < msize && hash[hash[key%msize] + j * j] != key){
				j++;
				cnt++;
			}
			continue;
		}else{
			continue;
		}
		
	} 
	timeb t2;
	printf("%.1f",t2.time/1000 - t1.time/1000);
	return 0;
}
