#include <cstdio>
#include <vector>
using namespace std;
int g[201][201];
vector<int> s;
int main(){
	int nv,ne,v1,v2;
	scanf("%d %d",&nv,&ne);
	for(int i = 0;i < ne;i++){
		scanf("%d %d",&v1,&v2);
		g[v1][v2] = g[v2][v1] = 1;
	}
	int m,k;
	scanf("%d",&m);
	for(int i = 0;i < m;i++){
		s.clear();
		scanf("%d",&k);
		s.resize(k);
		for(int j = 0;j < k;j++){
			scanf("%d",&s[j]);
		}
		bool nac = false,nm = false;
		for(int p = 0;p < s.size() - 1;p++){
			for(int q = p + 1;q < s.size();q++){
				if(g[s[p]][s[q]] != 1){
					nac = true;
					break;
				}
			}
		}
		if(nac){
			printf("Not a Clique\n");
			continue;
		}
		for(int j = 1;j <= nv;j++){
			bool isother = true;
			for(int p = 0;p < s.size();p++){
				if(s[p] == j) {
					isother = false;
					break;
				}
			}
			if(isother){
				for(int p = 0;p < s.size();p++){
					if(g[j][s[p]] != 1) {
						break;
					}
					if(p == s.size() - 1) nm = true;
				}
			}
			if(nm) break;
		}
		if(nm) {
			printf("Not Maximal\n");
		}else{
			printf("Yes\n");
		}
	}
}
