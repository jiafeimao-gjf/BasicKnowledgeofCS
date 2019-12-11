
package problemset.code;
import java.util.*;

public class Leedcode139_2 {
    public boolean wordBreak(String s, List<String> wordDict) {
        // 将单词字典转换成Set集合
        Set<String> wordDictSet = new HashSet(wordDict);
        // dp[] 状态数组，dp[i] 表示前i哥字符组成的字串能否被完全拆分
        boolean[] dp = new boolean[s.length() + 1];
        // 初始状态
        dp[0] = false;
        for (int i = 1;i <= s.length();i++) {//遍历每个位置
            for (int j = 0; j < i; j++) {
                // 判断字串的字串是否有满足条件的拆分
                // 前j个字符已经可以被正确拆分 且 后面的字符也恰好可以
                if (dp[j] && wordDictSet.contains(s.substring(j,i))) {
                    dp[i] = true;
                    break;// 退出查找
                }
            }
        }
        return dp[s.length()];
    }

    public static void main(String[] args) {
        String s = "aaaaaaaa";
        List<String> wordDict = new ArrayList<>();
        wordDict.add("aaaa");
        wordDict.add("aaa");
        wordDict.add("aa");
        boolean ret = new Leedcode139_2().wordBreak(s, wordDict);
        System.out.print(ret);
    }
}