### 发LeedCode

力扣决定给一个刷题团队发LeetCoin作为奖励。同时，为了监控给大家发了多少LeetCoin，力扣有时候也会进行查询。

该刷题团队的管理模式可以用一棵树表示：

团队只有一个负责人，编号为1。除了该负责人外，每个人有且仅有一个领导（负责人没有领导）；
不存在循环管理的情况，如A管理B，B管理C，C管理A。
 

#### 力扣想进行的操作有以下三种：

1. 给团队的一个成员（也可以是负责人）发一定数量的LeetCoin；
2. 给团队的一个成员（也可以是负责人），以及他/她管理的所有人（即他/她的下属、他/她下属的下属，……），发一定数量的LeetCoin；
3. 查询某一个成员（也可以是负责人），以及他/她管理的所有人被发到的LeetCoin之和。
 

#### 输入：
```
N表示团队成员的个数（编号为1～N，负责人为1）；
leadership是大小为(N - 1) * 2的二维数组，其中每个元素[a, b]代表b是a的下属；
operations是一个长度为Q的二维数组，代表以时间排序的操作，格式如下：
operations[i][0] = 1: 代表第一种操作，operations[i][1]代表成员的编号，operations[i][2]代表LeetCoin的数量；
operations[i][0] = 2: 代表第二种操作，operations[i][1]代表成员的编号，operations[i][2]代表LeetCoin的数量；
operations[i][0] = 3: 代表第三种操作，operations[i][1]代表成员的编号；
```
#### 输出：
```
返回一个数组，数组里是每次查询的返回值（发LeetCoin的操作不需要任何返回值）。由于发的LeetCoin很多，请把每次查询的结果模1e9+7 (1000000007)。
```
 

#### 示例 1：
```
输入：N = 6, leadership = [[1, 2], [1, 6], [2, 3], [2, 5], [1, 4]], operations = [[1, 1, 500], [2, 2, 50], [3, 1], [2, 6, 15], [3, 1]]
输出：[650, 665]
```
> 解释：团队的管理关系见下图。
- 第一次查询时，每个成员得到的LeetCoin的数量分别为（按编号顺序）：500, 50, 50, 0, 50, 0;
- 第二次查询时，每个成员得到的LeetCoin的数量分别为（按编号顺序）：500, 50, 50, 0, 50, 15.

#####  限制：
```
1 <= N <= 50000
1 <= Q <= 50000
operations[i][0] != 3 时，1 <= operations[i][2] <= 5000
```
<!-- 来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/coin-bonus
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。 -->
### 思路
- 构造数据结构存储数据
- 设计遍历算法，发leedcode币
- 优化查找算法，统计leedcode币

### 代码
- 我的超时代码
```java
class Solution {
    private int[] hasCoins = null;
    private int getCoins(List<List<Integer>> map, int index,int sum){
        for (int j = 0;j < map.get(index).size();j++) {
            int son = map.get(index).get(j);
            sum += hasCoins[son];// 统计儿子
//            System.out.println(sum+"son = "+son + "，map.get(son).size() = " + map.get(son).size());
            if (map.get(son).size() > 0) {// 有孙子
                sum = getCoins(map,son,sum);// 统计孙子们
            }
        }
        return sum;
    }

    private void giveCoins(int coins,List<List<Integer>> map, int index){
        for (int j = 0;j < map.get(index).size();j++) {
            int son = map.get(index).get(j);
            hasCoins[son] += coins;// 发给儿子
//            System.out.println("son = "+son + "，map.get(son).size() = " + map.get(son).size());
            if (map.get(son).size() > 0) {// 有孙子
                giveCoins(coins,map,son);// 发给孙子们
            }
        }
    }
    public int[] bonus(int n, int[][] leadership, int[][] operations) {
        List<List<Integer>> map = new ArrayList<List<Integer>>(0);
        for (int i = 0;i <= n;i++) {
            map.add(new ArrayList<Integer>(0));
        }
        hasCoins = new int[n+1];
        // 初始化图
        for (int i = 0;i < leadership.length;i++) {
            map.get(leadership[i][0]).add(leadership[i][1]);
        }
        int len = 0;
        for (int i = 0;i < operations.length;i++) {
            if (operations[i][0] == 3) {
                len++;
            }
        }
        int[] res = new int[len];
        int c = 0;
        for (int i = 0;i < operations.length;i++) {
            if (operations[i][0] == 1) {
                hasCoins[operations[i][1]] += operations[i][2];
                // System.out.println(Arrays.toString(hasCoins));
            }else if (operations[i][0] == 2) {
                hasCoins[operations[i][1]] += operations[i][2];
                giveCoins(operations[i][2],map,operations[i][1]);
                // System.out.println(Arrays.toString(hasCoins));
            }else {
                int sum = 0;
                sum +=  hasCoins[operations[i][1]];
                sum = getCoins(map,operations[i][1],sum);
                res[c++] = sum;
            }
        }
        return res;
    }
}
```

- 题解区代码

```java
import java.util.HashMap;
import java.util.Iterator;
import java.util.LinkedList;

class Solution {
    public int[] bonus(int n, int[][] leadership, int[][] operations) {
        // 图节点对于下面的链表
        HashMap<Integer, Node> map = new HashMap<>((int)(n/3.0*4)+1);
        // 初始化
        for(int i=0; i<n; i++) map.put(i+1, new Node(i+1));
        for (int[] ints : leadership) {// 进一步初始化
            Node c = map.get(ints[1]);
            Node p = map.get(ints[0]);
            c.p = p;
            p.child.add(c);
        }
        // 存放结果
        LinkedList<Integer> rs = new LinkedList<>();
        for (int[] operation : operations) {
            Node node = map.get(operation[1]);
            if(operation[0] == 1) {
                node.n += operation[2];
                Node t = node;
                while(t.p != null) {// 向上遍历？对，方便统计某个节点以及子节点所有的leedcode数量
                    t.p.n += operation[2];
                    t = t.p;
                }
            } else if (operation[0] == 2) {// 发leedcode币
                int update = update(node, operation[2]);
                while(node.p != null) {
                    node.p.n += update;
                    node = node.p;
                }
            } else {
                // 直接获取值
                rs.add((int)(node.n%1000000007));
            }
        }
        // 构造返回结果
        Iterator<Integer> iterator = rs.iterator();
        int[] arr = new int[rs.size()];
        for(int i=0; iterator.hasNext(); i++) {
            arr[i] = iterator.next();
        }
        return arr;
    }
    // 发leedcode币更新，递归更新
    int update(Node node, int c) {
        if(node == null)
            return 0;
        int n = c;
        for (Node ch : node.child) {// 遍历子节点
            n += update(ch, c);
        }
        node.n += n;
        return n;
    }

    // 关系树的链表节点
    class Node {
        int num;// 节点编号
        int n;// leedcode数量
        Node p;// 父亲节点
        // 子节点链表
        LinkedList<Node> child = new LinkedList<>();

        public Node(int num) {
            this.num = num;
        }
    }

}

// 作者：Duncan_dsf
// 链接：https://leetcode-cn.com/problems/coin-bonus/solution/java-158ms-by-duncan_dsf/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
```