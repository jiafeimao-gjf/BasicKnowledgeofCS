//1013. 数素数 (20)
//对区间内的素数进行一一判断即可
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
				i++;//该行 输出元素个数+1 
				if(i == 10){//输出了10个数据 
					i = 0;//回车 
					cout<<endl;//换行 
				}else if(i>0){//没有输出到10个元素 
					if(k<n){//若不是最后一个数字输出一个空格 
						cout<<' ';//输出空格 ; 
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

