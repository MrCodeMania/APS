import java.util.*;

class Solution {
    public String solution(String[] participant, String[] completion) {
        HashMap<String, Integer> map = new HashMap<>();
        
        for(int i = 0; i < completion.length; i++) {
            map.put(completion[i], map.get(completion[i]) == null ? 1 : map.get(completion[i]) + 1);
        }
        
        for(int i = 0; i < participant.length; i++) {
            if(map.get(participant[i]) == null) {
                return participant[i];
            }
            else {
                if(map.get(participant[i]) == 1) {
                    map.remove(participant[i]);
                } else {
                    map.put(participant[i], map.get(participant[i]) - 1);
                }
            }
        }
        
        return map.entrySet().iterator().next().getKey();
    }
}