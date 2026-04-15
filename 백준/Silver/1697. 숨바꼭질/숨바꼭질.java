
import java.io.*;
import java.util.*;

public class Main {
    static int maxDistance = 100_000;
    static int N;
    static int K;
    static int[] location = new int[maxDistance+1];
    static boolean[] visited = new boolean[maxDistance+1];
    static Queue<Integer> queue = new LinkedList<>();

    public static void bfs(int X) {
        queue.add(X);

        while(!queue.isEmpty()) {
            int current = queue.poll();

            if (current == K) {
                System.out.println(location[K]);
                break;
            }

            int[] dir = { current-1, current+1, current*2 };

            for (int i = 0; i < 3; i++) {
                if (0 <= dir[i] && dir[i] <= maxDistance) {
                    if (!visited[dir[i]]) {
                        visited[dir[i]] = true;
                        location[dir[i]] = location[current]+1;
                        queue.add(dir[i]);
                    }
                }
            }
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        K = Integer.parseInt(st.nextToken());

        if (K <= N) System.out.println(N-K);

        else {
            location[N] = 0;
            visited[N] = true;
            bfs(N);
        }
    }
}