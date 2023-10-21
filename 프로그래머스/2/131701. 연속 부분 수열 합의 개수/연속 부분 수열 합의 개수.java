import java.util.HashMap;

class Solution {
    public int solution(int[] elements) {
        int answer = 0;

        HashMap<Integer, Integer> map = new HashMap<>();
        int[] circularSequence = new int[elements.length * 2];

        for(int i = 0; i < circularSequence.length; i++){
            circularSequence[i] = elements[i % elements.length];
        }

        // 연속된 수열의 길이
        for(int i = 1; i <= elements.length; i++){
            int seqSum = 0;
            // 첫 부분합 구하기
            for(int j = 0; j < i; j++){
                seqSum += circularSequence[j];
            }

            for(int j = 0; j < elements.length; j++){
                seqSum -= circularSequence[j];
                seqSum += circularSequence[i + j];

                if(!map.containsKey(seqSum)){
                    map.put(seqSum, 0);
                    answer++;
                }
            }
        }

        return answer;
    }
}