#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
struct Rank{
	string icode;
	double tws;
	int ns;
	Rank(){
		tws = 0.0;
		ns = 0;
	}
};
vector<Rank> R;
map<string,int> index;
bool cmp(Rank a,Rank b){
	return (a.tws != b.tws ? a.tws > b.tws : (a.ns != b.ns ? a.ns < b.ns : a.icode < b.icode)); 
}
string upper(string icode){
	string ncode;
	for(int i = 0;i < icode.length();i++){
		if(icode[i] <= 'Z') ncode += icode[i] - 'A' + 'a';
		else ncode += icode[i];
	}
	return ncode;
}
int main(){
	int n,score;
	char id[10],icode[10];
	scanf("%d",&n);
	int cnt = 0;
	for(int i = 0;i < n;i++){
		scanf("%s %d %s",id,&score,icode);
		string upicode = upper(string(icode));
		if(index.find(upicode) == index.end()){//不存在 
			Rank rr;
			index[upicode] = cnt;
			rr.icode = upicode;
			rr.ns++;
			if(id[0] == 'B') rr.tws = score/1.5;
			else if(id[0] == 'A') rr.tws = score*1.0;
			else rr.tws = score*1.5;
			R.push_back(rr);
			cnt++;
		}else{//已经存在 
			int j = index[upicode];
			R[j].ns++;
			if(id[0] == 'B') R[j].tws += score/1.5;
			else if(id[0] == 'A') R[j].tws += score*1.0;
			else R[j].tws += score*1.5;
		}
	}
	sort(R.begin(),R.end(),cmp);
	cnt = 1;
	cout<<R.size()<<endl;
	for(int i = 0;i < R.size();i++){
		if(i > 0){
			if((int)(R[i].tws) != (int)(R[i-1].tws)) cnt = i + 1; 
		}
		printf("%d ",cnt);
		cout<<R[i].icode<<" ";
		printf("%d %d\n",(int)(R[i].tws),R[i].ns);
	}
	return 0;
} 
