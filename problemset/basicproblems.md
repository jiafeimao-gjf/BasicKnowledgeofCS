# 字符框

### 题目描述 
给你n∗m的二维网格，求2∗2的方格的个数，方框里面的字符可以构成'face'
### 输入描述:
第一行输入两个整数n,m

接下来n行每行m个小写字符

1<=n,m<=50
### 输出描述:
输出满足条件的2∗2的方格的数量
#### 示例1
#### 输入

```
2 3  
fac  
cef
```
 
#### 输出
```
2
```

```c++
#include <cstdio>
char chs[51][51];

int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    for (int i = 0;i < n;i++){
        char str[51];
        scanf("%s",&str);
        for (int j = 0;j < m;j++){
            chs[i][j] = str[j];
        }
    }
    int res = 0;
    for (int i = 0;i < n-1;i++){
        for (int j = 0;j < m-1;j++){
            // 遍历看是否有四个字母，face
            char ch[4] = {'f','a','c','e'};
            int count = 4;
            for (int a = i;a <= i+1;a++){
                for (int b = j;b <= j+1;b++){
                    for (int k = 0;k < 4;k++){
                        if (chs[a][b] == ch[k]){// 检测到关键字母
                            ch[k] = ' ';// 将其置为空格，以防重复检测
                            count--;
                        }
                    }
                }
            }
            if (count == 0){
                res++;
            }
        }
    }
    printf("%d\n",res);
    return 0;
}
```
# 初始化扫雷游戏

> 链接：https://ac.nowcoder.com/acm/problem/22232
> 来源：牛客网

### 题目描述 
扫雷游戏是一款十分经典的单机小游戏。在n行m列的雷区中有一些格子含有地雷（称之为地雷格），其他格子不含地雷（称之为非地雷格）。
玩家翻开一个非地雷格时，该格将会出现一个数字——提示周围格子中有多少个是地雷格。
现在给出n行m列的雷区中的地雷分布，请计算出每个非地雷格周围的地雷格数。

注：一个格子的周围格子包括其上、下、左、右、左上、右上、左下、右下八个方向上与之直接相邻的格子。


#### 输入描述:
第一行输入两个整数n,m ，分别表示雷区的行数和列数。

接下来n行，每行m个字符，描述了雷区中的地雷分布情况。字符’*’表示相应格子是地雷格，字符’?’表示相应格子是非地雷格。相邻字符之间无分隔符。

1<=n,m<=100
#### 输出描述:
输出包含n行，每行m个字符，描述整个雷区。用’*’表示地雷格，用周围的地雷个数表示非地雷格。相邻字符之间无分隔符
#### 示例1
#### 输入

```
3 3
*??
???
?*?
```

#### 输出

```
*10
221
1*1
```


```c++
#include <iostream>
#include <cstdio>
using namespace std;
char chs[100][100];
int main(){
    int n,m;
    cin>>n>>m;
    for (int i = 0;i < n;i++){
        for (int j = 0;j < m;j++){
            cin>>chs[i][j];
        }
    }
    for (int i = 0;i < n;i++){
        for (int j = 0;j < m;j++){
            if (chs[i][j]!='*'){
                int x1,x2,y1,y2;
                x1 = i-1>=0?i-1:0;
                x2 = i+1<n?i+1:n;
                y1 = j-1>=0?j-1:0;
                y2 = j+1<m?j+1:m;
                int sum = 0;
                for(int a = x1;a <= x2;a++){
                    for (int b = y1;b <= y2;b++){
                        if (chs[a][b] == '*'){
                            sum++;
                        }
                    }
                }
                chs[i][j] = '0'+sum;
            }
        }
    }
    for (int i = 0;i < n;i++){
        for (int j = 0;j < m;j++){
            cout<<chs[i][j];
        }
        cout<<endl;
    }
    return 0;
}
```

# 约瑟夫环
> 链接：https://ac.nowcoder.com/acm/problem/22227
> 来源：牛客网

### 题目描述 
n个人（0,1,2,3,4...n-1），围成一圈，从编号为k的人开始报数，报数报到m的人出队（报数是1,2,...m这样报的）。下次从出队的人之后开始重新报数，循环往复，当队伍中只剩最后一个人的时候，那个人就是大王。现在，给定n，k，m，
请你求出大王的编号。
输入描述:
输入一行包含三个整数n,k,m

