#include <iostream>
#include <cstring>
using namespace std;

int main(){
    char str[1000];
    while(cin>>str){
        int len =strlen(str);
        int pivot = 0;
        for(int i = len - 1;i >= 0;i--){
            if(str[i] > 'Z'){
                pivot = i;
                break;
            }
        }
        char key;
        int tail = pivot; 
        for(int i = tail-1;i >= 0;i--){
            if(str[i] < 'a'){
                key = str[i];
                for(int j = i;j < pivot;j++){
                    str[j] = str[j+1];
                }
                str[pivot--] = key;
                tail = i;
            }
        }
        cout<<str<<endl;
    }
    return 0;
}
