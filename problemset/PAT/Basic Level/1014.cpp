//1014. ����Ħ˹��Լ�� (20)

//������Ҫ��ASCII���Ϊ��Ϥ A = 65 0 = 48 a = 81,A-Z��a-z��������һ��� 
/*
��4����ĸ'D'�����������ģ�
��2����ͬ���ַ���'E'�����ǵ�5��Ӣ����ĸ������һ����ĵ�14����ͷ������һ���0�㵽23��������0��9���Լ���д��ĸA��N��ʾ����
�������ַ�����1����ͬ��Ӣ����ĸ's'�����ڵ�4��λ�ã���0��ʼ�������ϣ������4���ӡ�
�ָ��������ַ��������������Ħ˹����õ�Լ���ʱ��
*/

//�ĸ��ַ������顣 
//����ַ�ƥ�䡣 
//ƥ��ɹ���ƥ����һ��
//ע�� �ַ�������ת��

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
		}else if(isgetweek && week_str2[i] == week_str1[i] && //����else if��if�Ĳ��ܴ� �����ϸ�ڰ��� 
		((week_str1[i]>='A' && week_str1[i] <= 'N') || (week_str1[i]>='0' && week_str1[i] <= '9'))){
			if(week_str1[i]>='0' && week_str1[i] <= '9'){
				cout<<0<<week_str2[i] - '0'<<':';//����Ҫ+1����Ϊ����Ҫ��ʾ 00 - 09
			}else if(week_str1[i]>='A' && week_str1[i] <= 'N'){
				cout<<week_str2[i] - 'A' + 10<<':';	//��Ҫ+10����Ϊ����Ҫ��ʾ 10 - 23
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
//����Ҫ���
//����ṹҪ���� 

/*
3485djDkxh4hhGE
2984akDfkkkkggEdsb
s&hgsfdk
d&Hyscvnm
*/