1<=n<=100,1<=k<=n-1,1<=m<=100
### 输出描述:
输出一个整数
#### 示例1
#### 输入
```
5 1 2
```
#### 输出

```
3
```

```c++
#include <iostream>
#include <queue>
 
 using namespace std;
 
int main(){
    int n,k,m;
    cin>>n>>k>>m;
    queue<int> a;
    for(int i = 0;i < n;i++){
        a.push(i);
    }
    while(k--){
        int b = a.front();
        a.pop();
        a.push(b);
    }
    while(a.size()>1){
        int count = m;
        while(count>0){
            int b = a.front();
            a.pop();
            if(--count != 0){// 不是最后一个元素
                a.push(b);
            }
        }
    }
    printf("%d\n",a.front());
    return 0;
}
```
# 上下金字塔
> 链接：https://ac.nowcoder.com/acm/problem/22204
> 来源：牛客网

### 题目描述 
输出双层金字塔。

### 输入描述:
多个测试数据。每个测试数据输入一个整数n( 2 <= n <= 9)
### 输出描述:
输出双层金字塔
#### 示例1
#### 输入

```
2
5
```

#### 输出

```
 *
***
 *
    *
   ***
  *****
 *******
*********
 *******
  *****
   ***
    *
```

```
#include <cstdio>

int main(){
    int n;
    while(scanf("%d",&n) != EOF){
        for (int i = 1;i <= n;i++){// 第i行
            // 输出空格
            for (int j = 1;j <= n-i;j++){//依次递减
                printf(" ");
            }
            // 输出 *
            for (int j = 1;j <= 2*i-1;j++){//一次递增
                printf("*");
            }
            printf("\n");// 每一行一个回车
        }
        for (int i = n-1;i > 0;i--){
            // 输出空格
            for (int j = 1;j <= n-i;j++){//依次递增
                printf(" ");
            }
            // 输出 *
            for (int j = 1;j <= 2*i-1;j++){//依次递减
                printf("*");
            }
            printf("\n");// 每一行一个回车
        }
    }
    return 0;
}
```
# 字符金字塔
> 链接：https://ac.nowcoder.com/acm/problem/22209
> 来源：牛客网

### 题目描述 
请打印输出一个字符金字塔，字符金字塔的特征请参考样例


#### 输入描述:
输入一个字母，保证是大写
#### 输出描述:
输出一个字母金字塔。
#### 示例1
#### 输入

```
C
```
#### 输出

```
  A
 ABA
ABCBA
```

```
#include <cstdio>
#include <string>

int main(){
    char ch;
    char chs[26] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
    ch = getchar();
    int n = ch - 'A' + 1;
    for (int i = 1;i <= n;i++){// 第i行
        // 输出空格
        for (int j = 1;j <= n-i;j++){//依次递减
            printf(" ");
        }
        for (int j = 0;j < i;j++){//0~(i-1)
            printf("%c",chs[j]);
        }
        for (int j = i-2;j >= 0;j--){//(i-2)~0
            printf("%c",chs[j]);
        }
        printf("\n");// 每一行一个回车
    }
    return 0;
}
```

# 阶乘计算
> 链接：https://ac.nowcoder.com/acm/problem/22205
> 来源：牛客网

### 题目描述 
计算S=1！+2！+3！+…+N！的值
#### 输入描述:
输入一行，包含一个整数n (n <= 10)
#### 输出描述:
输出一行，包含一个整数。
#### 示例1
#### 输入

```
2
```

#### 输出

```
3
```

```
#include <cstdio>

int main(){
    int n;
    scanf("%d",&n);
    // 用空间换时间
    int lastsum = 1;
    int sum = 0;
    for (int i = 1;i <= n;i++){
        lastsum *= i;// 更新为i的阶乘
        sum += lastsum;// 更新阶乘的和
    }
    printf("%d\n",sum);
    return 0;
}
```

# 打印质数表
> 链接：https://ac.nowcoder.com/acm/problem/22210
> 来源：牛客网

### 题目描述 
输入一个自然数N，按质数定义从小到大输出1~N（包含N）中所有的质数
#### 输入描述:
输入一行，包含一个整数N

1 <= N <= 2000
#### 输出描述:
输出一行，包含所有的质数，按照从小到大的顺序输出，以空格隔开。
#### 示例1
#### 输入

