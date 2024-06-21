---
title: LCP61.气温变化趋势
categories:
  - leetcode
tags:
  - 滑动窗口
  - 数组
  - 单调性
date: 2024-06-21 11:18:36
---

## 题目
力扣城计划在两地设立「力扣嘉年华」的分会场，气象小组正在分析两地区的气温变化趋势，对于第 i ~ (i+1) 天的气温变化趋势，将根据以下规则判断：

- 若第 i+1 天的气温 高于 第 i 天，为 上升 趋势
- 若第 i+1 天的气温 等于 第 i 天，为 平稳 趋势
- 若第 i+1 天的气温 低于 第 i 天，为 下降 趋势

已知 temperatureA[i] 和 temperatureB[i] 分别表示第 i 天两地区的气温。 组委会希望找到一段天数尽可能多，且两地气温变化趋势相同的时间举办嘉年华活动。请分析并返回两地气温变化趋势相同的最大连续天数。

即最大的 n，使得第 i~i+n 天之间，两地气温变化趋势相同

### 示例 1：
![](/images/lcp61-1.png)
```
输入： temperatureA = [21,18,18,18,31] temperatureB = [34,32,16,16,17]

输出：2

解释：如下表所示， 第 2～4 天两地气温变化趋势相同，且持续时间最长，因此返回 4-2=2

```


### 示例 2：
```
输入： temperatureA = [5,10,16,-6,15,11,3] temperatureB = [16,22,23,23,25,3,-16]

输出：3
```

**提示：**

- `2 <= temperatureA.length == temperatureB.length <= 1000`
- `-20 <= temperatureA[i], temperatureB[i] <= 40`

## 分析

### 单调性同步窗口

```java
class Solution {
    public int temperatureTrend(int[] temperatureA, int[] temperatureB) {
        
        int l = 0;
        int r = 0;
        int n = temperatureA.length;
        int[] ta = temperatureA;
        int[] tb = temperatureB;
        int max = 0;
        boolean same = false;
        for (int i = 1;i < n;i++) {
            // 计算 diff
            int diffA = ta[i] - ta[i - 1];
            int diffB = tb[i] - tb[i - 1];
            if ((diffA == 0 && diffB == 0) || diffA * diffB > 0 ) {
                // 由不同转相同
                if (!same) {
                    same = true;
                    l = r;
                }
            } else{
                same = false;
            }
            // 只有趋势一致的时候才进行更新最大值
            if(same) {
                max = Math.max(max, r - l + 1);
            }
            r++;
        }

        return max;
    }
}
```

### 统计连续相同的天数，累加

```java
class Solution {
    public int temperatureTrend(int[] temperatureA, int[] temperatureB) {
        
        int n = temperatureA.length;
        int[] ta = temperatureA;
        int[] tb = temperatureB;
        int count = 0;
        int maxCount = 0;
        for (int i = 1;i < n;i++) {
            // 计算 diff
            int diffA = ta[i] - ta[i - 1];
            int diffB = tb[i] - tb[i - 1];
            if ((diffA == 0 && diffB == 0) || diffA * diffB > 0 ) {
                maxCount = Math.max(maxCount, ++count);
            } else{
                count = 0;
            }
        }

        return maxCount;
    }
}
```