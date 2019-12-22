//1007. 素数对猜想 (20)
//此题需注意零界状态，当n = 1,2,3,4,5时的返回值 

#include <iostream>
#include <cmath>

using namespace std;

bool isPrime(int num){
	if(num == 1) return false;
	if(num == 2 || num == 3 || num == 5 || num == 7) return true;
	for(int i = 2;i<sqrt(num)+1;i++){
		if(num%i == 0) return false;
	}
	return true;
} 

int main(){
	int n;
	cin>>n;
	if(n<5){
		cout << 0;
		return 0;
	}else{
		int cnt = 0,i = 3;
		while(i <= n-2){//i的值最大为n-2, 因为n只能为第二个素数 
			if(isPrime(i) && isPrime(i+2)){
				//cout<<i<<' '<<i+2<<endl;
				cnt++;
			}
			i += 2;
		}
		cout<<cnt;
		return 0;	
	}
}
