import java.util.*;

// 한 바퀴로 끝내기
// 다음 숫자가 현재 숫자보다 작다면 현재 숫자를 List에 keep해둔다.
// 다음 숫자가 크다면 List에서 하나씩 비교
// List에서 꺼낸 숫자가 작다면 다시 keep

class Solution {
    public int[] solution(int[] numbers) {
        int[] answer = new int[numbers.length];

        PriorityQueue<Keep> pq = new PriorityQueue<>((a, b) -> a.value - b.value);

        for(int i = 0; i < numbers.length; i++){

            while(!pq.isEmpty() && pq.peek().value < numbers[i]){
                answer[pq.poll().index] = numbers[i];
            }

            pq.add(new Keep(i, numbers[i]));
        }
        
        while(!pq.isEmpty())
            answer[pq.poll().index] = -1;

        return answer;
    }
}

class Keep{
    int index;
    int value;

    Keep(int index, int value){
        this.index = index;
        this.value = value;
    }

}