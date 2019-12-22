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
	map<char,bool> m;//char��һ�����ϣ����ظ�Ԫ�� 
	set<char> printed;
	char pre = '#';
	s = s + '#';
	for(int i = 0;i < s.length();i++){//�ҳ�û�л����ļ�
		if(s[i] ==  pre){//�����ǰ�ַ���ǰһ���ַ���� 
			cnt++;//���ַ����ִ�����һ 
		}else{//����� 
			if(cnt % k != 0){//����ַ����ִ����뻵���ļ����ִ�����һ�� 
				sureNoBroken[pre] = true;//�����û�л� 
			}
			cnt = 1;//�����ַ����ִ��� 
		}
		if(i != s.length() -1) //û�е����һ���ַ� 
			m[s[i]] = (cnt % k == 0);//��¼��i�����Ƿ��� 
		pre = s[i];//����ǰһ���� 
	}
	for(int i = 0;i < s.length() - 1;i++){//�ҳ������ļ� 
		if(sureNoBroken[s[i]] == true)
			m[s[i]] = false;
	} 
	
	for(int i = 0; i < s.length() - 1;i++){//��������ļ� 
		if(m[s[i]] && printed.find(s[i]) == printed.end()){//�ü�������û�б������� 
			printf("%c",s[i]);
			printed.insert(s[i]);
		}
	}
	printf("\n");
	for(int i = 0;i < s.length() -1;i++){//�����ȷ���ַ��� 
		printf("%c",s[i]);
		if(m[s[i]]) i = i + k - 1;//���������ļ� 
	}
	return 0;
}
