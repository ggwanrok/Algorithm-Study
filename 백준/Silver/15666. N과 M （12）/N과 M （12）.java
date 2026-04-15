

import java.util.*;

public class Main
{

    private static int N;
    private static int M;
    private static int[] nums;
    private static int[] arr;
    private static boolean[] isVisited;
    private static HashSet<String> set = new HashSet<>();
    private static StringBuilder sb = new StringBuilder();

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        TreeSet<Integer> ts = new TreeSet<>();
        N = sc.nextInt();
        M = sc.nextInt();
        nums = new int[N];
        arr = new int[M];
        isVisited = new boolean[N];
        for (int i = 0; i < N; i++) {
            ts.add(sc.nextInt());
        }
        Iterator<Integer> it = ts.iterator();
        int q=0;
        while(it.hasNext()){
            nums[q] = it.next();
            q++;
        }
        N = ts.size();
        dfs(0);
        System.out.println(sb.toString());
    }

    private static void dfs(int depth) {
        if (depth == M) {
            StringBuilder sb2 = new StringBuilder();
            for (int i = 0; i < M; i++) {
                sb2.append(arr[i]).append(" ");
            }
            if (!set.contains(sb2.toString())) { // 중복제거
                sb.append(sb2.toString()).append("\n");
                set.add(sb2.toString());
            }
            return;
        }
        for (int i = 0; i < N; i++) {
                if(depth > 0 && arr[depth-1] > nums[i]) continue;
                arr[depth] = nums[i];
                dfs(depth + 1);
        }

    }

}