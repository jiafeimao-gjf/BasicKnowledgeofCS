// 1003. 我要通过！(20)

/*
这道题要分析一波： 
1. 字符串中必须仅有P, A, T这三种字符，不可以包含其它字符；
	-->字符串长度至少为3 
2. 任意形如 xPATx 的字符串都可以获得“答案正确”，其中 x 或者是空字符串，或者是仅由字母 A 组成的字符串；
	-->PAT两段连接的A的数量一定相等 
3. 如果 aPbTc 是正确的，那么 aPbATca 也是正确的，其中 a, b, c 均或者是空字符串，或者是仅由字母 A 组成的字符串
	-->这里b=A，a=c,所以aPATa=>aPAATaa => aP * 2 = Ta 
	
	综上：该字符串的正则表达式为：xPyTxx ，其中x,y是由字母'A'组成的串 ，满足y至少由一个A组成 （A）P(A)*T(A) 
	
	经验总结：关于字符串匹配的题，一定要弄出该字符串匹配的正则表达式 
*/

#include <iostream>
#include <string>

using namespace std;

/* 由于理解字符串的特点出错，而学错了程序 
bool match_string(string str){
	if(str[1] == '\0' || str[2] == '\0'){
		////cout<<"//字符串长度最短为3 " <<endl;
		return false;
	} 
	int i = 0;
	bool is_match = false;//标志PAT或者PAAT是否检测过 
	while(str[i] != '\0'){
		if(str[i] == 'A'){//该子母为A,继续 
			////cout<<"//该子母为A,继续 " <<endl;
			i++;
		}else if(str[i] == 'P'){//该子母为P,匹配PAT或者PAAT
			//cout<<"//该子母为P,匹配PAT或者PAAT" <<endl;
			if(!is_match){//PAT或者PAAT没有匹配过 
				//cout<<"//PAT或者PAAT没有匹配过 " <<endl;
				if(str[i+1] != '\0' && str[i+2] != '\0'){//字符串还没结束
					//cout<<"//符串还没结束2 " <<endl;
					if(str[i+1] == 'A' && str[i+2] == 'T'){//匹配AT 
						//cout<<"//匹配AT成功 " <<endl;
						i = i + 3;
						is_match = true;
					}else if(str[i+2] != 'A'){//匹配AA 
						//cout<<"//该匹配AA失败 " <<endl;
						return false;
					}
				}
				if(!is_match && str[i+1] != '\0' && str[i+2] != '\0' && str[i+3] != '\0'){
					//cout<<"//符串还没结束3 " <<endl;
					if(str[i+3] == 'T'){//匹配AAT 
						//cout<<"//匹配AAT成功" <<endl;
						i = i + 4;
						is_match = true;
					}else{
						//cout<<"//匹配AAT失败" <<endl;
						return false;
					}
				}	
			}else{//匹配过PAT或者PAAT，P字母不对 
				//cout<<"//匹配过PAT或者PAAT，P字母不对 " <<endl;
				return false;
			} 
		}else{
			//cout<<"//匹配到除A、P的其他字母 " <<endl;
			return false;
		} 
	}
	return true;
}
*/
bool match_string(string str){
	if(str[1] == '\0' || str[2] == '\0'){
		////cout<<"//字符串长度最短为3 " <<endl;
		return false;
	} 
	int cnt[3] = {0,0,0};//统计三个位置A的个数
	int i = 0;
	while(str[i] == 'A'){//统计P之前A的个数 
		cnt[0]++;
		i++;
	}
	if(str[i] == 'P'){
		i++;
		while(str[i] == 'A'){//统计P和T之间的A的个数 
			cnt[1]++;
			i++;
		}
		if(str[i] != 'T' || cnt[1] == 0){
			return false;
		}else{
			i++;
			while(str[i] == 'A'){//统计T之后的A的个数 
				cnt[2]++;
				i++;
			}
			if(str[i] != '\0'){
				return false;
			}
		}
	}else{
		return false;
	}
	if(cnt[2] == cnt[0]*cnt[1]){
		return true;
	}else{
		return false;
	}
} 
int main(){
	int t;
	cin >> t;
	string str;
	while(t--){
		cin >> str;
		if(match_string(str)){
			cout<<"YES"<<endl;
		}else{
			cout<<"NO"<<endl;
		}
	}
	return 0;
}
