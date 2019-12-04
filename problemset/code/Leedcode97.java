package problemset.code;

public class Leedcode97{
    public static void main(String[] args) {
        Leedcode97 leedcode97 = new Leedcode97();
        System.out.println(leedcode97.isInterleave("aabcc", "dbbcasjk", "aadbbcbcasjkc"));
        System.out.println(leedcode97.isInterleave("aabcc", "dbbca", "aadbbbaccc"));
    }

    public boolean isInterleave(String s1, String s2, String s3) {
        if (s1.length() == 0 && s2.length() == 0 && s3.length() == 0) return true;
        if (s3 == null || s3.length() == 0) return false;
        if (s3.length() != (s1.length() + s2.length())) return false;
        return isInterleaveCore(s1,0,s2,0,s3,0);
    }
    
    private boolean isInterleaveCore(String s1,int i,String s2,int j,String s3,int k) {
        if ((i+j) == k && k == s3.length()) return true;
        if (i < s1.length() && j < s2.length()) {
            if (s1.charAt(i) == s2.charAt(j) && s1.charAt(i) == s3.charAt(k)) {
                return isInterleaveCore(s1,i+1,s2,j,s3,k+1) || isInterleaveCore(s1,i,s2,j+1,s3,k+1);
            } else if (s1.charAt(i) == s3.charAt(k)){
                return isInterleaveCore(s1,i+1,s2,j,s3,k+1);
            } else if (s2.charAt(j) == s3.charAt(k)) {
                return isInterleaveCore(s1,i,s2,j+1,s3,k+1);
            }
        } else if (i < s1.length() && s1.charAt(i) == s3.charAt(k)){
            return s1.substring(i).equals(s3.substring(k));
        } else if (j < s2.length() && s2.charAt(j) == s3.charAt(k)) {
            return s2.substring(j).equals(s3.substring(k));
        }
        return false; 
    }
}
