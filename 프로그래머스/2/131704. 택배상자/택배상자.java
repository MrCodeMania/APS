import java.util.*;

class Solution {
    public int solution(int[] order) {
        int answer = 0;
        
        Deque<Integer> s = new ArrayDeque<>();
        
        int num = 1;
        for(int box : order){
            if(s.isEmpty()) {
                s.offerLast(num);
                num++;
            }
            
            while(s.peekLast() < box){
                s.offerLast(num);
                num++;
            }
            if(s.peekLast() == box){
                s.pollLast();
                answer++;
            } else{
                break;
            }
        
        }
        
        return answer;
    }
}