
import java.util.Scanner;

public class Main {
    static int[] array;
    static int max;
    static int n;
    static int k;
    public static void binarySearch() {
        long start = 1;
        long end = max;

        while (start <= end) {
            long mid = (start + end) / 2;
            long count = 0;
            for (int i = 0; i < array.length; i++) {
                count += array[i] / mid;
            }

            if (count < n) {
                end = mid-1;
            } else if (count >= n) {
                start = mid+1;
            }

        }

        System.out.println(end);
    }
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        k = scanner.nextInt();
        n = scanner.nextInt();
        array = new int[k];

        for(int i=0; i<k; i++){
            array[i] = scanner.nextInt();
            max = Math.max(max, array[i]);
        }



        binarySearch();
    }
}
