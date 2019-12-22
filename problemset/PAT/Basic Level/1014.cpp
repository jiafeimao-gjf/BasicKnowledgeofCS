//1014. 福尔摩斯的约会 (20)

//本体需要对ASCII码较为熟悉 A = 65 0 = 48 a = 81,A-Z和a-z不是连在一起的 
/*
第4个字母'D'，代表星期四；
第2对相同的字符是'E'，那是第5个英文字母，代表一天里的第14个钟头（于是一天的0点到23点由数字0到9、以及大写字母A到N表示）；
后面两字符串第1对相同的英文字母's'出现在第4个位置（从0开始计数）上，代表第4分钟。
现给定两对字符串，请帮助福尔摩斯解码得到约会的时间
*/

//四个字符串数组。 
//逐个字符匹配。 
//匹配成功就匹配下一个
//注意 字符与结果的转换

#include <iostream>

using namespace std;

int main(){
	char week_str1[61];
	char week_str2[61];
	char time_str1[61];
	char time_str2[61];
	
	string weeks[7] = {"MON","TUE","WED","THU","FRI","SAT","SUN"};
	cin>>week_str1>>week_str2>>time_str1>>time_str2;
	char week_char,hour_char;
	bool isgetweek = false;
	for(int i = 0;week_str1[i] != '\0' && week_str1!='\0';++i){
		if(!isgetweek && week_str2[i] == week_str1[i] && week_str1[i]>='A' && week_str1[i] <= 'G'){
			cout<<weeks[week_str2[i] - 'A']<<' ';
			isgetweek = true;
		}else if(isgetweek && week_str2[i] == week_str1[i] && //这里else if和if的差别很大 ，编程细节把握 
		((week_str1[i]>='A' && week_str1[i] <= 'N') || (week_str1[i]>='0' && week_str1[i] <= '9'))){
			if(week_str1[i]>='0' && week_str1[i] <= '9'){
				cout<<0<<week_str2[i] - '0'<<':';//不需要+1，因为我们要显示 00 - 09
			}else if(week_str1[i]>='A' && week_str1[i] <= 'N'){
				cout<<week_str2[i] - 'A' + 10<<':';	//需要+10，因为我们要显示 10 - 23
			}
			break;
		}
	}
	
	for(int i = 0;time_str1[i] != '\0'&&time_str2[i] != '\0';i++){
		if(time_str2[i] == time_str1[i] && 
		((time_str1[i] >= 'A'  && week_str1[i] <= 'Z') || (time_str1[i]>='a' && time_str1[i]<='z'))){
			if(i<=9) cout<<0<<i<<endl;
			else cout<<i<<endl;
			break;
		}
	}
	
	return 0;
}
//代码要简洁
//代码结构要清晰 

/*
3485djDkxh4hhGE
2984akDfkkkkggEdsb
s&hgsfdk
d&Hyscvnm
*/
