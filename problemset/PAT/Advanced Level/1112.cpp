#include <iostream>
using namespace std;
int main(){
	int k;
	string str;
	cin>>k>>str;//kҪ�õ� 
	int chars[128];//��¼ÿ�����ĺá���������δ֪ 
	char chs[38];//�洢�����ļ� 
	int cnt = 0;//��¼�����ĸ��� 
	for(int i = 0;i < 128;i++){
		chars[i] = -1;//��ʼ��Ϊδ֪
	}
	int i = 0;
	while(i < str.length()){//����һ���ַ���
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
	chs[cnt] = '\0';//�����ַ�����β�� 
	cout<<chs<<endl;//�������
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
