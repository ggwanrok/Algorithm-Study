

import java.util.*;

public class Main {

    static int n, m;
    static int[] nums;
    static boolean[] isUsed;
    static int[] seq;
    static StringBuffer sb = new StringBuffer(10000);

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        m = sc.nextInt();
        nums = new int[n];
        for (int i = 0; i < n; i++)
            nums[i] = sc.nextInt();
        isUsed = new boolean[n];
        Arrays.sort(nums);
        seq = new int[m];

        pick(0);
        System.out.print(sb);
    }

    public static void pick(int k) {
        if (k == m) {
            for (int i = 0; i < m; i++)
                sb.append(seq[i] + " ");
            sb.append('\n');
            return ;
        }

         int tmp = 0;
        for (int i = 0; i < n; i++) {
            if (isUsed[i] == true || tmp == nums[i])
            	continue ;

            isUsed[i] = true;
            seq[k] = nums[i];
             tmp = seq[k];
            pick(k + 1);
            isUsed[i] = false;
        }
    }
}