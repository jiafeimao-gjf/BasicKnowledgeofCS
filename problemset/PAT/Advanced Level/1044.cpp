#include <cstdio>
#include <vector>
using namespace std;

int main(){
	int n,total,cnt;
	vector<int> a;
	int b[1000][3];
	int min = 100000000;
	bool isNoSolution = false;
	scanf("%d %d",&n,&total);
	a.resize(n);
	for(int i = 0;i < n;i++){
		scanf("%d",&a[i]);
	}
	for(int i = 0;i < n;i++){
		int sum = 0;
		for(int j = i;j < n;j++){
			sum += a[j];
			if(sum == total){
				printf("%d-%d\n",i+1,j+1);
				isNoSolution = true;
				break;
			}
			if(sum > total && !isNoSolution){
				if(sum - total < min){
					cnt = 0;
					min = sum - total;
					b[cnt][0] = i;
					b[cnt][1] = j;
					b[cnt][3] = min;	
					break;
				}
				if(sum - total == min){
					cnt++;
					min = sum - total;
					b[cnt][0] = i;
					b[cnt][1] = j;
					b[cnt][3] = min;	
					break;
				}
			}
		}
	}
	if(!isNoSolution){
		for(int i = 0;i <= cnt;i++){
			printf("%d-%d\n",b[i][0]+1,b[i][1]+1);
		}
	}
	return 0;
}
