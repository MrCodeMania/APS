import java.util.*;
class Solution {
    public int solution(String dartResult) {
        int answer = 0;
        int starPower = 0;
        int star = 1;
        int fault = 1;
        int multi = 0;
        String num = "";

        for(int i = dartResult.length() - 1; i >= 0; i--){

            char charIndex = dartResult.charAt(i);

            if('0' <= charIndex && charIndex <= '9'){
                num = charIndex + num;
                if(i == 0){
                    // 계산
                    answer += Math.pow(Integer.parseInt(num), multi) * star * fault;
                }
            } else if(multi != 0){
                answer += Math.pow(Integer.parseInt(num), multi) * star * fault;
                num = "";
                fault = 1;
                multi = 0;
                if(starPower == 0){
                    star = 1;
                } else if(starPower == 1){
                    star /= 2;
                } else {
                    starPower--;
                    if(star == 4){
                        star /= 2;
                    }
                }
                i++;
            } else if(charIndex == '*'){
                star *= 2;
                starPower = 2;
            } else if(charIndex == '#'){
                fault = -1;
            } else {
                if(charIndex == 'S') {
                    multi = 1;
                } else if(charIndex == 'D') {
                    multi = 2;
                } else if(charIndex == 'T') {
                    multi = 3;
                }
            }



        }
        return answer;
    }
}