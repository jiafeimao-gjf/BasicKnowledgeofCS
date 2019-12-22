//1125. Chain the Ropes (25)
#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;
int main(){
    int N;
    cin>>N;
    double segs[10000];
    double  longest = 0;
    for(int i = 0;i < N;i++){
        cin>>segs[i];
    }
    sort(segs,segs+N);
    longest = segs[0];
    for(int i = 1;i < N;i++){
        longest = int((longest+segs[i])/2);
    }
    cout<<longest<<endl;
    return 0;
}
