/*
1020. 月饼 (25)

月饼是中国人在中秋佳节时吃的一种传统食品，不同地区有许多不同风味的月饼。
现给定所有种类月饼的库存量、总售价、以及市场的最大需求量，请你计算可以获得的最大收益是多少。

注意：销售时允许取出一部分库存。
样例给出的情形是这样的：假如我们有3种月饼，其库存量分别为18、15、10万吨，总售价分别为75、72、45亿元。
如果市场的最大需求量只有20万吨，那么我们最大收益策略应该是卖出全部15万吨第2种月饼、
以及5万吨第3种月饼，获得 72 + 45/2 = 94.5（亿元）。

输入格式：

	每个输入包含1个测试用例。
	每个测试用例先给出一个不超过1000的正整数N表示月饼的种类数、
	以及不超过500（以万吨为单位）的正整数D表示市场最大需求量。
	随后一行给出N个正数(可以是小数)表示每种月饼的库存量（以万吨为单位）；
	最后一行给出N个正数(可以是小数)表示每种月饼的总售价（以亿元为单位）。
	数字间以空格分隔。

输出格式：

	对每组测试用例，在一行中输出最大收益，以亿元为单位并精确到小数点后2位。
	
	贪婪算法，将月饼的单价按从大到小排序，之后在这个序列中按照最大需求量进行求最大销售额  
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
