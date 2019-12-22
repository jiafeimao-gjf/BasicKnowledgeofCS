//1126. Eulerian
#include <iostream>
using namespace std;
int degree[500];
int uset[500];

int find(int x){
    int r = x;//ί��rȥ������
    while(uset[r]!=r) //��������
        r = uset[r];//rί���ϼ�������
    return r;       //���żݵ�
}
int main(){
    for(int i = 0;i < 500;i++){
        degree[i] = 0;
        uset[i] = i;
    }
    int N,M;
    int x,y;
    cin>>N>>M;
    for(int i = 0;i < M;i++){//ͳ�Ƹ�����Ķ�
        cin>>x>>y;
        degree[x-1]++;
        degree[y-1]++;
        uset[find(x)] = find(y);//y��x���ϼ�
    }

    int kind = 0;
    for(int i = 0;i < N;i++){
        cout<<degree[i];
        if(i < N-1) cout<<' ';
        if(degree[i]%2!=0) {//�ҵ�һ�������ȵĵ���û��0�ȵĵ�
            kind++;//�����ȵ�ĸ����� 1
        }
    }
    cout<<endl;
    //�����Ƿ���ڶ����Ķ������
    int cnt = 0;
    for(int i = 0;i < N;i++){
        if(uset[i] == i) cnt++;
    }
    if(cnt != 1) kind = -1;//���������������1������ڶ������


    if(kind == 0){//����ȫΪż
        cout<<"Eulerian"<<endl;
    }else if(kind == 2){//��������Ϊ�����ĵ�
        cout<<"Semi-Eulerian"<<endl;
    }else{
        cout<<"Non-Eulerian"<<endl;
    }
    return 0;
}
