//1018. ���Ӽ����� (20)

/*
�����ʽ��

�����1�и���������N��<=105������˫������Ĵ�����
���N�У�ÿ�и���һ�ν������Ϣ�����ס���˫��ͬʱ�����ĵ����ơ�
C�������ӡ���J������������B������������1����ĸ����׷�����2�������ҷ����м���1���ո�

�����ʽ��

�����1��2�зֱ�����ס��ҵ�ʤ��ƽ�������������ּ���1���ո�ָ���
��3�и���������ĸ���ֱ����ס��һ�ʤ�����������ƣ��м���1���ո�
����ⲻΨһ�����������ĸ����С�Ľ⡣

ע�⣺Ҫͳ�����������ʤ�������������һ����Ͱ���ĸ˳����� B>C>J

*/

#include <iostream>
//#include <stdio.h>
using namespace std;

int cmp(char ch1,char ch2){
	if(ch1 == ch2){
		return 0;
	}else if(ch1 == 'C' && ch2 =='J'){
		return 1;
	}else if(ch1 == 'J' && ch2 =='B'){
		return 1;
	}else if(ch1 == 'B' && ch2 =='C'){
		return 1;
	}else{
		return -1;
	}
}

int main(){
	int n;
	cin >> n;
	//scanf("%d\n",&n);
	int k = 0;
	char ch1[100001],ch2[100001];
	int cnt1[3]={0,0,0},cnt2[3]={0,0,0};
	int s1[3] = {0,0,0},s2[3] = {0,0,0};
	while(n--){
		cin>>ch1[k]>>ch2[k];
		//scanf("%c %c\n",&ch1[k],&ch2[k]);
		k++;
	}
	/*
	for(int i = 0;i < k; i++){
		cout << ch1[i]<<' '<<ch2[i]<<endl;
		//printf("%c %c\n",ch1[i],ch2[i]);
	}
	*/
	for(int i = 0;i < k;i++){
		if(cmp(ch1[i],ch2[i]) == 1){//��Ӯ���� 
			s1[0]++;
			s2[2]++;
			if(ch1[i] == 'C'){
				cnt1[0]++;
			}else if(ch1[i] == 'J'){
				cnt1[1]++;
			}else if(ch1[i]== 'B'){
				cnt1[2]++; 
			}
		}else if(cmp(ch1[i],ch2[i]) == -1){//��Ӯ�˼� 
			s1[2]++;
			s2[0]++;
			if(ch2[i] == 'C'){
				cnt2[0]++;
			}else if(ch2[i] == 'J'){
				cnt2[1]++;
			}else if(ch2[i]== 'B'){
				cnt2[2]++; 
			}
		}else{//���Ҵ�ƽ 
			s1[1]++;
			s2[1]++; 
		}
	}
	
	//printf("%d %d %d\n",s1[0],s1[1],s1[2]);
	//printf("%d %d %d\n",s2[0],s2[1],s2[2]);
	cout<<s1[0]<<' '<<s1[1]<<' '<<s1[2]<<endl;
	cout<<s2[0]<<' '<<s2[1]<<' '<<s2[2]<<endl;
	//cout<<cnt1[0]<<' '<<cnt1[1]<<' '<<cnt1[2]<<endl;
	//cout<<cnt2[0]<<' '<<cnt2[1]<<' '<<cnt2[2]<<endl;
	if((cnt1[0] > cnt1[1] && cnt1[0] > cnt1[2]) || (cnt1[0] == cnt1[1] && cnt1[0] > cnt1[2]) || (cnt1[0] == cnt1[2] && cnt1[0] > cnt1[1])){
		cout<<"C "; 
		//printf("C ");
	}else if(cnt1[1] > cnt1[2] && cnt1[1] > cnt1[0]){
		cout<<"J ";
		//printf("J ");
	}else if((cnt1[2] > cnt1[1] && cnt1[2] > cnt1[0]) || (cnt1[2] == cnt1[1] && cnt1[2] > cnt1[0]) ||
	(cnt1[2] == cnt1[0] && cnt1[2] > cnt1[1]) || (cnt1[2] == cnt1[0] && cnt1[2] == cnt1[1])){
		cout<<"B "; 
		//printf("B ");
	}
	if((cnt2[0] > cnt2[1] && cnt2[0] > cnt2[2]) || (cnt2[0] == cnt2[1] && cnt2[0] > cnt2[2]) || (cnt2[0] == cnt2[2] && cnt2[0] > cnt2[1])){
		//printf("C\n");
		cout<<'C'<<endl;
	}else if(cnt2[1] > cnt2[2] && cnt2[1] > cnt2[0]){
		//printf("J\n");
		cout<<'J'<<endl;
	}else if((cnt2[2] > cnt2[1] && cnt2[2] > cnt2[0]) ||(cnt2[2] == cnt2[1] && cnt2[2] > cnt2[0]) || 
	(cnt2[2] == cnt2[0] && cnt2[2] > cnt2[1]) || (cnt2[2] == cnt2[1] && cnt2[2] == cnt2[0])){
		//printf("B");
		cout<<'B'<<endl; 
	}
	return 0;
} 
