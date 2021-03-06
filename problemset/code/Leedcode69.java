package problemset.code;
public class Leedcode69{
    public static void main(String[] args) {
        Leedcode69 leedcode69 =new Leedcode69();
        int res = leedcode69.mySqrt(21);
        System.out.println(res);
        res = leedcode69.mySqrt(4);
        System.out.println(res);
        res = leedcode69.mySqrt(223141411);
        System.out.println(res);
        res = leedcode69.mySqrt(21234231);
        System.out.println(res);
        res = leedcode69.mySqrt(22221);
        System.out.println(res);
        res = leedcode69.sqrt(Integer.MAX_VALUE);
        System.out.println(res);
        System.out.println("-----------------------");
        res = leedcode69.sqrt(21);
        System.out.println(res);
        res = leedcode69.sqrt(4);
        System.out.println(res);
        res = leedcode69.sqrt(223141411);
        System.out.println(res);
        res = leedcode69.sqrt(21234231);
        System.out.println(res);
        res = leedcode69.sqrt(22221);
        System.out.println(res);
        res = leedcode69.sqrt(Integer.MAX_VALUE);
        System.out.println(res);
        System.out.println("-----------------------");
        res = leedcode69.binarySqrt(21);
        System.out.println(res);
        res = leedcode69.binarySqrt(4);
        System.out.println(res);
        res = leedcode69.binarySqrt(223141411);
        System.out.println(res);
        res = leedcode69.binarySqrt(21234231);
        System.out.println(res);
        res = leedcode69.binarySqrt(22221);
        System.out.println(res);
        res = leedcode69.binarySqrt(Integer.MAX_VALUE);
        System.out.println(res);
    }
    

    public int mySqrt(int x) {
        if (x == 1 || x == 0) return x;
        int res = 1;
        for (int i = 1;i < x -1;i*=2) {
            if (i*i == x){
                res = i;
                break;
            }else if (i*i > x) {
                for(int j = i - 1;j > 0;j--) {
                    if (j*j <= x && (j+1)*(j+1) > x){
                        res = j;
                        break;
                    }
                }
                if (res != 1)  {
                    break;
                }
            }
        }
        return res;
    }

    int sqrt(int x){
        int res =1;
        double pre = 0;
        double cur = x;
        while(Math.abs(cur - pre) > 0.000001) {
            pre = cur;
            cur  = (pre/2 + x/(2*pre));
        }
        res = (int) cur;
        return res;
    }

    int binarySqrt(int x) {
        int res = 1;
        double begin = 0;
        double end = x;
        double result = 1;
        double mid = 1;
        while (Math.abs(result - x) > 0.000001) {
            mid = (begin + end)/2;
            result = mid*mid;
            if (result > x){
                end = mid;
            } else {
                begin = mid;
            }
        }
        res = (int) mid;
        return res;
    }
}