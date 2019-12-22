#include <iostream>
#include <string>
using namespace std;

int main(){
	string str[55];
	string stra = "SHCD";
	int cnt = 0,c = 0;
	string nums[13] = {"1","2","3","4","5","6","7","8","9","10","11","12","13"};
	for(int i = 1;i < 53;i++){
		str[i] = stra[c] + nums[cnt%13];
		cnt++;
		if(cnt%13==0) c++;
	}
	str[53] = "J1";str[54] = "J2";
	string nstr[55];
	int k = 0;
	scanf("%d",&k);
	int a[55];
	for(int i = 1;i < 55;i++){
		scanf("%d",&a[i]);
	} 
	for(int i = 0;i < k;i++){
		for(int j = 1;j < 55;j++){
			if(i%2==0) nstr[a[j]] = str[j];
			else str[a[j]] = nstr[j];
		}
	}
	for(int i = 1;i < 55;i++){
		if(k%2==1) cout<<nstr[i];
		else cout<<str[i];
		if(i!=54) printf(" ");
		else printf("\n");
	} 
	return 0;
} 
