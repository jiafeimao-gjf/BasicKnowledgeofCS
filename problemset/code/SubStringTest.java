package problemset.code;

class SubStringTest{
    public static void main(String[] args) {
        String str = "ABCDEFG";
        System.out.println(str);
        for (int i = 1;i <= str.length();i++) {
            System.out.println(str.substring(0,i));
        }
    }
}