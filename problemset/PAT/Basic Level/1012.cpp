//1012. 数字分类 (20)

/*
1、怎么判断一个都没有 ？ 
2、怎么精确到小数点一位？ 

*/

#include <iostream>
#include <iomanip>

using namespace std;

int main() {
	int t;
	cin >> t;
	int An[5] = { 0,0,0,0,0 };
	bool isempty[5] = {true,true,true,true,true} ;
	int f = 1;
	int cnt = 0;
	while (t--) {//输入数据
		int a;
		cin >> a;
		if (a % 5 == 0 && a % 2 == 0) {
			An[0] += a;
			isempty[0] = false;
		}
		else if (a % 5 == 1) {
			An[1] += f*a;
			f = -f;
			isempty[1] = false;
		}
		else if (a % 5 == 2) {
			An[2]++;
			isempty[2] = false;
		}
		else if (a % 5 == 3) {
			An[3] += a;
			cnt++;
			isempty[3] = false;
		}
		else if (a % 5 == 4) {
			if (An[4]<a) {
				An[4] = a;
			}
			isempty[4] = false;
		}
	}
	
	for (int i = 0; i<5; i++) {//输出结果
		if (!isempty[i]) {
			if (i == 0) {
				cout << An[i];
			}
			else {
				if (i == 3) {
					cout.setf(ios::fixed);
					cout.precision(1);
					cout << ' ' << (double)An[i] / cnt;
					cout.unsetf(ios::fixed);
					cout.precision(6);
				}
				else {
					cout << ' ' << An[i];
				}
			}
		}
		else {
			if (i == 0) cout << 'N';
			else cout << ' ' << 'N';
		}
	}
	cout << endl;
	return 0;
}
