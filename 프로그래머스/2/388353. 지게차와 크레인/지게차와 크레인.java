import java.util.*;

class Pos {
    int x, y, val;
    
    Pos(int x, int y, int val) {
        this.x = x;
        this.y = y;
        this.val = val;
    }
}

class Solution {
    
    List<Pos> outside = new ArrayList<>();
    boolean[][] visited;
    int[][] dir = { {0,1}, {1,0}, {-1,0}, {0,-1} }; // 방향 배열 수정
    
    public void DFS(String[] storage, int r, int c, int n, int m) {
        visited[r][c] = true;
        
        // 4방향 탐색
        for (int i = 0; i < 4; i++) {
            int newR = r + dir[i][0];
            int newC = c + dir[i][1];
            
            if (0 <= newR && newR < n && 0 <= newC && newC < m) {
                if (!visited[newR][newC]) {
                    if (storage[newR].charAt(newC) == '0') {
                        DFS(storage, newR, newC, n, m);
                    } else {
                        outside.add(new Pos(newR, newC, storage[newR].charAt(newC)));
                        visited[newR][newC] = true;
                    }
                }
            }
        }
    }
    
    public int solution(String[] storage, String[] requests) {
        int answer = 0;
        visited = new boolean[storage.length][];
        
        for (int i = 0; i < storage.length; i++) {
            visited[i] = new boolean[storage[i].length()];
        }
                
        for (String request : requests) {
            
            // jige
            if (request.length() == 1) {
                
                // visited 초기화
                for (int r = 0; r < storage.length; r++) {
                    Arrays.fill(visited[r], false);
                }
                
                // outside 초기화
                outside.clear();
                
                // outside select DFS
                for (int r = 0; r < storage.length; r++) {
                    for (int c = 0; c < storage[0].length(); c++) {
                        if (r == 0 || c == 0 || r == storage.length - 1 || c == storage[0].length() - 1) {
                            if (storage[r].charAt(c) == '0') {
                                DFS(storage, r, c, storage.length, storage[0].length());
                            } else if(storage[r].charAt(c) == request.charAt(0) && !visited[r][c]){
                                outside.add(new Pos(r, c, storage[r].charAt(c)));
                                visited[r][c] = true;
                            }
                        }
                    }
                }
                
                // outside list search
                Iterator<Pos> it = outside.iterator();
                while (it.hasNext()) {
                    Pos pos = it.next();
                    if (pos.val == request.charAt(0)) {
                        StringBuilder sb = new StringBuilder(storage[pos.x]);
                        sb.setCharAt(pos.y, '0'); // 값 변경
                        storage[pos.x] = sb.toString();
                        answer++;
                    }
                }
            }
            
            // crane
            else {
                for (int r = 0; r < storage.length; r++) {
                    for (int c = 0; c < storage[0].length(); c++) {
                        if (storage[r].charAt(c) == request.charAt(0)) {
                            StringBuilder sb = new StringBuilder(storage[r]);
                            sb.setCharAt(c, '0');
                            storage[r] = sb.toString();
                            answer++;
                        }
                    }
                }
            }
        }
        
        answer = storage.length * storage[0].length() - answer;
        return answer;
    }
}
