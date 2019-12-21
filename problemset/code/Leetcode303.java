package problemset.code;

class NumArray {
    private int[][] dp;
    // 线段树 ？？？
    public NumArray(int[] nums) {
        dp = new int[nums.length][];
        int len = nums.length;
        for(int i = 0;i < len;i++) {
            dp[i] = new int[len - i];// 初始化数组
            dp[i][0] = nums[i];
            for (int j = i+1;j < len;j++) {
                    dp[i][j-i] = dp[i][j-i-1] + nums[j];
            }
        }
        print(dp);
    }
    public void print(int[][] nums){
        for (int[] n : nums) {
            for (int a:n) {
                System.out.print(a+" ");
            }
            System.out.println();
        }
    }

    public int sumRange(int i, int j) {
        return dp[i][j-i];
    }
}

public class Leetcode303 {
    public static void main(String[] args) {
        int[] nums = {-2, 0, 3, -5, 2, -1};
        NumArray numArray = new NumArray(nums);
        System.out.println(numArray.sumRange(0, 2));
        System.out.println(numArray.sumRange(2, 5));
        System.out.println(numArray.sumRange(0, 5));
    }
}