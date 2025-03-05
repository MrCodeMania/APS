import java.util.*;

class Solution {
    public int solution(int number, int limit, int power) {
        int answer = 0;

        for(int i = 1; i <= number; i++){
            int divisor = 0;
            for(int j = 1; j * j <= i; j++){
                if(i % j == 0){
                    if(i / j == j){
                        divisor++;
                    } else {
                        divisor+=2;
                    }
                }
            }
            if(divisor > limit){
                divisor = power;
            }
            answer += divisor;
        }

        return answer;
    }
}