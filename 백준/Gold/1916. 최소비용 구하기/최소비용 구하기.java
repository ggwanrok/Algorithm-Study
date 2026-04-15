
import java.util.Scanner;

public class Main {


    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int m = scanner.nextInt();//m개의 도시
        int n = scanner.nextInt();//n개의 노선
        int[] shortest = new int[m];//노익스트라
        boolean[] fix = new boolean[m]; //고정이 된 치
        for(int i=0; i<m; i++){
            shortest[i] = 1000000000;
        }
        int[][][] price = new int[m][m][2];//인접행렬로 구현한 문제이고, 마지막 배열은 픽스 유무이다.

        for(int i=0; i<n; i++){
            int var1 = scanner.nextInt()-1;
            int var2 = scanner.nextInt()-1;
            int var3 = scanner.nextInt();
            if(price[var1][var2][1] != 0){
                if(var3 > price[var1][var2][0]){
                    continue;
                }
            }
            price[var1][var2][0] = var3;
            price[var1][var2][1] = 1; // 경로가 있을을 뜻한다.
        }

        int startPoint = scanner.nextInt()-1;
        int endPoint = scanner.nextInt()-1;

        shortest[startPoint] = 0;
        fix[startPoint] = true;

        int index = startPoint;
        int sIndex = 1000000000;
        for(int j=0; j<m-1; j++){
            for(int i=0; i<m; i++){
                if(i==index){
                    continue;
                }
                if(price[index][i][1] == 1){
                    if(shortest[i] > shortest[index] + price[index][i][0]){
                        shortest[i] = shortest[index] + price[index][i][0];
                    }
                }
            }
            for(int i=0; i<m; i++){
                if(fix[i]){
                    continue;
                }
                if(shortest[i] < sIndex){
                    sIndex = shortest[i];
                    index = i;
                }
            }
            sIndex = 1000000000;
            fix[index] = true;
            if(index == endPoint){
                break;
            }
        }

        System.out.println(shortest[endPoint]);

    }

}
