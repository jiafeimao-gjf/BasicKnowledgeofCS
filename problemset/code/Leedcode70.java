package problemset.code;

public class Leedcode70{

    public static void main(String[] args) {
        Leedcode70 leedcode70 = new Leedcode70();
        int res = leedcode70.climbStairs(2);
        System.out.println(res);
        res = leedcode70.climbStairs(4);
        System.out.println(res);
        res = leedcode70.climbStairs(5);
        System.out.println(res);
        res = leedcode70.climbStairs(70);
        System.out.println(res);
    }

    public int climbStairs(int n) {
        if (n == 1 || n ==  2) return n;
        int f1 = 1;
        int f2 = 2;
        int count = 3;
        while (count <= n){
            int t = f2;
            f2 = f1 + f2;
            f1 = t;
            count ++;
        }
        return f2;
    }
}