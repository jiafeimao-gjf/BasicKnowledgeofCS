#include <cstdio>
int main(){
  int n;
  scanf("%d",&n);
  int firstId,lastId,id,a,b;
  int max = -1,min = 1000000;
  for(int i = 0;i < n;i++){
    scanf("%d%d%d",&id,&a,&b);
    int dis = a*a + b*b;
    if(max < dis){
      firstId = id;
      max = dis;
    }
    if(min > dis){
      lastId = id;
      min = dis;
    }
  }
  printf("%04d %04d\n",lastId,firstId);
  return 0;
}
