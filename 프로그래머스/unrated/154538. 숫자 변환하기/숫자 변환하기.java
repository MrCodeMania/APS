import java.util.*;

class Solution {
    
    Queue<int[]> bfsQueue = new LinkedList<>();

    public int solution(int x, int y, int n) {
        bfsQueue.add(new int[]{y, 0});

        while(!bfsQueue.isEmpty()){
            int[] front = bfsQueue.poll();
            
            if(front[0] == x)
                return front[1];
            
            if(front[0] > x){
                if(front[0] % 3 == 0){
                    bfsQueue.add(new int[]{front[0] / 3, front[1] + 1});
                }
                if(front[0] % 2 == 0){
                    bfsQueue.add(new int[]{front[0] / 2, front[1] + 1});
                }
                bfsQueue.add(new int[]{front[0] - n, front[1] + 1});
            }
        }
    
        return -1;
    }
}