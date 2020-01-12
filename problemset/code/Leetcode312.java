package problemset.code;

class BurstBalloons {
    public int maxCoins(int[] nums) {
        // 边界判断
        if (nums.length == 0) return 0;
        
        // 进行每一轮的择优
        int sum = 0;
        for (int i = 0;i < nums.length;i++) {
            int maxi = 0;
            int mark = 0;
            for (int j = 0;j < nums.length;j++) {
                if (nums[j] == -1) { continue;}
                // 向左找边界
                int l = j - 1,left;
                while(l >= 0 && nums[l] == -1) {
                    l--;
                }
                if (l == -1) {
                    left = 1;
                } else{
                    left = nums[l];
                }
                // 向右找边界
                int r = j + 1,right;
                while(r < nums.length && nums[r] == -1) {
                    r++;
                }
                if (r == nums.length) {
                    right = 1;
                } else{
                    right = nums[r];
                }
                System.out.print("left: "+ left);
                System.out.print(", nums[j]: "+ nums[j]);
                System.out.println(", right: "+ right);
                maxi = Math.max(left*nums[j]*right,maxi);
                mark = j;
            }
            System.err.println(i+": "+maxi);
            sum += maxi;
            nums[mark] = -1;
        }
        return sum;
    }
    public int maxCoins1(int[] nums) {
        // 边界判断
        if (nums.length == 0) return 0;

        // 进行每一轮的择优
        int sum = 0;
        for (int i = 0;i < nums.length;i++) {
            int mini = -1;
            for (int j = 1;j < nums.length - 1;j++) {
                if (nums[j] == -1) { continue;}
                if (mini == -1) {mini = j;continue;}
                mini = nums[j] > nums[mini] ? mini : j;
            }
            if (mini == -1) {continue;}
            // 向左找边界
            int l = mini - 1,left;
            while(l > 0 && nums[l] == -1) {
                l--;
            }
            if (l <= 0) {
                left = nums[0];
            } else{
                left = nums[l];
            }
            // 向右找边界
            int r = mini + 1,right;
            while(r < nums.length - 1 && nums[r] == -1) {
                r++;
            }
            if (r >= nums.length - 1) {
                right = nums[nums.length - 1];
            } else{
                right = nums[r];
            }
            sum += left*nums[mini]*right;
            System.out.print("left: "+ left);
            System.out.print(", nums[j]: "+ nums[mini]);
            System.out.println(", right: "+ right);
            nums[mini] = -1;
        }
        sum += nums[0] * nums[nums.length - 1];
        // 处理边界值
        if(nums[0] > nums [nums.length - 1]) {
            sum += nums[0];
        }else {
            sum += nums[nums.length - 1];
        }
        return sum;
    }
    public static void main(String[] args) {
        BurstBalloons balloons = new BurstBalloons();
        int[] nums = {3,1,5,8};
        int res = balloons.maxCoins(nums);
        System.err.println("result: " + res);
        int[] nums1 = {3,1,5,8};
        res = balloons.maxCoins1(nums1);
        System.err.println("result: " + res);
    }
 }