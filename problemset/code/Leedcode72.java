package problemset.code;

public class Leedcode72{

    public static void main(String[] args) {
        Leedcode72 leedcode72 = new Leedcode72();
        int res = leedcode72.minDistance("horse", "ros");
        System.out.println(res);
        res = leedcode72.minDistance("horse", "house");
        System.out.println(res);
        res = leedcode72.minDistance("romantic", "ros");
        System.out.println(res);
    }

    public int minDistance(String word1,String word2){
        int n = word1.length();
        int m = word2.length();
        if (n*m == 0) {
            return n + m;
        } 
        int[][] d = new int[n + 1][m + 1];
        // 初始化
        for (int i = 0;i <= n;i++) {
            d[i][0] = i;
        }

        for (int j =0;j <= m;j++) {
            d[0][j] = j;
        }

        // 枚举所有情况，找到最优解
        for (int i = 1;i < n+1;i++){
            for (int j = 1;j < m+1;j++) {
                int left = d[i - 1][j] + 1;
                int down = d[i][j-1] + 1;
                int left_down =  d[i-1][j-1];
                if (word1.charAt(i - 1) != word2.charAt(j - 1)) {
                    left_down += 1;
                }
                d[i][j] = Math.min(left, Math.min(down, left_down));
            }
        }

        return d[n][m];
    }
}