//常用工具，常用算法 ，加一个求解思路 
#include <iostream>
#include <vector>
using namespace std;
vector<vector<int> > v(10000);//邻接表 
int line[10000][10000], visit[10000], minCnt, minTransfer, start, end1;
//	邻接矩阵			访问控制数组 记录最少站数 记录最少换乘 开始点 结束点 
vector<int> path, tempPath;
int transferCnt(vector<int> a) {//遍历已求路径，求转乘次数 
    int cnt = -1, preLine = 0;
    for (int i = 1; i < a.size(); i++) {
        if (line[a[i-1]][a[i]] != preLine) { 
			cnt++;
		}
        preLine = line[a[i-1]][a[i]];//跟新线路 
    }
    return cnt;
}

/*
	深度优先搜索 
	参数更新
	结束条件 
	遍历dfs 
*/
 
void dfs(int node, int cnt) {//深度优先搜索，好好理解 
    if (node == end1 && (cnt < minCnt || (cnt == minCnt && transferCnt(tempPath) < minTransfer))) {//更新少转乘路径 
        minCnt = cnt;
        minTransfer = transferCnt(tempPath);
        path = tempPath;
    }
    if (node == end1) return;//到达终点 
    for (int i = 0; i < v[node].size(); i++) {
        if (visit[v[node][i]] == 0) {
            visit[v[node][i]] = 1;
            tempPath.push_back(v[node][i]);
            dfs(v[node][i], cnt + 1);
            visit[v[node][i]] = 0;
            tempPath.pop_back();
        }
    }
}
int main() {
    int n, m, k, pre, temp;
	//线路数 
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &m, &pre);
        for (int j = 1; j < m; j++) {
            scanf("%d", &temp);
            v[pre].push_back(temp);
            v[temp].push_back(pre);
            line[pre][temp] = line[temp][pre] = i + 1;//记录是第几条线 
            pre = temp;
        }
    }
    scanf("%d", &k);
    for (int i = 0; i < k; i++) {
        scanf("%d %d", &start, &end1);
        minCnt = 99999, minTransfer = 99999;
        tempPath.clear();
        tempPath.push_back(start);
        visit[start] = 1;
        dfs(start, 0);
        visit[start] = 0;
        printf("%d\n", minCnt);
        int preLine = 0, preTransfer = start;
        for (int j = 1; j < path.size(); j++) {
            if (line[path[j-1]][path[j]] != preLine) {
                if (preLine != 0) printf("Take Line#%d from %04d to %04d.\n", preLine, preTransfer, path[j-1]);
                preLine = line[path[j-1]][path[j]];
                preTransfer = path[j-1];
            }
        }
        printf("Take Line#%d from %04d to %04d.\n", preLine, preTransfer, end1);
    }
    return 0;
}
