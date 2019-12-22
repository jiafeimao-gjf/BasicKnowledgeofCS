//1127. Friend numbers

#include <iostream>
using namespace std;

int main(){
    int friend_id[10000];
    int N;
    cin>>N;
    int num;
    int cnt = 0;
    while(N--){
        cin>>num;
        int sum = num/1000 + num%1000/100 + num%100/10 + num%10;
        cout<<"sum="<<sum<<endl;
        if(cnt == 0){
            friend_id[cnt++] = sum;
        }else{
            for(int i = 0;i < cnt;i++){
                if(friend_id[i] == sum){
                    break;
                }else if(i == cnt - 1){
                    friend_id[cnt++] = sum;
                    break;
                }
            }
        }
    }

    for(int i = 0;i < cnt;i++){
        for(int j = 0;j < cnt - i - 1;j++){
            if(friend_id[j]>friend_id[j+1]){
                int temp = friend_id[j];
                friend_id[j] = friend_id[j+1];
                friend_id[j+1] = temp;
            }
        }
    }
    cout<<cnt<<endl;
    for(int i = 0;i < cnt;i++){
        cout<<friend_id[i];
        if(i == cnt-1) cout<<endl;
        else cout<<' ';
    }
    return 0;
}
