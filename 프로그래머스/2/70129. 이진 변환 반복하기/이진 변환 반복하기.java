import java.util.*;

class Solution {
    
    public int[] solution(String s) {
        String newS = "";
        int time = 0;
        int zero = 0;
        
        while(true){
            for(int i = 0; i < s.length(); i++){
                if(s.charAt(i) != '1'){
                    zero++;
                } else {
                    newS += "1";
                }
            }

            int c = newS.length();
            boolean first = true;
            newS = "";

            for(int i = 17; i >= 0; i--){
                if(c >= Math.pow(2,i)){
                    c -= Math.pow(2,i);
                    newS += "1";
                    first = false;
                } else if(!first) {
                    newS += "0";
                }
            }

            time++;
            
            if(newS.equals("1")){
                break;
            }
            
            s = newS;
            newS = "";
        }
        
        return new int[]{time, zero};
    }
}