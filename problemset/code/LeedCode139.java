package problemset.code;

import java.util.*;

class Solution {
    public boolean wordBreak(String s, List<String> wordDict) {
        Map<Integer,List<String> > wordMap = new HashMap<>();
        
        // 初始化Hash表
        for (int i = 0;i < wordDict.size();i++) {
            String word = wordDict.get(i);
            if (!wordMap.containsKey(word.length())) {
                List<String> v = new ArrayList<>();
                v.add(word);
                wordMap.put(word.length(),v);
            } else {
                wordMap.get(word.length()).add(word);
            }
        }
        
        // 查找是否有对应的
        int i = 0;
        // dp[i][j]
        Integer[] keys = wordMap.keySet().toArray(new Integer[0]);
        // 循环
        for(int j = 0;j < keys.length + 1;j++) {
            // 匹配完毕
            if(i == s.length()) break;
            int old = i;// 保存
            // 匹配
            for (int k : keys) {
                if (i + k <= s.length()) {
                    String sub = s.substring(i,i+k);
                    System.out.println(i+"-"+sub);
                    if (wordMap.get(k).contains(sub)) { // 贪心，找到合适的就不找了
                        i += k;
                        // continue;
                    }else {
                        i = old;
                    }
                }
            }
            // if (old == i && i < s.length()) {
            //     break;
            // }
        }
        if (i == s.length()){
            return true;
        }else {
            return false;      
        }
    }
}

public class LeedCode139 {
   
    
    public static void main(String[] args)  {
        String s = "aaaaaaaa";
        List<String> wordDict = new ArrayList<>();
        wordDict.add("aaaa");
        wordDict.add("aaa");
        wordDict.add("aa");
        boolean ret = new Solution().wordBreak(s, wordDict);
        System.out.print(ret);
//         while ((line = in.readLine()) != null) {
//             String s = stringToString(line);
//             line = in.readLine();
//             List<String> wordDict = stringToStringList(line);
            
//             boolean ret = new Solution().wordBreak(s, wordDict);
            
//             String out = booleanToString(ret);
            
//             System.out.print(out);
//         }
    }
}