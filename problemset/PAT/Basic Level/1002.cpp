// 1002. д������� (20)
#include <iostream>
#include <string>

using namespace std;

int main(){
	char a[1024];//���һ������ 
	int sum = 0;//��������λ�ĺ�
	string num_spell[10] = {"ling","yi","er","san","si","wu","liu","qi","ba","jiu"};
	string sum_spell[10];
	cin >>a;
	for(int i = 0;a[i] != '\0';i++){
		//cout<<(int)(a[i] - 0x30)<<' '; 
		sum += (int)(a[i] - 0x30);//0x30�� '0' ��ASCII�� 
	}
	int i = 0;
	while(sum != 0){
		sum_spell[i] = num_spell[sum % 10];
		sum /= 10;
		i++;
	}
	while(i--){
		cout<<sum_spell[i];
		if(i!=0){
			cout<<' ';
		}
	} 
	return 0;
} 
