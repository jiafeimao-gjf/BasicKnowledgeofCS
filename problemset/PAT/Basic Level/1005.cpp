//1005. ����(3n+1)���� (25) ����Ӧ��ɸ�������� 

#include <iostream> 

using namespace std;

int numbers[10001];


int main(){
	for(int i = 0;i<10001;i++){
		numbers[i] = 1;
	}
	int input_nums[101];
	int t,i = 0;
	cin >>t;
	while(t--){
		cin>>input_nums[i++];
	}
	for (int j = 0;j < i;j++){
		int num = input_nums[j];
		if(numbers[input_nums[j]] == 1){	
			while(num != 1){
				if(num % 2 == 0){
					num /= 2;
					numbers[num] = 0;
				}else{
					num = (3 * num + 1)/2;
					numbers[num] = 0;
				}
			}
		}
	}
	
	//�������� ��ʵ�ִӴ�С���� 
	int best_num[101],cnt[0] = 0;
	for(int j = 0;j < i;j++){
		if(numbers[input_nums[j]] == 1){
			if(cnt[0] == 0) {
				best_num[cnt[0]++] = input_nums[j];	
			}else{
				if(input_nums[j] < best_num[cnt[0]-1]){
					best_num[cnt[0]++] = input_nums[j];
				}else{
					for(int l = 0;l<cnt[0];l++){
						if(input_nums[j] > best_num[l]){
							for(int x = cnt[0];x > l;x--){
								best_num[x] = best_num[x-1];
							}
							best_num[l] = input_nums[j];
							cnt[0]++;
							breacnt[0];
						}	
					}	
				}
			}
		}
	}
	
	for(int j = 0;j<cnt[0];j++){
		cout<<best_num[j];
		if(j!= cnt[0]-1){	//��ĿҪ�����һ�����ֺ��治�����κ���ĸ 
			cout<<' '; 
		} 
	}
	return 0;
} 
