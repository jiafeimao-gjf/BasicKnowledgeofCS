//1018. 锤子剪刀布 (20)

/*
输入格式：

输入第1行给出正整数N（<=105），即双方交锋的次数。
随后N行，每行给出一次交锋的信息，即甲、乙双方同时给出的的手势。
C代表“锤子”、J代表“剪刀”、B代表“布”，第1个字母代表甲方，第2个代表乙方，中间有1个空格。

输出格式：

输出第1、2行分别给出甲、乙的胜、平、负次数，数字间以1个空格分隔。
第3行给出两个字母，分别代表甲、乙获胜次数最多的手势，中间有1个空格。
如果解不唯一，则输出按字母序最小的解。

注意：要统计三种情况的胜出次数，如果都一样多就按字母顺序输出 B>C>J

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
		if(cmp(ch1[i],ch2[i]) == 1){//甲赢了乙 
			s1[0]++;
			s2[2]++;
			if(ch1[i] == 'C'){
				cnt1[0]++;
			}else if(ch1[i] == 'J'){
				cnt1[1]++;
			}else if(ch1[i]== 'B'){
				cnt1[2]++; 
			}
		}else if(cmp(ch1[i],ch2[i]) == -1){//乙赢了甲 
			s1[2]++;
			s2[0]++;
			if(ch2[i] == 'C'){
				cnt2[0]++;
			}else if(ch2[i] == 'J'){
				cnt2[1]++;
			}else if(ch2[i]== 'B'){
				cnt2[2]++; 
			}
		}else{//甲乙打平 
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
