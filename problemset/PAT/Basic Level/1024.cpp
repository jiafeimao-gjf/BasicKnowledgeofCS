//1024 ��ѧ������

//���ÿ�ѧ��������ʾ�����֣���ʾ��һ�������
//��С����������������������С�������� 
#include <iostream>
#include <string>
using namespace std;
/*
+1.25E-110
-2.5E+05
*/

int main(){
	string number;
	cin>>number;
	int length = number.length();
	bool sign = number.at(0) == '-';//�жϸ�ʵ���ķ���
	int l;
	for(int i = length - 1;i >= 0;i--){
		if(number.at(i) == 'E'){
			l = i;
		}
	}
	string exp = number.substr(l+2,length-1);//ָ�� 
//	cout<<exp<<endl; 
	string nums = number.substr(1,l-1);//������ 
//	cout<<nums<<endl;
	bool isdecimal = number.at(l+1) == '-';
//	if(isdecimal) cout<<"is decimal"<<endl;
	int exponent = 0;
	if(sign) cout<<'-';
	for(int i = 0;i < exp.length();i++){
		exponent += exp[i] - '0';
		if(i != exp.length()-1) exponent *= 10;
	}
//	cout<<exponent<<endl;
	if(isdecimal){
		cout<<"0.";
		for(int i = 1;i < exponent;i++){
			cout<<"0";
		}
		for(int i = 0;i < nums.length();i++){
			if(nums[i]!='.') cout<<nums[i];
		}
	}else{
		string str;
		str.resize(nums.length()-1);
		int j=0;
		for(int i = 0;i < nums.length();i++){
			if(nums[i] != '.') str[j++] = nums[i];
		}
		if(str.length() >= exponent) {
			for(int i = 0;i < str.length();i++){
				cout<<str[i];
				if(i == exponent && i != str.length() - 1) cout<<'.';
			} 
		}else{
			cout<<str;
			exponent -= str.length()-1;
			while(exponent--) cout<<'0';
		}
	}
	return 0;
} 


