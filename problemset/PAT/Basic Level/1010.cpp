//1010. һԪ����ʽ�� (25)
//�����漰һ����ȷ�������������⣬������Ҫ��ϸ˼������Щ�������,�����кͲ����������������������
#include <iostream>

using namespace std;

int main() {
	int a, n;
	bool first = true;//���ƿո�����������������Ŀ���
	while (cin >> a >> n) {//�������뷽ʽ�������Ǹ�����
		if (n == 0 && a ==0) {//ֻ������Ķ���ʽ���ҳ�����ҲΪ0 ,y = 0
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
		//ֻ������Ķ���ʽ,�����Ϊ0���˶���ʽ����Ϊ0 0
		//�������������ں�������Ķ���ʽ�У�����Ҫ��һ����־
		if (n == 0 && a != 0 && first) {//y = ax^0
			cout << 0 << ' ' << 0;
		}
	}
	return 0;
}