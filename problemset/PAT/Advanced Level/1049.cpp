// ���֮��������-��1���� 
// �ҵĵ�һ�뷨�ǵݹ鲻��������ŵ�,����������㷨�о���ţ���뵽
#include <cstdio>
int count(int x)
{
    int res = 0; // result
    int b = 1; // base
    int l, n, r; // left now right
    while(x / b) {
        l = x / (b*10);
        n = (x / b) % 10;
        r = x % b;
        if (n == 0) {
            res += l * b;
        } else if (n == 1) {
            res += l * b + r + 1;
        } else {
            res += (l+1) * b;
        }
         printf("%d: %d %d %d %d\n", b, l, n, r,res);
        b *= 10;
    }
    return res;
}
int main()
{
    int n;
    scanf("%d", &n);
    printf("%d\n", count(n));
    return 0;
}

