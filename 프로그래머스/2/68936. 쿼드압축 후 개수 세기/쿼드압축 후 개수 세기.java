import java.util.*;

class QuadTree {
    int n;
    int r, c;
    
    QuadTree(int n, int r, int c) {
        this.n = n;
        this.r = r;
        this.c = c;
    }
}

class Solution {
    public int[] solution(int[][] arr) {
        int[] answer = {0, 0};
        
        Queue<QuadTree> bfsQueue = new LinkedList<>();
        
        int n = 0;
        int length = arr.length;
        while(length % 2 == 0){
            length /= 2;
            n++;
        }
        
        bfsQueue.offer(new QuadTree(n, 0, 0));
        
        while(bfsQueue.size() > 0) {
            QuadTree top = bfsQueue.poll();
            int nSquared = top.n;
            int first = arr[top.r][top.c];
            
            for(int i = top.r; i < top.r + Math.pow(2, nSquared); i++){
                for(int j = top.c; j < top.c + Math.pow(2, nSquared); j++){
                    if(first != arr[i][j]){                
                        if(nSquared != 0) {
                            bfsQueue.offer(new QuadTree(nSquared - 1, top.r, top.c));
                            bfsQueue.offer(new QuadTree(nSquared - 1, top.r, top.c + (int)Math.pow(2, nSquared - 1)));
                            bfsQueue.offer(new QuadTree(nSquared - 1, top.r + (int)Math.pow(2, nSquared - 1), top.c));
                            bfsQueue.offer(new QuadTree(nSquared - 1, top.r + (int)Math.pow(2, nSquared - 1), top.c + (int)Math.pow(2, nSquared - 1)));
                        }
                        
                        i = top.r + (int)Math.pow(2, nSquared);
                        break;
                    }
                    
                    
                    if(i == top.r + Math.pow(2, nSquared) - 1&& j == top.c + Math.pow(2, nSquared) - 1){
                        answer[first]++;
                    }
                }
            }
        }
            
        
        return answer;
    }
}