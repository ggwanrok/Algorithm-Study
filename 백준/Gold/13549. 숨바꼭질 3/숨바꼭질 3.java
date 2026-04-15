import java.util.*;

public class Main {
    static int N,K;
    static int arr[];

    public static void main(String args[]) throws Exception {

        Scanner sc = new Scanner(System.in);

        N = sc.nextInt(); // 5
        K = sc.nextInt(); // 17
        arr = new int[100002];

        Arrays.fill(arr, 100000);

        if (N == K) {
            System.out.println("0");
            return;
        }
        if (K < N) {
            System.out.println(N - K);
            return;
        }

        Queue<List> q = new LinkedList();

        q.add(Arrays.asList(N,0)); // 5, 0 (현재위치, 소요시간)

        int ans = Integer.MAX_VALUE;

        while(!q.isEmpty()){
            List out = q.poll(); // 5 , 0

            int cur = (int) out.get(0); // 5
            int time = (int) out.get(1); // 0

            

            arr[cur] = Math.min(arr[cur], time);

            // 2를 곱했을 때, 1을 더했을 때, 1을 뺐을 때를 각각 q에 넣어준다

            List nextP = Arrays.asList(cur+1, time+1);
            List nextN = Arrays.asList(cur-1, time+1);
            List next2X = Arrays.asList(cur*2, time);

//            System.out.println("cur : " + cur + " | time : " + time + " | 다음+1 이동위치 : " + nextP.get(0) + " | 다음-1 이동위치 : " + nextN.get(0) + " | 2배 순간이동 위치 : " + next2X.get(0) + " | ans : " + ans);

            if ((int)nextP.get(0) == K) {
                ans = Math.min(ans, (int)nextP.get(1));
            }
            if ((int)nextN.get(0) == K) {
                ans = Math.min(ans, (int)nextN.get(1));
            }
            if ((int)next2X.get(0) == K) {
                ans = Math.min(ans, (int)next2X.get(1));
            }

            if ((int)nextP.get(0)<=K+1 && (int)nextP.get(1) < arr[(int)nextP.get(0)]) q.add(nextP); // 다음에 +1로 이동할 좌표가 K+1 범위이내에 있고, 다음에 이동할 좌표의 time값이 이미 arr 배열에 들어있는 time값보다 작을 때만 큐에 넣어준다.
            if ((int)nextN.get(0)>=0 && (int)nextN.get(1) < arr[(int)nextN.get(0)]) q.add(nextN);
            if ((int)next2X.get(0)<=K+1 && (int)next2X.get(1) < arr[(int)next2X.get(0)]) q.add(next2X);
        }

        System.out.println(ans);

    }
}
