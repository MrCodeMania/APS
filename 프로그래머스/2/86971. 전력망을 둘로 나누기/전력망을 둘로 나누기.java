import java.util.*;

class Solution {
    
    int[][] connection;
    int network = 0;
    
    void DFS(int target, int n){
        connection[target][target] = 1;
        network++;
        
        for(int i = 0; i < n; i++){
            if(i != target) {
                if(connection[i][i] == 0 && connection[target][i] == 1){
                    DFS(i, n);
                }
            }
        }
    }
    
    public int solution(int n, int[][] wires) {
        int answer = Integer.MAX_VALUE;
        
        connection = new int[n][];
        for(int i = 0; i < n; i++){
            connection[i] = new int[n];
        }
        
        for(int i = 0; i < wires.length; i++){
            connection[wires[i][0] - 1][wires[i][1] - 1] = 1;
            connection[wires[i][1] - 1][wires[i][0] - 1] = 1;
        }
        
        for(int i = 0; i < wires.length; i++){
            connection[wires[i][0] - 1][wires[i][1] - 1] = 0;
            connection[wires[i][1] - 1][wires[i][0] - 1] = 0;
            
            int first = 0;
            int second = 0;
            
            for(int j = 0; j < n; j++){
                if(connection[j][j] == 0){
                    DFS(j, n);
                    
                    if(j == 0){
                        first = network;
                        network = 0;
                    } else {
                        second = network;
                        network = 0;
                    }
                }
            }
            
            if(Math.abs(first - second) < answer){
                answer = Math.abs(first - second);
            }
            
            for(int j = 0; j < n; j++){
                connection[j][j] = 0;
            }
            
            connection[wires[i][0] - 1][wires[i][1] - 1] = 1;
            connection[wires[i][1] - 1][wires[i][0] - 1] = 1;
        }
        
        return answer;
    }
}