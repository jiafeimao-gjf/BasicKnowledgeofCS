package problemset.code;

import java.util.Stack;

public class Leedcode71 {
    public static void main(String[] args) {
        Leedcode71 leedcode71 = new Leedcode71();
        String res =  leedcode71.simplifyPath("/home");
        System.out.println(res);
        res =  leedcode71.simplifyPath("/../");
        System.out.println(res);
        res =  leedcode71.simplifyPath("/home//foo/");
        System.out.println(res);
        res =  leedcode71.simplifyPath("/a/./b/../../c/");
        System.out.println(res);
        res =  leedcode71.simplifyPath("/a/../../b/../c//.//");
        System.out.println(res);
        res =  leedcode71.simplifyPath("/a/b////c/d//././/..");
        System.out.println(res);
        System.out.println("--------------------------------");
        res =  leedcode71.simplifyPath1("/home");
        System.out.println(res);
        res =  leedcode71.simplifyPath1("/../");
        System.out.println(res);
        res =  leedcode71.simplifyPath1("/home//foo/");
        System.out.println(res);
        res =  leedcode71.simplifyPath1("/a/./b/../../c/");
        System.out.println(res);
        res =  leedcode71.simplifyPath1("/a/../../b/../c//.//");
        System.out.println(res);
        res =  leedcode71.simplifyPath1("/a/b////c/d//././/..");
        System.out.println(res);
    }

    public String simplifyPath(String path) {
        StringBuilder sb = new StringBuilder();
        Stack<String> sk = new Stack<String>();
        String[] paths = path.split("/");
        int jump = 0;
        for (int i = paths.length - 1;i >= 0;i--){
            if (paths[i].equals("") || paths[i].equals(".")){
                continue;
            }else if(paths[i].equals("..")){
                jump++;
            }else {
                if (jump == 0){
                    sk.add(paths[i]);
                } else {
                    jump--;
                }
            }
        }
        if (sk.isEmpty()){
            sb.append("/");
        }
        while(!sk.isEmpty()){
            sb.append("/" + sk.pop());
        }
        return sb.toString();
    }

    public String simplifyPath1(String path) {
        String[] s = path.split("/");
        Stack<String> stack = new Stack<>();
        
        for (int i = 0; i < s.length; i++) {
            if (!stack.isEmpty() && s[i].equals(".."))
                stack.pop();
            else if (!s[i].equals("") && !s[i].equals(".") && !s[i].equals(".."))
                stack.push(s[i]);
        }
        if (stack.isEmpty())
            return "/";

        StringBuffer res = new StringBuffer();
        for (int i = 0; i < stack.size(); i++) {
            res.append("/" + stack.get(i));
        }
        return res.toString();
    }

// 作者：StackOverflow-
// 链接：https://leetcode-cn.com/problems/simplify-path/solution/java-yi-dong-yi-jie-xiao-lu-gao-by-spirit-9-18/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
}