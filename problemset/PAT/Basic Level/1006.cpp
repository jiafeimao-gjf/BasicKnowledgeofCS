//1006 换个格式输出整数 
#include <iostream>

using namespace std;

int main(){
  int n;
  cin >> n;
  if(n>1000){
    return 0;
  }else{
    for(int i =0;i < (n/100);i++){
      cout<<'B';
    }
    for(int i =0;i < ((n%100)/10);i++){
      cout<<'S';
    }
    for(int i =0;i < (n%10);i++){
      cout<<i+1;
    }
  }
  return 0;
}
