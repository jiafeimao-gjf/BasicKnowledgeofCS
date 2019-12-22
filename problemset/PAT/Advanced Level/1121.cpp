//

#include <iostream>
#include <iomanip>
using namespace std;
int peoples[100000];//-1/00000-99999/-2

int main(){
    int N,M;
    int male,female;
    int peo_pat;
    int cnt = 0;
    for(int i = 0;i < 100000;i++){
        peoples[i] = -1;
    }
    cin>>N;
    while(N--){
        cin>>male>>female;
        peoples[male] = female;
        peoples[female] = male;
    }
    cin>>M;
    while(M--){
        cin>>peo_pat;
        if(peoples[peo_pat] == -1){//�ǵ���
            peoples[peo_pat] = -2;
            cnt++;
        }else if(peoples[peo_pat] >= 0 && peoples[peo_pat]<=99999){//�а���
            if(peoples[peoples[peo_pat]] == peo_pat){//����û��
                peoples[peo_pat] = -2;
                cnt++;
            }else if(peoples[peoples[peo_pat]] == -2){//��������
                peoples[peoples[peo_pat]] = peo_pat;
                cnt--;
            }
        }
    }
    cout<<cnt<<endl;
    for(int i = 0,j = 0;i < 100000;i++){
        if(peoples[i] == -2){
            cout<<setfill('0')<<setw(5)<<i;
        if(j == cnt - 1) { cout<<endl;break; }
        else { j++;cout<<' '; }
        }
    }
    return 0;
}
