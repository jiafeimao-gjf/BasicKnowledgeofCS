//1009. ˵���� (20)

//����˵���������ֱ�Ӵ���ԭʼ���ݲ��õ��𰸣���ֱ�Ӵ���
//�ַ����ض����Ҫ��ָ����ʽ��ʾ������ֻ�����һ���ַ� 
#include <iostream>
#include <cstring>
using namespace std;

int main(){
	char str[81];
	cin.get(str,81);
	int i = strlen(str)-1;
	while (i != 0){//�ַ���δ���� 
		while(str[i] != ' ' && i != 0){//һ������δ���� 
			i--;
		}
		if(i != 0){//һ�����ʽ����˵����ַ���û�н�β 
			cout<<(str + i + 1)<<' ';//����дstr[i+1],��Ϊcout<<str[i+1];�����һ���ַ�����˼ 
		}else{
			break;//�ַ������� 
		}
		str[i] = '\0';//Ϊ��һ����������ս��
	}
	cout<<str;
	return 0;
}
