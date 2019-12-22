#include <iostream>
using namespace std;
int main(){
	int k;
	string str;
	cin>>k>>str;//k要用滴 
	int chars[128];//记录每个键的好、坏、还是未知 
	char chs[38];//存储坏掉的键 
	int cnt = 0;//记录坏键的个数 
	for(int i = 0;i < 128;i++){
		chars[i] = -1;//初始化为未知
	}
	int i = 0;
	while(i < str.length()){//遍历一趟字符串
		if(chars[str[i]] == 1){
			i++;
		}else if(chars[str[i]] == 0){
			i += k;
		}else if(chars[str[i]] == -1){
			if(i+k > str.length()){
				for(int j = i;j < str.length();j++){
					chars[str[j]] = 1;
				}
			}else{
				for(int j = i + 1;j < i + k;j++){
					if(str[i] != str[j]){
						chars[str[i]] = 1;
						break;
					}else if(j == i + k - 1){
						chars[str[i]] = 0;
						chs[cnt++] = str[i];
					}
				}
			}
		}
	}
	chs[cnt] = '\0';//加上字符串结尾符 
	cout<<chs<<endl;//输出坏键
	for(int i = 0;i<str.length();i++){
		if(chars[str[i]] == 1){
			cout<<str[i];
		}else{
			cout<<str[i];
			i += k-1;
		}
	}
	cout<<endl;
	return 0;
}
