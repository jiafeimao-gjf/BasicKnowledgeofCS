package javaTest;

public class StringTest{
    static String str = "abcdefg";

    static void stringTest(int index,String s){
        if (index == str.length()) return;
        System.out.println(s+str.charAt(index));
        stringTest(index+1, s+str.charAt(index));
    }

    public static void main(String[] args) {
        stringTest(0, "");
    }
}