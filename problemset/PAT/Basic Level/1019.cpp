/*
1019. 数字黑洞 (20)

给定任一个各位数字不完全相同的4位正整数，
如果我们先把4个数字按非递增排序，再按非递减排序，然后用第1个数字减第2个数字，将得到一个新的数字。
一直重复这样做，我们很快会停在有“数字黑洞”之称的6174，这个神奇的数字也叫Kaprekar常数。

例如，我们从6767开始，将得到

7766 - 6677 = 1089
9810 - 0189 = 9621
9621 - 1269 = 8352
8532 - 2358 = 6174
7641 - 1467 = 6174
... ...

现给定任意4位正整数，请编写程序演示到达黑洞的过程。

输入格式：

输入给出一个(0, 10000)区间内的正整数N。

输出格式：

如果N的4位数字全相等，则在一行内输出“N - N = 0000”；
否则将计算的每一步在一行内输出，直到6174作为差出现，输出格式见样例。
注意每个数字按4位数格式输出。

*/

#include <iostream>
#include <cmath> 
using namespace std;

void swap(int A[],int i,int j){
	int temp = A[i];
	A[i] = A[j];
	A[j] = temp;
}
int main(){
	int n;
	cin >> n;
	int key = n;
	if(n==6174){
		cout<<"7641 - 1467 = 6174"<<endl;
		return 0;
	}
	if(n == 0){
		cout<<"0000 - 0000 = 0000"<<endl;
		return 0;
	}
	while(key != 6174 && key != 0){
		int nums[4];
		nums[0] = key % 10;
		nums[1] = key / 10 % 10;
		nums[2] = key / 100 % 10;
		nums[3] = key / 1000;
		for(int i = 0;i < 4; i++){//i表示现在排了第几个最大值 
			for(int j = 0;j < 4 - i - 1;j++){
				if(nums[j] > nums[j+1])//该元素的值大于后一个元素 
					swap(nums,j,j+1);//该元素上浮 
			}
		}
		cout<<nums[3]<<nums[2]<<nums[1]<<nums[0]<<" - "<<
				nums[0]<<nums[1]<<nums[2]<<nums[3]<<" = "; 
		key = ((nums[3] - nums[0])*1000 + (nums[2] - nums[1])*100 + (nums[1] - nums[2])*10 + nums[0] - nums[3]);
		cout<<key/1000<<key/100%10<<key/10%10<<key%10<<endl;//对key要按照四位数格式输出 ，当算法没问题时，一定是输出格式有问题 
	}
	return 0;
} 
