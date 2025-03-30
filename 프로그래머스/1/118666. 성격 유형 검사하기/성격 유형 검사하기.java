import java.util.*;

class Solution {
    public String solution(String[] survey, int[] choices) {
        String answer = "";
        
        String type = "RTCFJMAN";
        int[][] count = new int[4][];
        for(int i = 0; i < count.length; i++){
            count[i] = new int[2];
        }
        
        for(int i = 0; i < survey.length; i++) {
            char firstType = survey[i].charAt(0);
            char secondType = survey[i].charAt(1);
            
            int firstPos = type.indexOf(firstType);
            int secondPos = type.indexOf(secondType);
            
            int point = choices[i] - 4;
            
            if(point < 0) {
                count[firstPos / 2][firstPos % 2] += -point;
            } else {
                count[secondPos / 2][secondPos % 2] += point;
            }
        }
        
        for(int i = 0; i < 4; i++){
            if(count[i][0] > count[i][1]) {
                answer += type.charAt(i * 2);
            } else if(count[i][0] < count[i][1]) {
                answer += type.charAt(i * 2 + 1);
            } else if(type.charAt(i * 2) < type.charAt(i * 2 + 1)) {
                answer += type.charAt(i * 2);
            } else {
                answer += type.charAt(i * 2 + 1);
            }
        }
        
        return answer;
    }
}