//1010. 一元多项式求导 (25)
//本题涉及一个不确定输入量的问题，此题需要仔细思考有那些特殊情况,（仅有和不仅有两种情况）常数项求导
#include <iostream>

using namespace std;

int main() {
	int a, n;
	bool first = true;//控制空格的输出，和特殊情况的考虑
	while (cin >> a >> n) {//这种输入方式，结束是个问题
		if (n == 0 && a ==0) {//只含常项的多项式，且常数项也为0 ,y = 0
			cout << 0 << ' ' << 0;
		}
		if (n != 0 && a != 0) {//y = ax^n
			if (first) {
				first = false;
			}else {
				cout << ' ';
			}
			cout << a*n << ' ' << n - 1;
		}
		//只含常项的多项式,常数项不为0，此多项式导数为0 0
		//这种情况会出现在汉常数项的多项式中，所以要加一个标志
		if (n == 0 && a != 0 && first) {//y = ax^0
			cout << 0 << ' ' << 0;
		}
	}
	return 0;
}