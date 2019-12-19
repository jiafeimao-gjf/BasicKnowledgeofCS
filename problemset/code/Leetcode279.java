package problemset.code;

class Leetcode279 {
    public int numSquares(int n) {
        int[] dp = new int[n+1];
        dp[0] = 0;
        for(int i = 1;i*i < n;i++) {
            dp[i*i] = 1;
        }
        if(dp[n] == 1) return dp[n];
        for (int i = 2;i <= n;i++) {
            if (dp[i] != 1) {
                dp[i] = i;
                // 带优化
                for (int j = i - 1;j >= 0;j--) {
                    if (dp[j] == 1) {// 有效值
                        // 更新最少的完全平方数的个数
                        dp[i] = Math.min(dp[i],dp[i-j]+1);
                    }
                }
            }
            System.out.println(i +" "+ dp[i]);
        }
        return dp[n];
    }

    public static void main(String[] args) {
        Leetcode279 l279 = new Leetcode279();
        // System.out.println(l279.numSquares(12));
        // System.out.println(l279.numSquares(13));
        System.out.println(l279.numSquares(1234431215));
    }
}