```
20
```

#### 输出
```
2 3 5 7 11 13 17 19
```
```
#include <cstdio>
#include <cmath>
int main(){
    int n,count=3;
    int p[10000];
    p[0] = 2;p[1] = 3;p[2] = 5;
    scanf("%d",&n);
    if (n<=4){
        int i = 0;
        while(p[i] <= n){
            printf("%d ",p[i]);
            i++;
        }
    } else {
        printf("%d %d ",p[0],p[1]);
        for (int i = 5;i <= n;i++){// 2～n
            for (int j = 0;p[j] <= (int)sqrt(i);j++){// 判断i是不是素数
                if (i % p[j] == 0){// i不是素数
                    break;
                }
                if (p[j+1] > (int)sqrt(i)){//p[j]是最后一个需要比较的数字
                    printf("%d",i);
                    p[count++] = i;// 动态更新质数数组
                    if (i != n){// 不是n，则输出一个空格
                        printf(" ");
                    }
                }
            }
            
        }
    }
    return 0;
}
```
# 最大公约数
> 链接：https://ac.nowcoder.com/acm/problem/22215
> 来源：牛客网

### 题目描述 
最大公因数，也称最大公约数、最大公因子，指两个或多个整数共有约数中最大的一个。给你两个数，请输出他们的最大公约数。
#### 输入描述:
输入一行，包含两个正整数A,B

1 <= A,B <= 1e9
#### 输出描述:
输出一行，包含一个正整数
#### 示例1
#### 输入
```
4 6
```
#### 输出
```
2
```
```
#include <cstdio>
// 欧几里得算法，求最大公约数
long gcd(long a,long b){
    return b == 0?a:gcd(b,a%b);
}
int main(){
    long a,b;
    scanf("%ld %ld",&a,&b);
    /*
    if (a>b){
        a = b - a;
        b = b - a;
        a = a + b;
    }
    while(a%b != 0){// 项减法
        b = b - a;
        if (a > b){
            a = b - a;
            b = b - a;
            a = a + b;
        }
    }*/
    
    printf("%ld",gcd(a,b));
    return 0;
}
```

# 质数数量
> 链接：https://ac.nowcoder.com/acm/problem/22226
> 来源：牛客网

### 题目描述 
质数（prime number）又称素数，有无限个，质数定义为在大于1的自然数中，除了1和它本身以外不再有其他因数。
例如小于10的质数有2，3，5，7。
#### 输入描述:
第一行输入一个整数T，表示询问的个数

接下来T行每行输入一个整数n.

1<=T<=1e8,1<=n<=1000000
#### 输出描述:
对于每个询问n输出小于等于n的的质数的个数。
#### 示例1
#### 输入

```
2
10
1000000
```

#### 输出

```
4
78498
```
```
#include <iostream>
#include <cmath>
using namespace std;
/*思路
一个大数组p[80000],存储所有的质数，最后一个质数的下标为size
如果输入的n大于目前已获取的最大的素数，
则求p[size]~n的之间的未知质数，存放在p数组中。
否则，采用二分查找，如果n是质数，可以确定位置，如果不是素数，可以确定离他最近的左右质数。
*/
int p[80000];// 素数下标
int size;// 已存储的最大质数下标
bool isPrime(int n){
    if (n == 2 || n == 3 || n == 5) return true;
    if (n == 4) return false;
    bool flag = true;
    for (int i = 0;p[i] <= (int)sqrt(n);i++){
        if (n % p[i] == 0){
            flag = false;
            break;
        }
        if (p[i+1] > (int)sqrt(n)){
            p[++size] = n;// 更新质数数组
        }
    }
    return flag;
}
int main(){
    int t,n;
    p[0] = 2;p[1] = 3;p[2] = 5;
    size = 2;
    cin>>t;
    while(t--){
        cin>>n;// 求 1～n内有多少个质数
        if (n == 1){
            printf("%d\n",0);
            continue;
        }
        if (p[size] >= n){// 已经有记录
            if(p[size] == n){
                printf("%d\n",size+1);
                continue;
            }
            int l = 0,r = size;// 二分查找
            while(l < r){
                if (l+1==r && n >= p[l]){//n不是质数
                    printf("%d\n",l+1);
                    break;
                }
                int mid = (l+r)>>1;
                if (p[mid] == n){//n是质数
                    printf("%d\n",mid+1);
                    break;
                }else if (p[mid] > n){
                    r = mid;
                }else{
                    l = mid;
                }
            }
        }else {// 还没有记录，将素数记录增加至n
            int count = size+1;
            for (int i = p[size]+1;i <= n;i++){
                if (isPrime(i)){
                    count++;
                }
            }
            printf("%d\n",count);
        }
    }
    return 0;
}
```

