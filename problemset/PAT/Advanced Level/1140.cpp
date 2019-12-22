#include <iostream>
//Sample Input:
//1 8
//Sample Output:
//1123123111
using namespace std;
int main(){
	int d,n;
	cin>>d>>n;
	int cnt = 0;
	string s = to_string(d);
	while(cnt < n - 1){
		//cout<<s<<endl;
		string ns;
		int i = 0;
		while(i < s.length()){
			int k = 1;
			for(int j = i + 1;j < s.length();j++){//统计第i个字符的个数 
				if(s[j] == s[i]) k++;
				else break;
			}
			ns += s[i];
			ns += to_string(k);
			i += k;
		}
		s = ns;
		cnt++;
	}
	cout<<s<<endl;
	return 0;
}
