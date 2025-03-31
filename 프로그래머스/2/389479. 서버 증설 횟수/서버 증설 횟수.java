import java.util.*;

class Solution {
    public int solution(int[] players, int m, int k) {
        int answer = 0;
        List<Integer> server = new ArrayList<>();
        
        for (int i = 0; i < players.length; i++) {
            if (players[i] >= m * (server.size() + 1)) {
                int times = (players[i] - m * server.size()) / m;
                for (int j = 0; j < times; j++) {
                    server.add(k);
                    answer++;
                }
            }
            
            Iterator<Integer> it = server.iterator();
            while (it.hasNext()) {
                int temp = it.next() - 1; // 값 감소
                if (temp == 0) {
                    it.remove(); // 안전하게 삭제
                } else {
                    server.set(server.indexOf(temp + 1), temp); // 값 업데이트
                }
            }
        }
        
        return answer;
    }
}
