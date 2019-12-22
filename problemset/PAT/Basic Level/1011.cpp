#include <iostream>

using namespace std;
long ABC[11][3];
int main(){
  int t,i=0;
  cin>>t;
  while(t--){
    cin>>ABC[i][0]>>ABC[i][1]>>ABC[i][2];
    i++;
  }
  for(int j = 0;j<i;j++){
    if(ABC[j][0] + ABC[j][1]>ABC[j][2]){
      cout<<"Case #"<<j+1<<": true"<<endl;
    }else{
      cout<<"Case #"<<j+1<<": false"<<endl;
    }
  }
  return 0;
}
