class Solution {
    public String solution(String s, int n) {
        String answer = "";
        
        for(int i = 0; i < s.length(); i++) {
            char temp = s.charAt(i);
            if('a' <= temp && temp <= 'z') {
                if((int)(temp - 'a') + n >= 26) {
                    temp = (char)((int)'a' + (int)(temp - 'a') + n - 26);
                } else {
                    temp = (char)((int)temp + n);
                }
            } else if('A' <= temp && temp <= 'Z') {
                 if((int)(temp - 'A') + n >= 26) {
                    temp = (char)((int)'A' + (int)(temp - 'A') + n - 26);
                } else {
                    temp = (char)((int)temp + n);
                }
            }
            
            answer += temp;
        }
        
        return answer;
    }
}