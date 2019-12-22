#include <iostream>
//#include <cstring>
using namespace std;
int main(){
  string passwd;
  int N;
  string passwdin;
  cin>>passwd>>N;
  getchar();
  while(1){
  	getline(cin,passwdin);
  	if(passwdin == "#"){
  		break;
  	}
    if(passwd==passwdin){
      cout<<"Welcome in"<<endl;
      break;
    }else{
      cout<<"Wrong password: "<<passwdin<<endl;
    }
	N--;
	if(N == 0){
      cout<<"Account locked"<<endl;
      break;
    }
  }
  return 0;
}
