package problemset.code;

class Solution300 {
    // 最长连续子序列
    public int lengthOfLIS(int[] nums) {
        if (nums.length <= 1) return nums.length;
        int maxLen = 1;
        int len = nums.length;
        int[] dp = new int[len];
        dp[0] = 1;
        for (int i = 1;i < len; i++) {
            if (nums[i] >= nums[i-1]) { // 非严格递增
                dp[i] = dp[i-1] + 1;
            }else{
                dp[i] = 1;
            }
            System.out.print(dp[i]+" ");
            maxLen = Math.max(maxLen,dp[i]);
        }
        System.out.println();
        return maxLen;
     }
     public int lengthOfLIS1(int[] nums) {
        int[] tails = new int[nums.length];
        int res = 0;
        for (int num : nums) {
            int i = 0,j = res;
            // 查找插入的位置，第一个比num小的数字的下一个位置
            while(i < j) {
                int m = (i + j) / 2;
                if (tails[m] < num) {
                    i = m + 1;
                }else {
                    j = m;
                }
            }
            tails[i] = num;// 更新i处的数字，使其保持最小，给剩余数据添加可以增长的空间
            // num大于tail的最大值
            if (res == j) {res++;}
        }
        for(int t : tails){
            System.out.print(t+" ");
        }
        return res;
    }
}

public class Leetcode300 {
    public static void main(String[] args) {
        Solution300 solution = new Solution300();
        int[] nums = {10,9,2,5,7,4,3,6,7,18};
        System.out.println(solution.lengthOfLIS1(nums)); 
    }
}