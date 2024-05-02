class Solution {
    
    boolean answer = false;
    
    void DFS(int fIdx, int sIdx, int gIdx, String[] cards1, String[] cards2, String[] goal){
        if(answer){
            return;
        }
        
        gIdx++;
        
        if(gIdx == goal.length){
            answer = true;
            return;
        }
        
        if(fIdx < cards1.length){
            if(cards1[fIdx].equals(goal[gIdx])){
                DFS(fIdx + 1, sIdx, gIdx, cards1, cards2, goal);
            }
        }
        
        if(sIdx < cards2.length){
            if(cards2[sIdx].equals(goal[gIdx])){
                DFS(fIdx, sIdx + 1, gIdx, cards1, cards2, goal);
            }
        }
    }
    
    public String solution(String[] cards1, String[] cards2, String[] goal) {
        
        DFS(0, 0, -1, cards1, cards2, goal);
        
        return answer == true ? "Yes" : "No";
    }
}