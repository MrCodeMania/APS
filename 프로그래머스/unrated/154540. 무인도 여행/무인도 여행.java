import java.util.*;

class Solution {
    int[][] visited;
    int[][] dir = {{-1,0}, {1,0},{0,-1},{0,1}};
    int colLen, food;
    
    public void DFS(String[] maps, int r, int c){
        food += Integer.valueOf(maps[r].charAt(c) - '0');
        
        for(int[] d : dir){
            if(r + d[0] < 0 || r + d[0] >= maps.length || c + d[1] < 0 || c + d[1] >= colLen){
                continue;
            }
            if(visited[r + d[0]][c + d[1]] == 0 && maps[r + d[0]].charAt(c + d[1]) != 'X') {
                visited[r + d[0]][c + d[1]] = 1;
                DFS(maps, r + d[0], c + d[1]);
            }
        }
    }

    public int[] solution(String[] maps) {
        int[] answer = {};

        visited = new int[maps.length][];
        for(int i = 0; i < maps.length; i++){
            visited[i] = new int[maps[i].length()];
            Arrays.fill(visited[i], 0);
        }
        
        colLen = maps[0].length();
        
        List<Integer> list = new ArrayList<>();

        for(int i = 0; i < maps.length; i++){
            for(int j = 0; j < maps[i].length(); j++){
                if(visited[i][j] == 0 && maps[i].charAt(j) != 'X') {
                    food = 0;
                    visited[i][j] = 1;
                    DFS(maps, i, j);
                    list.add(food);
                }
            }
        }

        if(list.isEmpty()){
            list.add(-1);
        }
        
        Collections.sort(list);
        
        return list.stream().mapToInt(Integer::intValue).toArray();
    }
}