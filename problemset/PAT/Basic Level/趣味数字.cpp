#include <iostream>
#include <cmath>
using namespace std;
int a[100000];
int N;
int main(){
    cin>>N;
    for(int i = 0;i < N;i++){
        cin>>a[i];
    }
    int max = -1;
    int min = 2147483647;
    int max_cnt = 0;
    int min_cnt = 0;
    for(int i = 0;i < N;i++){
        for(int j = i+1;j < N;j++){
            int cha = abs(a[i]-a[j]);
            if(cha > max){
                max = a[i]-a[j];
                max_cnt = 1;
            }else if(cha == max){
                max_cnt++;
            }
            if(cha < min){
                min = a[i]-a[j];
                min_cnt = 1;
            }else if(cha == min){
                min_cnt++;
            }
        }
    }
    cout<<min_cnt<<' '<<max_cnt<<endl;
    return 0;
}
