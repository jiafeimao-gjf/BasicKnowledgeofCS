// 1003. ��Ҫͨ����(20)

/*
�����Ҫ����һ���� 
1. �ַ����б������P, A, T�������ַ��������԰��������ַ���
	-->�ַ�����������Ϊ3 
2. �������� xPATx ���ַ��������Ի�á�����ȷ�������� x �����ǿ��ַ����������ǽ�����ĸ A ��ɵ��ַ�����
	-->PAT�������ӵ�A������һ����� 
3. ��� aPbTc ����ȷ�ģ���ô aPbATca Ҳ����ȷ�ģ����� a, b, c �������ǿ��ַ����������ǽ�����ĸ A ��ɵ��ַ���
	-->����b=A��a=c,����aPATa=>aPAATaa => aP * 2 = Ta 
	
	���ϣ����ַ�����������ʽΪ��xPyTxx ������x,y������ĸ'A'��ɵĴ� ������y������һ��A��� ��A��P(A)*T(A) 
	
	�����ܽ᣺�����ַ���ƥ����⣬һ��ҪŪ�����ַ���ƥ���������ʽ 
*/

#include <iostream>
#include <string>

using namespace std;

/* ��������ַ������ص������ѧ���˳��� 
bool match_string(string str){
	if(str[1] == '\0' || str[2] == '\0'){
		////cout<<"//�ַ����������Ϊ3 " <<endl;
		return false;
	} 
	int i = 0;
	bool is_match = false;//��־PAT����PAAT�Ƿ���� 
	while(str[i] != '\0'){
		if(str[i] == 'A'){//����ĸΪA,���� 
			////cout<<"//����ĸΪA,���� " <<endl;
			i++;
		}else if(str[i] == 'P'){//����ĸΪP,ƥ��PAT����PAAT
			//cout<<"//����ĸΪP,ƥ��PAT����PAAT" <<endl;
			if(!is_match){//PAT����PAATû��ƥ��� 
				//cout<<"//PAT����PAATû��ƥ��� " <<endl;
				if(str[i+1] != '\0' && str[i+2] != '\0'){//�ַ�����û����
					//cout<<"//������û����2 " <<endl;
					if(str[i+1] == 'A' && str[i+2] == 'T'){//ƥ��AT 
						//cout<<"//ƥ��AT�ɹ� " <<endl;
						i = i + 3;
						is_match = true;
					}else if(str[i+2] != 'A'){//ƥ��AA 
						//cout<<"//��ƥ��AAʧ�� " <<endl;
						return false;
					}
				}
				if(!is_match && str[i+1] != '\0' && str[i+2] != '\0' && str[i+3] != '\0'){
					//cout<<"//������û����3 " <<endl;
					if(str[i+3] == 'T'){//ƥ��AAT 
						//cout<<"//ƥ��AAT�ɹ�" <<endl;
						i = i + 4;
						is_match = true;
					}else{
						//cout<<"//ƥ��AATʧ��" <<endl;
						return false;
					}
				}	
			}else{//ƥ���PAT����PAAT��P��ĸ���� 
				//cout<<"//ƥ���PAT����PAAT��P��ĸ���� " <<endl;
				return false;
			} 
		}else{
			//cout<<"//ƥ�䵽��A��P��������ĸ " <<endl;
			return false;
		} 
	}
	return true;
}
*/
bool match_string(string str){
	if(str[1] == '\0' || str[2] == '\0'){
		////cout<<"//�ַ����������Ϊ3 " <<endl;
		return false;
	} 
	int cnt[3] = {0,0,0};//ͳ������λ��A�ĸ���
	int i = 0;
	while(str[i] == 'A'){//ͳ��P֮ǰA�ĸ��� 
		cnt[0]++;
		i++;
	}
	if(str[i] == 'P'){
		i++;
		while(str[i] == 'A'){//ͳ��P��T֮���A�ĸ��� 
			cnt[1]++;
			i++;
		}
		if(str[i] != 'T' || cnt[1] == 0){
			return false;
		}else{
			i++;
			while(str[i] == 'A'){//ͳ��T֮���A�ĸ��� 
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
