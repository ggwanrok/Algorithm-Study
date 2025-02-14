

import java.util.Scanner;

public class Main {
    static long calculate(int a, int b, int c){
        if(b == 0){
            return 1;
        }
        if(b%2 != 0){
            return a*(calculate(a, b-1, c)%c)%c;
        }
        else{
            long tmp = calculate(a, b/2, c)%c;
            return (tmp*tmp)%c;
        }
    }
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int a, b, c;
        a = scanner.nextInt();
        b = scanner.nextInt();
        c = scanner.nextInt();
        System.out.println(calculate(a, b, c)%c);
        scanner.close();
    }
}
