import java.util.*;

class Solution {
     public int solution(int n, int w, int num) {
        int answer = 0;
        int height = 0;

        int flag = 1;

        int row = 0;
        int col = 0;

        int[][] store = new int[110][];
        for(int i = 0; i < 110; i++){
            store[i] = new int[100];
        }

        int digit = 0;
        for(int i = 0; digit < n;){
            if(digit % w == 0 && digit != 0){
                if(flag == 1){
                    i--;
                } else {
                    i++;
                }
                flag = -flag;
                height += 1;
            }
            if(((n / w) * w + 1) < height)
                break;
            store[height][i] = digit+1;
            digit++;
            if(digit == num){
                row = height;
                col = i;
            }

            if(flag == 1){
                i++;
            } else {
                i--;
            }
        }

        while(store[row][col] <= n && store[row][col] != 0){
            answer++;
            row++;
            if(row > 100){
                break;
            }
        }

        return answer;

    }
}