# 回形矩阵
> 链接：https://ac.nowcoder.com/acm/problem/22230
> 来源：牛客网
### 题目描述 
给你一个整数n，按要求输出n∗n的回型矩阵
#### 输入描述:
输入一行，包含一个整数n

1<=n<=19
#### 输出描述:
输出n行，每行包含n个正整数.
#### 示例1
#### 输入

```
4
```

#### 输出

```
1   2  3 4
12 13 14 5
11 16 15 6
10  9  8 7
```

```
#include <iostream>
#include <cstdio>
using namespace std;
int main(){
    int n,a[20][20] = {0},t,j,k;
    t = j = k =0;// j为行号，k为列号
    cin>>n;
    for (int i = 0;i < n/2;i++){
        for (j = i,k = i;k <= n-i-1;k++){// i,i~n-i-1
            a[j][k] = ++t;
        }
        for (j = i+1,k = n-i-1;j <= n-i-1;j++){//i+1~n-i-1,n-i
            a[j][k] = ++t;
        }
        for (j = n-i-1,k = n-i-2;k >= i;k--){//n-i,n-i-2-1~i
            a[j][k] = ++t;
        }
        for (j = n-i-2,k = i;j >= i+1;j--){// n-i-2~i+1,i
            a[j][k] = ++t;
        }
    }
    if (n % 2){
        a[n/2][n/2] = n*n;
    }
    for (j = 0;j < n;j++){
        for (k = 0; k < n;k++){
            printf("%d",a[j][k]);
            if(k != n-1) cout<<" ";
        }
        cout<<endl;
    }
    return 0;
}
```
# 蛇形矩阵
> 链接：https://ac.nowcoder.com/acm/problem/22231
> 来源：牛客网
> 
### 题目描述 
给你一个整数n，输出n∗n的蛇形矩阵。
#### 输入描述:
输入一行，包含一个整数n
#### 输出描述:
输出n行，每行包含n个正整数，通过空格分隔。

1<=n<=1000
#### 示例1
#### 输入

```
4
```

#### 输出

```
 1  2  6  7
 3  5  8 13
 4  9 12 14
10 11 15 16
```


```
/*分析：
2*n-1次
奇数 j= y+1:i++,j--;j>=0
偶数 i = x+1:i--,j++;i>=0
*/
#include <cstdio>
int a[1000][1000];
int main(){
    int n;
    scanf("%d",&n);
    int count=1,b,i,j;
    for (int k = 0;k < 2*n-1;k++){
        if (k < n){
            b = k;
            if (k%2==0){// 偶数从坐下到右上
                for (i = b,j = 0;i >= 0,j <= b;i--,j++){
                    a[i][j] = count++;
                }
            } else {
                for (i = 0,j = b;i <= b,j>=0;i++,j--){
                    a[i][j] = count++;
                }
            }
        }else{
            b = k-n+1;//得多一行
            if (k%2==0){
                for (i = n-1,j = b;i >= b,j <= n-1;i--,j++){
                    a[i][j] = count++;
                }
            } else {
                for (i = b,j = n-1;i <= n-1,j >= b;i++,j--){
                    a[i][j] = count++;
                }
            }
        }
    }
    
    for (i = 0;i < n;i++){
        for (j = 0;j < n;j++){
            printf("%d",a[i][j]);
            if (j != n-1){
                printf(" ");
            }
        }
        printf("\n");
    }
    
    return 0;
}
```
# 神仙打架

```
链接：https://ac.nowcoder.com/acm/problem/22235 来源：牛客网
```
### 题目描述 
牛村新开了一个系列赛，一个系列赛有m场比赛，比赛规则是解题数越多排名越前，如果前几名队伍解题数一样则会并列第一。
有n个神仙队伍完整参加了m场比赛，请问有几个队伍拿过第一名。
#### 输入描述:
第一行输入两个整数n,m,表示队伍数量与m场比赛。

