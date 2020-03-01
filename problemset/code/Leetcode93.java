package problemset.code;

import java.util.*;
public class Leetcode93 {
    public static void main(String[] args) {
        Leetcode93 leetcode93 = new Leetcode93();
        long start = System.nanoTime();
        List<String> res = leetcode93.restoreIpAddresses("11111111111");
        long end = System.nanoTime();
        System.out.println("use " + (end - start)/1000000 + "ms");
        leetcode93.print(res);
        res.clear();
        start = System.nanoTime();
        res = leetcode93.restoreIpAddresses("1111111111");
        end = System.nanoTime();
        System.out.println("use " + (end - start)/1000000 + "ms");
        leetcode93.print(res);
    }
    private void print(List<String> res) {
        for (String str : res) {
            System.out.print(str+" ");
        }
        System.out.println();
    }
    int n;
    String s;
    List<String> res = new ArrayList<>();
    public List<String> restoreIpAddresses(String s){
        n = s.length();
        this.s = s;
        dfs(0,4,"");
        return res;
    }

    private void dfs(int index,int segment,String currIP) {
        // 超过四个字节
        if (segment < 0) return;
        // 处理了四个字节
        if(segment == 0){
            // 是一个有效解
            if(currIP.length() == n + 3) {
                // System.out.println("currIP: " + currIP);
                // 加入结果集
                res.add(currIP);
                return;
            }
        }
        // 处理一个结点
        for (int i = 1;i < 4;i++) {
            // 剩余足够的字符数
            if (n - index >= i) {
                int seg = Integer.parseInt(s.substring(index,index+i));
                if (seg <= 255) {
                    // 添加 .
                    String tmp = null;
                    if (segment != 1) {
                        tmp = "" + seg + ".";
                    } else {
                        tmp = "" + seg;
                    }
                    // System.out.println(currIP + tmp);
                    // 深度优先搜索
                    dfs(index + i,segment-1,currIP + tmp);
                }
            }
        }
    }
}