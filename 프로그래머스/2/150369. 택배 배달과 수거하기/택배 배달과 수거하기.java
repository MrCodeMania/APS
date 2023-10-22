import java.util.*;

class Solution {
    public long solution(int cap, int n, int[] deliveries, int[] pickups) {
        long answer = 0;

        Stack<Integer> dStack = new Stack<>();
        Stack<Integer> pStack = new Stack<>();

        for(int i = 0; i < n; i++){
            dStack.push(deliveries[i]);
            pStack.push(pickups[i]);
        }
        while(!dStack.isEmpty() && !pStack.isEmpty()){ 
            if(dStack.peek() == 0 && pStack.peek() == 0){
                dStack.pop();
                pStack.pop();
                n--;
            } else {
                break;
            }
        }
        
        int box = 0;
        int dist = n;
        
        while(dStack.size() > 0 || pStack.size() > 0) {
            box = 0;
            while (dStack.size() > 0) {
                box += dStack.pop();
                if (box > cap) {
                    dStack.push(box - cap);
                    break;
                }
            }
            box = 0;
            while (pStack.size() > 0) {
                box += pStack.pop();
                if (box > cap) {
                    pStack.push(box - cap);
                    break;
                }
            }

            answer += dist * 2;
            dist = Math.max(dStack.size(), pStack.size());
        }

        return answer;
    }

}