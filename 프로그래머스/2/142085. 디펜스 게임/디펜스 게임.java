import java.util.*;

class Solution {
    public int solution(int n, int k, int[] enemy) {
        int answer = enemy.length;
        PriorityQueue<Integer> pq = new PriorityQueue<>(); // 최소 힙

        for (int i = 0; i < enemy.length; i++) {
            pq.offer(enemy[i]);

            if (pq.size() > k) {
                int weakest = pq.poll(); // 가장 약한 적을 병력으로 막음
                if (n - weakest >= 0) {
                    n -= weakest;
                } else {
                    answer = i;
                    break;
                }
            }
        }

        return answer;
    }
}
