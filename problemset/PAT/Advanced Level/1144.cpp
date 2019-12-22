#include <cstdio>
#include <set>
using namespace std;
//bool a[4294967296];
set<int> a;
int main(){
	int n;
	scanf("%d",&n);
	int num,max = -1;;
	for(int i = 0;i < n;i++){
		scanf("%d",&num);
		if(num >= 0){
			if(num > max) max = num;
//			a[num] = true;
			a.insert(num);
		}
	}
	int i = 1;
//	while(a[i] == true && i <= max) i++; 
	while(a.find(i) != a.end() && i <= max) i++; 
	printf("%d\n",i);
	return 0;
} 
