//1009. 说反话 (20)

//该题说明，如果能直接处理原始数据并得到答案，就直接处理
//字符串截断输出要用指针形式表示，否则只能输出一个字符 
#include <iostream>
#include <cstring>
using namespace std;

int main(){
	char str[81];
	cin.get(str,81);
	int i = strlen(str)-1;
	while (i != 0){//字符串未结束 
		while(str[i] != ' ' && i != 0){//一个单词未结束 
			i--;
		}
		if(i != 0){//一个单词结束了但是字符串没有结尾 
			cout<<(str + i + 1)<<' ';//不能写str[i+1],因为cout<<str[i+1];是输出一个字符的意思 
		}else{
			break;//字符串结束 
		}
		str[i] = '\0';//为下一个单词添加终结符
	}
	cout<<str;
	return 0;
}
