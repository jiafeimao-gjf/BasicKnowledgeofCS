// 1004. 成绩排名 (20)
#include <iostream>
#include <string>

using namespace std;

//学生信息结构体
typedef struct{
  string name;
  string id;
  int score;
}STU_INFO;

int main(){

  STU_INFO stu_info[1000];
  int t;
  cin >> t;
  int i = 0;
  while(t--){
    cin>>stu_info[i].name>>stu_info[i].id>>stu_info[i].score;
    i++;
  }
  
  //求最低分和最高分的序号
  int maxS = stu_info[0].score,minS = stu_info[0].score;
  int maxO = 0,minO = 0;
  for(int j = 1;j < i;j++){
    if(stu_info[j].score > maxS){
    	maxS = stu_info[j].score;
      	maxO = j;
    }
    if(stu_info[j].score < minS){
    	minS = stu_info[j].score;
      	minO = j;
    }
  }
  
  cout<<stu_info[maxO].name<<' '<<stu_info[maxO].id<<endl;
  cout<<stu_info[minO].name<<' '<<stu_info[minO].id<<endl;
  return 0;
}
