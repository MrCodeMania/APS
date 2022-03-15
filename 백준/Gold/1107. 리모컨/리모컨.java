import java.util.*;
import java.util.Scanner;


public class Main {
    static int N;
    static int M;

    static int[] possible = new int[10];

    static int min = 999999;

    static void DFS(int channel, int digits, int target){

        if(digits >= target) {
            if(digits + Math.abs(channel - N) < min)
                min = digits + Math.abs(channel - N);
            return;
        }

        for(int i = 0; i < possible.length; i++){
            if(possible[i] == 0){
                DFS(channel * 10 + i, digits+1,target);
            }
        }
    }

    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);

        N = sc.nextInt();
        M = sc.nextInt();

        for(int i = 0; i < M; i++){
            possible[sc.nextInt()] = 1;
        }


        if(Integer.toString(N).length() != 1) {
            for (int i = 0; i < possible.length; i++) {
                if (possible[i] == 0) {
                    DFS(i, 1, Integer.toString(N).length() - 1);
                }
            }
        }

        if(Integer.toString(N).length() != 6) {
            for (int i = 0; i < possible.length; i++) {
                if (possible[i] == 0) {
                    DFS(i, 1, Integer.toString(N).length() + 1);
                }
            }
        }
        
        for (int i = 0; i < possible.length; i++) {
            if (possible[i] == 0) {
                DFS(i, 1, Integer.toString(N).length());
            }
        }

        if(Math.abs(100 - N) < min)
            min = Math.abs(100 - N);





        System.out.print(min);
    }
}
