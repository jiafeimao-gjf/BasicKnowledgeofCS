package problemset.code;

import java.util.Arrays;
import java.util.Comparator;
import java.util.*;

/**
 * 通用模板
 */
class Solution3169 {
    public int countDays(int days, int[][] meetings) {
        // 1、按照开始时间排序会议 从小到大排序
        Arrays.sort(meetings, new Comparator<int[]>() {
            @Override
            public int compare(int[] o1, int[] o2) {
                return o1[0] - o2[0];
            }
        }
        );

        // 2、合并重叠的会议区间
        List<int[]> merged = new ArrayList<>();

        for (int[] interval : meetings) {
            if (merged.isEmpty() || interval[0] > merged.get(merged.size() - 1)[1]) {
                merged.add(interval);
            } else {
                merged.get(merged.size() - 1)[1] = Math.max(merged.get(merged.size() - 1)[1], interval[1]);
            }
        }
        // 3、计算合并区间的总天数
        int meetingDatsCount = 0;
        for (int[] interval : merged) {
            int start = Math.max(1, interval[0]);
            int end = Math.min(days, interval[1]);
            if (start <= end) {
                meetingDatsCount += end - start + 1;
            }

        }
        // 4、计算剩余天数
        return days - meetingDatsCount;
    }
}

/**
 *
 */

public class Leetcode3169 {

    public static void main(String[] args) {
        int[][] meetings = {{5, 7}, {1, 3}, {9,10}};
        Solution3169 solution = new Solution3169();
        int count = solution.countDays(10, meetings);
        System.out.println("总天数是10， 会议列表 {{5, 7}, {1, 3}, {9,10}} 的答案是 " + count);
    }



}
