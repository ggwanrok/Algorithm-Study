

import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int[] test = new int[12];
        test[0] = 0;
        test[1] = 1;
        test[2] = 2;
        test[3] = 4;
        for(int i=4; i<test.length; i++){
            test[i] = test[i-1] + test[i-2] + test[i-3];
        }

        int T = scanner.nextInt();
        for(int i=0; i<T; i++){
            int k = scanner.nextInt();
            System.out.println(test[k]);
        }
    }
}
