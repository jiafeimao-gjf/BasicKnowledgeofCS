## LCP4、机器人大冒险

力扣团队买了一个可编程机器人，机器人初始位置在原点(0, 0)。小伙伴事先给机器人输入一串指令command，机器人就会无限循环这条指令的步骤进行移动。指令有两种：

1. U: 向y轴正方向移动一格
2. R: 向x轴正方向移动一格。

不幸的是，在 xy 平面上还有一些障碍物，他们的坐标用obstacles表示。机器人一旦碰到障碍物就会被损毁。

给定终点坐标(x, y)，返回机器人能否完好地到达终点。如果能，返回true；否则返回false。

 

### 示例 1：
```
输入：command = "URR", obstacles = [], x = 3, y = 2
输出：true
解释：U(0, 1) -> R(1, 1) -> R(2, 1) -> U(2, 2) -> R(3, 2)。
```
### 示例 2：
```
输入：command = "URR", obstacles = [[2, 2]], x = 3, y = 2
输出：false
解释：机器人在到达终点前会碰到(2, 2)的障碍物。
```
### 示例 3：
```
输入：command = "URR", obstacles = [[4, 2]], x = 3, y = 2
输出：true
解释：到达终点后，再碰到障碍物也不影响返回结果。
```

#### 限制：
```
2 <= command的长度 <= 1000
command由U，R构成，且至少有一个U，至少有一个R
0 <= x <= 1e9, 0 <= y <= 1e9
0 <= obstacles的长度 <= 1000
obstacles[i]不为原点或者终点
```
<!-- 来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/programmable-robot
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。 -->

## 思路
- 判断终点是否在运动轨迹中
- 判断障碍点是否在轨迹中
- 如何确定轨迹，将每个点按照轨迹移动到第一个循环内就可以判断

### 如何存储机器人的轨迹坐标？
考虑到 `0 <= x <= 1e9, 0<=y<=1e9`，可以将所有点的横坐标左移 30 位，和纵坐标做按位或运算，再存储到哈希集合中。接下来只需按照两个条件一一查找相应的坐标即可。

<!-- 作者：yanghk
链接：https://leetcode-cn.com/problems/programmable-robot/solution/c-4ms-jie-da-by-yanghk/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。 -->

## 代码
- 巧妙计算，他人的代码
```C++
bool robot(string command, vector<vector<int>> & obstacles,int x,int y){
    // 存储轨迹
    int xx = 0,yy = 0;
    s.insert(0);
    for (auto c : command) {
        if (c == 'U') {yy++;}
        else if (c == 'C') {xx++};
        s.insert(((long)xx << 30) | y);
    }

    // 判断目标点是否在轨迹上
    int circle = min(x/xx,y/yy);
    // set的count统计目标在集合中出现的次数
    if (s.count(((long)(x-circle*xx) <<30) | (y - circle*yy)) == 0) return false;

    // 判断每个障碍是否在轨迹上
    for (auto v : obstacles) {
        if (v.size() != 2) continue;
        if (v[0] > x || v[1] > y) continue;
        circle = min(v[0]/xx,v[1]/yy);
        if (s.count(((long)(v[0] - circle*xx) << 30) | (v[1] - circle*yy))) return false;
    }

    return true;
}

```
- 借鉴了之后，我的代码
```java
class Solution {
    public boolean robot(String command, int[][] obstacles, int x, int y) {
        char[] commands = command.toCharArray();// 命令列表
        int x0 = 0,y0 = 0;
        // 将第一个循环的点记录到集合中
        Set<String> set = new HashSet<String>();
        set.add("0-0");
        for (int k = 0;k < commands.length;k++){
            if (commands[k] == 'U') {
                y0++;
            }else if(commands[k] == 'R'){
                x0++;
            }
            set.add(x0+"-"+y0);// 加入轨迹到集合中
        }
        
        int circle = Math.min(x/x0,y/y0);
        if (!set.contains((x - circle*x0)+"-"+(y - circle*y0))) return false;
        
        // 判断每一个障碍点是否在轨迹内
        for (int[] point : obstacles) {
            if(point[0] > x || point[1] > y) continue;// 在目标点之后
            circle = Math.min(point[0]/x0,point[1]/y0);
            if (set.contains((point[0] - circle*x0)+"-"+(point[1] - circle*y0))) return false;
        }
        return true;
    }
}
```