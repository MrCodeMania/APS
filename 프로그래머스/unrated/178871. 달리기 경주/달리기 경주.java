import java.util.*;

class Solution {
    public String[] solution(String[] players, String[] callings) {
            HashMap<String, Integer> pos = new HashMap<>();

            for(int i = 0; i < players.length; i++) {
                pos.put(players[i], i);
            }

            for(String call : callings){
                int index = pos.get(call);
                
                String temp = players[index - 1];
                players[index - 1] = call;
                players[index] = temp;

                pos.replace(call, index - 1);
                pos.replace(temp, index);
            }

            return players;
        }
}