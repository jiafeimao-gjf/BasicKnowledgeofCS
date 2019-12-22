#include <iostream>
#include <algorithm>
using namespace std;
int main(){
	int N,a[100001];
	cin>>N;
	for(int i = 0;i<N;i++){
		cin>>a[i];
	}
	sort(a,a + N);
	int s1 = 0,s2 = 0;
	for(int i = 0,j = N-1;i < N/2;i++,j--){
		s1 += a[i];
		s2 += a[j];
	}
	if(N%2==1){
		s2 += a[N/2];
	}
	cout<<N%2<<" "<<s2-s1<<endl;
	return 0;
}
