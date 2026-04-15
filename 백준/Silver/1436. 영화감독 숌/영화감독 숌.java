

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N = Integer.parseInt(br.readLine());

        int count = 1;
        int num = 666;

        if(N == 1) {
            System.out.println(num);
        }

        String str = "";

        while(count != N) {

            num++;
            str = String.valueOf(num);
            String str2 = str.replace("666", "");

            if((str.length() != str2.length()) && (str.length() - str2.length())%3 == 0) {
                count++;
            }

        }

        System.out.println(str);


    }
}
