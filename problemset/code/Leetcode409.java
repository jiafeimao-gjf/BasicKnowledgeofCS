package problemset.code;

import java.util.Map;
import java.util.stream.Collectors;

public class Leetcode409 {
    public static void main(String[] args) {
        Leetcode409 leedcode409 = new Leetcode409();
        int res = leedcode409.longestPalindrome("aabbccddddeees");
        System.out.println("res = " + res);
    }

    public int longestPalindrome(String s) {
        // ChasSequence#chars()
        // IntStream#Boxed()
        // Stream#collect()
        // Collectors#toMap()
        Map<Integer, Integer> count = s.chars().boxed()
              .collect(Collectors.toMap(k -> k, v -> 1, Integer::sum));
        // Stream#mapToInt()
        int ans = count.values().stream().mapToInt(i -> i - (i & 1)).sum();
        return ans < s.length() ? ans + 1 : ans;
      }
}
