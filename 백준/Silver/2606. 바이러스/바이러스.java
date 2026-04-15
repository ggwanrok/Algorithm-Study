

import java.io.*;
import java.util.StringTokenizer;


public class Main{

    static int num;
    public static void main(String[] args) throws NumberFormatException, IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));



        int N = Integer.parseInt(br.readLine());
        num = N;
        int M = Integer.parseInt(br.readLine());

        int[][] matrix = new int[N][N];
        int[] arr = new int[N];
        StringTokenizer st;

        for (int i = 0; i < M; i++) {
            st = new StringTokenizer(br.readLine());
            int key = Integer.parseInt(st.nextToken());
            int value = Integer.parseInt(st.nextToken());
            matrix[key - 1][value - 1] = 1;
            matrix[value - 1][key - 1] = 1;
        }

        dfs(0, arr, matrix);

        int cnt = 0;
        for (int i = 0; i < num; i++) {
            if (arr[i] == 1) {
                cnt++;
            }
        }
        bw.write(String.valueOf(cnt - 1));
        bw.flush();
        bw.close();
    }

    static void dfs(int i, int[] arr, int[][] matrix) {
        if (arr[i] == 0) {
            arr[i] = 1;
            for (int j = 0; j < num; j++) {
                if (matrix[i][j] == 1) {
                    dfs(j, arr, matrix);
                }
            }
        }
    }
}
