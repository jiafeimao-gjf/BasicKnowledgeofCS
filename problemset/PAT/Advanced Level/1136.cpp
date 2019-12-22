#include <iostream>
#include <algorithm>
using namespace std;
string add(string str,string nstr){//用字符串表示的大整数加法 
	string res = "";
	int acc = 0;
	for(int i = 0;i < str.length();i++){
		int r = str[i] - '0' + nstr[i] - '0' + acc;
		acc = 0;
		if(r >= 10){
			acc = 1;
			r -= 10;
		}
		res += r + '0';
	}
	if(acc == 1) res += acc + '0';
	reverse(res.begin(),res.end());
	return res;
}
int main(){
	string str;
	cin>>str;
	int cnt = 0;
	while(cnt < 10){
		string nstr = str;
		reverse(str.begin(),str.end());
		if(str == nstr){
			cout<<str<<" is a palindromic number."<<endl;
			break;
		}else{
			string res = add(str,nstr);
			cout<<nstr<<" + "<<str<<" = "<<res<<endl;
			str = res;
			cnt++;
		}
	}
	if(cnt == 10){
		cout<<"Not found in 10 iterations."<<endl;
	}
	return 0;
} 
