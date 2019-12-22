#include <iostream>
#include <cstring>
 
using namespace std;
char str[100001];
int indexP[100001];
int indexA[100001];
int indexT[100001];
int main(){
	cin>>str;
	int len = strlen(str);
	int cnt[3] = {0};
	for(int i = 0;i < len;i++){
		if(str[i] == 'P'){
			indexP[cnt[0]++] = i;
		}else if(str[i] == 'A'){
			indexA[cnt[1]++] = i;
		}else{
			indexT[cnt[2]++] = i;
		}
	}
	//cout<<"P:"<<cnt[0]<<",A:"<<cnt[1]<<",T:"<<cnt[2]<<endl;
	
	long long sum = 0;
	int *cntAT = new int[cnt[1]];
	for(int j = 0;j < cnt[1];j++){
		for(int k = 0;k < cnt[2];k++){//统计第j个A后面有多少个T
			if(indexT[k] > indexA[j]){
				cntAT[j] = cnt[2] - k;
				break;
			}
		}
		sum += cntAT[j];
	}
	for(int i = 0;i < cnt[0];i++){
	}
	cout<< sum%1000000007 <<endl;
	return 0;
}
