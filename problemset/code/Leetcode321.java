package problemset.code;

import java.util.Arrays;
import java.util.Stack;

class Leetcode321 {
    public int[] maxNumber(int[] num1,int[] num2,int k) {
        int[] res = null;
        int len1 = num1.length;
        int len2 = num2.length;
        System.out.println("num1: ");
        print(num1);
        System.out.println("num2: ");
        print(num2);
        boolean first = true;
        for (int i = Math.max(0,k-len2);i <= Math.min(k,len1);i++) {
            int[] sub1 = subSequence(num1,i);
            System.out.println("sub1-"+i+": ");
            print(sub1);
            int[] sub2 = subSequence(num2,k-i);
            System.out.println("sub2-"+i+": ");
            print(sub2);
            int[] tmp = merge(sub1,sub2);
            System.out.println("tmp: ");
            print(tmp);
            if (first) {
                res = tmp;
                first = false;
            }else {
                res = maxSubSequence(res,tmp)?res:tmp;
            }
            System.out.println("res: ");
            print(res);
        }
        return res;
    }

    private int[] subSequence(int[] nums,int k) {
        int l = nums.length;
        if (l <= k) return nums;

        int drop = l - k;

        int[] ans = new int[k];
        if (k == 0) return ans;
        Stack<Integer> stack = new Stack<>();
        for (int i = 0; i < l; i++) {
            while (!stack.empty() && nums[i] > stack.peek() && drop-- > 0) {
                stack.pop();
            }
            stack.push(nums[i]);
        }
        // 裁剪大小
        while (stack.size() > k) stack.pop();
        
        for (int i = k - 1;i >=0 ;i--) {
            ans[i] = stack.pop();
        }
        return ans;
    }

    private void print(int[] nums) {
        for (int item : nums) {
            System.out.print(item+" ");
        }
        System.out.println();
    } 

    // 有问题
    private int[] merge(int[] nums1,int[] nums2) {
        int l1 = nums1.length;
        int l2 = nums2.length;
        if(l1==0) return nums2;
        if(l2==0) return nums1;
        int ans[] = new int[l1+l2];
        int i1 = 0;
        int i2 = 0;
        for(int i=0;i<l1+l2;i++){
            if(maxSubSequence(Arrays.copyOfRange(nums1, i1, l1),Arrays.copyOfRange(nums2, i2, l2))){
                ans[i] = nums1[i1++];
            }
            else{
                ans[i] = nums2[i2++];
            }
        }
        return ans;
    }

    // true -> nums1 > nums2
    private boolean maxSubSequence(int[] nums1,int[] nums2) {
        // 求出长度较小的值
        int n = Math.min(nums1.length,nums2.length);
        for(int i=0;i < n;i++){
            if(nums1[i] > nums2[i]) return true;
            else if(nums1[i] < nums2[i]) return false;
            else continue;
        }
        return nums1.length > nums2.length;
    }
    public static void main(String[] args) {
        Leetcode321 leetcode321 = new Leetcode321();
        int[] num1 = {3,4,6,5};
        int[] num2 = {9, 1, 2, 5, 8, 3};
        leetcode321.maxNumber(num1, num2, 5);
        System.out.println("-------------------------------");
        int[] num3 = {6,7};
        int[] num4 = {6,0,4};
        leetcode321.maxNumber(num3, num4, 5);
    }
}