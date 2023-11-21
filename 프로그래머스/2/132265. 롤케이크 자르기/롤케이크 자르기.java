import java.util.*;

class Solution {
    public int solution(int[] topping) {
        int answer = 0;

        HashMap<Integer, Integer> leftMap = new HashMap<>();
        HashMap<Integer, Integer> rightMap = new HashMap<>();

        for(int i = 0; i < topping.length; i++){
            if(i == 0) {
                leftMap.put(topping[i], 1);
            } else {
                if(rightMap.get(topping[i]) == null){
                    rightMap.put(topping[i], 1);
                } else {
                    rightMap.put(topping[i], rightMap.get(topping[i]) + 1);
                }
            }
        }

        for(int i = 0; i < topping.length; i++){
            if(i != 0){
                if(leftMap.get(topping[i]) == null){
                    leftMap.put(topping[i], 1);
                } else {
                    leftMap.put(topping[i], leftMap.get(topping[i]) + 1);
                }

                if(rightMap.get(topping[i]) == 1){
                    rightMap.remove(topping[i]);
                } else {
                    rightMap.put(topping[i], rightMap.get(topping[i]) - 1);
                }
            }

            if(leftMap.size() == rightMap.size()){
                answer++;
            }
        }

        return answer;
    }
}