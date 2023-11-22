import java.util.*;

class Solution {
    public int solution(int[] order) {
        int answer = 0;
        
        Stack<Integer> s = new Stack<>();
        
        int num = 1;
        for(int box : order){
            if(s.isEmpty()) {
                s.push(num);
                num++;
            }
            
            while(s.peek() < box){
                s.push(num);
                num++;
            }
            if(s.peek() == box){
                s.pop();
                answer++;
            } else{
                break;
            }
        
        }
        
        return answer;
    }
}