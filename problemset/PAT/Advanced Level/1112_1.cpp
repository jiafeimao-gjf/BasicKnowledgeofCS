#include  <iostream>
#include <map>
#include <set>
#include <cstdio>

using namespace std;

bool sureNoBroken[256];
int main(){
	int k,cnt = 1;
	scanf("%d",&k);
	string s;
	cin>>s;
	map<char,bool> m;//char是一个集合，无重复元素 
	set<char> printed;
	char pre = '#';
	s = s + '#';
	for(int i = 0;i < s.length();i++){//找出没有坏掉的键
		if(s[i] ==  pre){//如果当前字符与前一个字符相等 
			cnt++;//该字符出现次数加一 
		}else{//不相等 
			if(cnt % k != 0){//这个字符出现次数与坏掉的键出现次数不一样 
				sureNoBroken[pre] = true;//这个键没有坏 
			}
			cnt = 1;//重置字符出现次数 
		}
		if(i != s.length() -1) //没有到最后一个字符 
			m[s[i]] = (cnt % k == 0);//记录第i个键是否损坏 
		pre = s[i];//根新前一个键 
	}
	for(int i = 0;i < s.length() - 1;i++){//找出坏掉的键 
		if(sureNoBroken[s[i]] == true)
			m[s[i]] = false;
	} 
	
	for(int i = 0; i < s.length() - 1;i++){//输出坏掉的键 
		if(m[s[i]] && printed.find(s[i]) == printed.end()){//该键坏了且没有保存下来 
			printf("%c",s[i]);
			printed.insert(s[i]);
		}
	}
	printf("\n");
	for(int i = 0;i < s.length() -1;i++){//输出正确的字符串 
		printf("%c",s[i]);
		if(m[s[i]]) i = i + k - 1;//跳过坏掉的键 
	}
	return 0;
}
