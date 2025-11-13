import java.util.*;

class Solution {
    public int solution(int[] ingredient) {
        int answer = 0;

        // 1231
        // 1 들어올 때 Stack top 3? -> Stack top 2? -> Stack top 1? -> 맞다 = 다 뺌. answer + 1
        // 진행하면서 하나라도 틀리면 이때까지 뺀 애들 다 넣음
        Stack<Integer>  S = new Stack<>();

        for(int i = 0; i < ingredient.length; i++) {
            S.push(ingredient[i]);
            if(S.size() > 3){
                if(ingredient[i] == 1){
                    int zero = S.pop();
                    if(!S.isEmpty()) {
                        int first = S.pop();
                        if (first == 3) {
                            if(!S.isEmpty()) {
                                int second = S.pop();
                                if (second == 2) {
                                    if(!S.isEmpty()) {
                                        int third = S.pop();
                                        if (third == 1) {
                                            answer++;
                                        } else {
                                            S.push(third);
                                            S.push(second);
                                            S.push(first);
                                            S.push(zero);
                                        }
                                    }
                                } else {
                                    S.push(second);
                                    S.push(first);
                                    S.push(zero);
                                }
                            }
                        } else {
                            S.push(first);
                            S.push(zero);
                        }
                    }
                }
            }
        }
        return answer;
    }
}