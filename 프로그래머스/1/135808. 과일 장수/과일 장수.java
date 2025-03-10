import java.util.*;

class Solution {
    public int solution(int k, int m, int[] score) {
        int answer = 0;

        Integer[] arr = Arrays.stream(score).boxed().toArray(Integer[]::new);
        Arrays.sort(arr, Collections.reverseOrder());

        for(int i = 1; i <= arr.length; i++){
            if(i % m == 0){
                answer += (arr[i-1] * m);
            }
        }

        return answer;
    }
}