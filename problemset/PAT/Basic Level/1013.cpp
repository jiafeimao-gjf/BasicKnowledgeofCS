//1013. ������ (20)
//�������ڵ���������һһ�жϼ���
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
	int m,n;
	cin>>m>>n;
	int i = 0,k = 0,l = 2;
	while(k <= n){
		if(isPrime(l)){
			k++;
			if(k<=n&&k>=m){
				cout<<l;
				i++;//���� ���Ԫ�ظ���+1 
				if(i == 10){//�����10������ 
					i = 0;//�س� 
					cout<<endl;//���� 
				}else if(i>0){//û�������10��Ԫ�� 
					if(k<n){//���������һ���������һ���ո� 
						cout<<' ';//����ո� ; 
					}
				}
			}
		}
		if(l%2 != 0){
			l += 2;
		}else{
			l++;
		}
	}
	return 0;
}

