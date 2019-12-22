//1124 Raffle for Weibo Followers 1125 --1126 --1127
/*
9 3 2
Imgonnawin!
PickMe
PickMeMeMeee
LookHere
Imgonnawin!
TryAgainAgain
TryAgainAgain
Imgonnawin!
TryAgainAgain
*/
#include <iostream>
#include <string>

using namespace std;

int main(){
    string nickname[1001];
    string winner[1001];
    int M,N,S;
    cin>>M>>N>>S;

    for(int i = 0;i < M;i++){
        cin>>nickname[i];
    }
    int cnt = 0;
    for(int i = S-1;i < M;){
        if(cnt == 0){
            winner[cnt++] = nickname[i];
            i = i + N;
        }else{
            int counts = cnt;
            for(int j = 0;j < counts;j++){
                if(winner[j] == nickname[i]){
                    i = i + 1;
                    break;
                }else if(j == cnt - 1){
                    winner[cnt++] = nickname[i];
                    i = i + N;
                }
            }
        }
    }
    //cout<<"cnt = "<<cnt<<endl;
    for(int i = 0;i < cnt;i++){
        cout<<winner[i]<<endl;
    }

    if(cnt == 0){
        cout<<"Keep going..."<<endl;
    }
    return 0;
}