接下来n行输入一个数字矩阵，每行m个数字字符表示每场比赛的解题数量
1<=n,m<=100
#### 输出描述:
输出一个整数表示拿过第一名的队伍数量
#### 示例1
#### 输入

```
3 5

91728
11828
11111
```
#### 输出
```
3
```
```
/* 思路
n支队伍，m场比赛
n*m个结果
*/
#include <cstdio>
char chs[101][101];

int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    int teams[101] = {0};
    for (int i = 0;i < n;i++){
        char scores[101];
        scanf("%s",scores);
        for (int j = 0;j < m;j++){
            chs[i][j] = scores[j];
        }
    }
    for (int i = 0;i < m;i++){
        int max = 0;
        for(int j = 0;j < n;j++){
            if (chs[j][i] >= chs[max][i]){
                max  = j;
            }
        }
        for(int j = 0;j < n;j++){
            if (chs[j][i] == chs[max][i]){
                teams[j] = 1;
            }
        }
    }
    int count = 0;
    for (int i = 0;i < n;i++){
        if (teams[i] == 1){
            ++count;
        }
    }
    printf("%d",count);
    return 0;
}
```
# 过山车
> 链接：https://ac.nowcoder.com/acm/problem/22237
> 来源：牛客网

### 题目描述 
牛牛想要挑战一下自己的勇气，于是打算去玩牛村的刺激过山车，牛村的刺激过山车一排只坐一个人，牛牛胆子比较小，所以他要求必须坐在前面有人或者后面有人的空位置。
牛牛上车前只知道这批过山车总共有n个位置，已经有k个人坐上去了，请帮助牛牛计算一下最少有多少个位置符合他的要求，最多有多少个位置符合他的要求。
注：第一个位置的前面和最后一个位置的后面我们认为是没有人。

#### 输入描述:
一行两个整数n,k。

n≥k≥0
#### 输出描述:
输出两个整数表示最少和最多的符合他要求的位置
#### 示例1
#### 输入

```
6 3
```

#### 输出

```
1 3
```

#### 示例2
#### 输入

```
6 2
```

#### 输出

```
1 4
```

```
#include <cstdio>

int main(){
    int n,k,max,min;
    scanf("%d %d",&n,&k);
    if (k == 0 || k == n){// 只有牛牛一个人或者已经被坐满了
        min = max = 0;
    }else if (n > 3*k){// 上车人数小于等于总人数的三分之一
        min = 1;
        max = 2*k;
    }else{//否则，最多剩下的都可以
        max = n-k;
        min = 1;
    }
    printf("%d %d",min,max);
    return 0;
}
```

# 回文对称数
> 链接：https://ac.nowcoder.com/acm/problem/22169
> 来源：牛客网

### 题目描述 
今天牛牛学到了回文串，他想在数字里面找回文，即回文数，回文数是正着读与倒着读都一样的数，比如1221，343是回文数，433不是回文数。请输出不超过n的回文数。
#### 输入描述:
输入一个整数n(1 <= n <= 100000)
#### 输出描述:
从1开始按从小到大的顺序输出所有回文数
#### 示例1
#### 输入

```
10
```

#### 输出

```
1
2
3
4
5
6
7
8
9
```

```
#include <iostream>

using namespace std;

int main(){
    int n;
    cin>>n;
    for (int i = 1;i <= n;i++){
        int reverse = 0;
        int t = i;
        while(t >= 10){// t>10
            reverse += t%10;
            reverse *= 10;
            t /= 10;
        }
        reverse += t;
        if(reverse == i){
            cout<<reverse<<endl;
        }
    }
    return 0;
}
```

# 前n项和的前n项和
> 链接：https://ac.nowcoder.com/acm/problem/22159
> 来源：牛客网

### 题目描述 
帮助牛牛计算 1+（1+2）+（1+2+3）+...+(1+2+3+...+n)
#### 输入描述:
输入一个整数
#### 输出描述:
输出一个整数
#### 示例1
#### 输入

```
4
```

#### 输出

```
20
```

```
#include <cstdio>

int main(){
    long n;
    long allsum = 0;
    long lastsum = 0;
    
    scanf("%ld",&n);
    for (long i = 1;i <= n;i++){
        lastsum += i;
        allsum += lastsum;
    }
    printf("%ld",allsum);
    return 0;
}
```


