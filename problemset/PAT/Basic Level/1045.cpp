#include <iostream>
using namespace std;

struct Elem{
	int val;
	bool isok;
	Elem(){
		val = 0;
		isok = true;
	}
};
Elem array[100000];
int mainkey[100000];

int main(){
	int N;
	cin>>N;
	for(int i = 0;i < N;i++){
		cin>>array[i].val;
	}
	int cnt = 0;
	for(int i = 0;i < N;i++){
		if(array[i].isok){
			for(int j = i+1;j < N;j++){
				if(array[i].val > array[j].val){
					array[i].isok = false;
					array[j].isok = false;
				}
			}
			if(array[i].isok){
				mainkey[cnt++] = array[i].val;
			}
		}
	}
	
	cout<<cnt<<endl;
	for(int i = 0;i < cnt;i++){
		if(i != 0) cout<<' ';
		cout<<mainkey[i];
	}
	cout<<endl;
	return 0;
}
