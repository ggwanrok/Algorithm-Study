import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int length = 0;
        int max = 0;
        for(int i=1; i<=n; i++){
            length += i;
        }
        tri[] Tri = new tri[length];
        int dep = 1;
        int depCheck = 0;
        for(int i=0; i<length; i++){
            int k = scanner.nextInt();
            Tri[i] = new tri(dep, k, k, 0);
            depCheck++;
            if(dep == depCheck){
                dep++;
                depCheck = 0;
            }
        }
        
        for(int i=0; i<length; i++){
            int nIndex = Tri[i].depth;
            int nValue = Tri[i].value;
            if(Tri[i].depth == n){
                if(Tri[i].sum > max){
                    max = Tri[i].sum;
                }
            }
            else{
                if(Tri[i+nIndex].value + Tri[i].sum > Tri[i+nIndex].sum) {
                    Tri[i + nIndex].sum = Tri[i + nIndex].value + Tri[i].sum;
                }
                if(Tri[i+nIndex+1].value + Tri[i].sum > Tri[i+nIndex+1].sum) {
                    Tri[i + nIndex+1].sum = Tri[i + nIndex+1].value + Tri[i].sum;
                }
            }
        }
        System.out.println(max);


    }
}

class tri{
    int depth;
    int value;

    int sum;

    int isVisited;

    public tri(int depth, int value, int sum, int isVisited){
        this.depth = depth;
        this.value = value;
        this.sum = sum;
        this.isVisited = isVisited;
    }
}
