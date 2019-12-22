//1126. Eulerian
#include <iostream>
using namespace std;
int degree[500];
int uset[500];

int find(int x){
    int r = x;//委托r去找掌门
    while(uset[r]!=r) //不是掌门
        r = uset[r];//r委托上级找掌门
    return r;       //掌门驾到
}
int main(){
    for(int i = 0;i < 500;i++){
        degree[i] = 0;
        uset[i] = i;
    }
    int N,M;
    int x,y;
    cin>>N>>M;
    for(int i = 0;i < M;i++){//统计各个点的度
        cin>>x>>y;
        degree[x-1]++;
        degree[y-1]++;
        uset[find(x)] = find(y);//y是x的上级
    }

    int kind = 0;
    for(int i = 0;i < N;i++){
        cout<<degree[i];
        if(i < N-1) cout<<' ';
        if(degree[i]%2!=0) {//找到一个奇数度的点且没有0度的点
            kind++;//奇数度点的个数加 1
        }
    }
    cout<<endl;
    //查找是否存在独立的多个门派
    int cnt = 0;
    for(int i = 0;i < N;i++){
        if(uset[i] == i) cnt++;
    }
    if(cnt != 1) kind = -1;//如果门派数不等于1，则存在多个门派


    if(kind == 0){//度数全为偶
        cout<<"Eulerian"<<endl;
    }else if(kind == 2){//两个度数为奇数的点
        cout<<"Semi-Eulerian"<<endl;
    }else{
        cout<<"Non-Eulerian"<<endl;
    }
    return 0;
}
