class Solution {
    
    int answer = 0;
    boolean[] visited;
    
    void DFS(int[][] computers, int index){
        visited[index] = true;
        for(int j = 0; j < computers.length; j++){
            if(index != j && !visited[j] && computers[index][j] == 1){
                DFS(computers, j);
            }
        }
    }
    
    public int solution(int n, int[][] computers) {
        
        visited = new boolean[200];
        
        for(int i = 0; i < computers.length; i++){
            if(!visited[i]){
                DFS(computers, i);
                answer++;
            }
        }
        
        return answer;
    }
}