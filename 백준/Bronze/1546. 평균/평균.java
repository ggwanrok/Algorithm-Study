

import java.util.Scanner;

public class Main {
    public static double getAver(double k, double Max){
        return (k/Max)*100;
    }

    static double average = 0;

    public static void main(String[] args) {
        int n;
        Scanner scanner = new Scanner(System.in);
        n = scanner.nextInt();
        int[] arr = new int[n];
        for(int i=0; i<arr.length; i++){
            arr[i] = scanner.nextInt();
        }
        for(int i=0; i<n-1; i++){
            for(int j=i+1; j<n; j++){
                if(arr[i] < arr[j]){
                    int tmp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = tmp;
                }
            }
        }
        System.out.println();
        for(int i=0; i<n; i++){
            average += getAver((double)arr[i], (double)arr[0]);
        }

        System.out.println(average/n);
    }
}
