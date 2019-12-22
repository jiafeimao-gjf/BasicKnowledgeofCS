/*
1020. �±� (25)

�±����й���������ѽ�ʱ�Ե�һ�ִ�ͳʳƷ����ͬ��������಻ͬ��ζ���±���
�ָ������������±��Ŀ���������ۼۡ��Լ��г�����������������������Ի�õ���������Ƕ��١�

ע�⣺����ʱ����ȡ��һ���ֿ�档
���������������������ģ�����������3���±����������ֱ�Ϊ18��15��10��֣����ۼ۷ֱ�Ϊ75��72��45��Ԫ��
����г������������ֻ��20��֣���ô��������������Ӧ��������ȫ��15��ֵ�2���±���
�Լ�5��ֵ�3���±������ 72 + 45/2 = 94.5����Ԫ����

�����ʽ��

	ÿ���������1������������
	ÿ�����������ȸ���һ��������1000��������N��ʾ�±�����������
	�Լ�������500�������Ϊ��λ����������D��ʾ�г������������
	���һ�и���N������(������С��)��ʾÿ���±��Ŀ�����������Ϊ��λ����
	���һ�и���N������(������С��)��ʾÿ���±������ۼۣ�����ԪΪ��λ����
	���ּ��Կո�ָ���

�����ʽ��

	��ÿ�������������һ�������������棬����ԪΪ��λ����ȷ��С�����2λ��
	
	̰���㷨�����±��ĵ��۰��Ӵ�С����֮������������а������������������������۶�  
*/

#include <iostream>

using namespace std;

typedef struct {
	double nums;
	double costs;
}GOODS; 
bool cmp(GOODS a,GOODS b){
	return (a.costs/a.nums < b.costs/b.nums);
}
int main(){
	int n,needs;
	cin >>n>>needs;
	GOODS goods[1001];
	for(int i = 0;i < n;i++){
		cin>>goods[i].nums;
	}
	for(int i = 0;i < n;i++){
		cin>>goods[i].costs;
	}
	
	for(int i = 0;i < n;i++){
		for(int j = 0;j < n - i - 1;j++){
			if(cmp(goods[j],goods[j+1])){
				GOODS temp = goods[j];
				goods[j] = goods[j+1];
				goods[j+1] = temp; 
			}
		}
	}
	
	double sell = 0;
	for(int i = 0;i < n && needs != 0;i++){
		//cout<<goods[i].costs/goods[i].nums<<endl; 
		if(goods[i].nums<=needs){
			sell += goods[i].costs;
			needs -= goods[i].nums;
		}else{
			sell +=  needs * ( goods[i].costs/goods[i].nums);
			needs = 0;
		}
	}
	
	cout.setf(ios::fixed);
	cout.precision(2);
	cout <<sell;	  
	cout.unsetf(ios::fixed);
	cout.precision(6);
		
	return 0;
} 
