//1007. �����Բ��� (20)
//������ע�����״̬����n = 1,2,3,4,5ʱ�ķ���ֵ 

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
		while(i <= n-2){//i��ֵ���Ϊn-2, ��Ϊnֻ��Ϊ�ڶ������� 
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
