//	害死人不偿命的(3n+1)猜想 
#include <iostream>

using namespace std;

int main(){
	int a,k;//,t
	int t;
	cin>>t;
	while(t--){
	cin>>a;k=0;
	while(a != 1){
		if (a%2==0) {
			a=a/2;
			cout<<a<<' '; 
			k++;
		}else {
			a = 3 * a + 1;
			a = a/2;
			cout<<a<<' ';
			k++;
		}
	}
	cout<<endl;
	cout << k <<endl;
	}
	return 0;
}
