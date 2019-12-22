#include <iostream>
using namespace std;
int a[100001];
int main(){
  for(int i = 0;i < 100001;i++ ){
    a[i] = -1;
  }
  int N;
  cin>>N;
  int id,score;
  while(N--){
    cin>>id>>score;
    if(a[id] == -1){
      a[id] = 0;
    }
    a[id] += score;
  }
  id = 1;
  int max = a[1];
  for(int i = 2;i < 100001;i++ ){
    if(a[i]!= -1 && a[i] > max){
      max = a[i];
      id = i;
    }
  }
  cout<<id<<' '<<max<<endl;
  return 0;
}
