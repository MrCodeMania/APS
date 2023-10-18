import java.util.*;

class Solution {
    public int solution(int k, int[] tangerine) {

        HashMap<Integer, Integer> map = new HashMap<>();

        for(int i : tangerine) {
            if(!map.containsKey(i)) {
                map.put(i, 1);
            } else {
                map.replace(i, map.get(i) + 1);
            }
        }

        PriorityQueue<Integer> pq = new PriorityQueue<>(Collections.reverseOrder());
        
        for(int key : map.keySet()){
            pq.add(map.get(key));
        }

        int answer = 0;
        
        while(k > 0){
            int top = pq.poll();
            k -= top;
            answer++;
        }

        return answer;
    }
}