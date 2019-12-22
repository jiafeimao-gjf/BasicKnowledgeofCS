#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
int main(){
	int n,p,num,min,max;
	vector<int> arr;
	scanf("%d%d",&n,&p);
	while(n--){
		scanf("%d",&num);
		arr.push_back(num);
	}
	sort(arr.begin(),arr.end());
	min = arr[0],max = arr[arr.size()-1];
	if(max <= min * p){
		printf("%d\n",arr.size());
	}else{
		int cnt1,cnt2;
		for(int i = arr.size() - 1;i >= 0;i--){
			if(arr[i] <= min * p){
				cnt1 = i + 1;
				break;
			}
		}
		for(int i = 0;i < arr.size();i++){
			if(arr[i] * p >= max){
				cnt2 = arr.size() - i;
				break;
			}
		}
		printf("%d\n",cnt1>=cnt2?cnt1:cnt2);
	}
	return 0;
} 
