#include <iostream>
#include <cstring>
using namespace std;
int main(){
	char str[100001],breakkey[100];
	bool key[100];
	cin>>breakkey>>str;
	int len_str = strlen(str);
	int len = strlen(breakkey);
	for(int i = 0;i < 100;i++){
		key[i] = true; 
	}
	for(int i = 0;i < len;i++){
		if(breakkey[i] >='A'&&breakkey[i] <='Z'){
			key[breakkey[i]-32] = false;
			key[breakkey[i]] = false;
		}else{
			key[breakkey[i]-32] = false;
		}
	}
	
	for(int i = 0;i < len_str;i++){
		if(str[i] >='A'&&str[i] <='Z'){
			if(key[str[i]-32]&&key[11]){
				cout<<str[i];
			}
		}else{
			if(key[str[i]-32]){
				cout<<str[i];
			}
		}
	}
	//cout<<endl;
	return 0;
}
