import java.util.*;
import java.io.*;

public class Main {
    static int[] dx = { 1, 0, -1, 0 };
    static int[] dy = { 0, -1, 0, 1 };
    static int[][] map, distance;
    static int m, n, startX, startY;
    static boolean[][] visit;
    
    static class Point {
        public int x, y;
        public Point(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }
    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder builder = new StringBuilder();
        String[] size = reader.readLine().split(" ");
        n = Integer.parseInt(size[0]);
        m = Integer.parseInt(size[1]);
        
        map = new int[n][m];
        distance = new int[n][m];
        visit = new boolean[n][m];
        
        for (int i = 0; i < n; i++) {
            map[i] = Arrays.stream(reader.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();
                for (int j = 0; j < m; j++) 
                    if (map[i][j] == 2) {
                        startX = i;
                        startY = j;
                        break;
                    }
        }
        
        bfs(startX, startY);
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) 
                if (!visit[i][j] && map[i][j] == 1)
                    builder.append(-1 + " ");
                else 
                    builder.append(distance[i][j] + " ");
            builder.append("\n");
        }
        
        System.out.print(builder.toString());
    }
    
    private static void bfs(int x, int y) {
        Queue<Point> q = new LinkedList<>();
        q.add(new Point(x, y));
        visit[x][y] = true;
        
        while (!q.isEmpty()) {
            Point now = q.poll();

            for (int i = 0; i < 4; i++) {
                int nx = now.x + dx[i];
                int ny = now.y + dy[i];
                
                if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
                if (map[nx][ny] == 0) continue;
                if (visit[nx][ny]) continue;

                q.add(new Point(nx, ny));
                distance[nx][ny] = distance[now.x][now.y] + 1;
                visit[nx][ny] = true;
            }
        }
    }
}