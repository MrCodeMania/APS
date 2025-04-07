import java.util.*;

class Solution {
    public int[] solution(String[] id_list, String[] report, int k) {
        int[] answer = new int[id_list.length];
        
        HashMap<String, Integer> id_num = new HashMap<>();
        
        int[][] id_report = new int[id_list.length][];
        for(int i = 0; i < id_list.length; i++){
            id_num.put(id_list[i], i);
            id_report[i] = new int[id_list.length];
        }
        
        //enroll
        for(int i = 0; i < report.length; i++){
            String first = report[i].split(" ")[0];
            String second = report[i].split(" ")[1];
            
            id_report[id_num.get(first)][id_num.get(second)] = 1; 
        }
        //muzi > frodo, neo
        
        //valuation
        for(int i = 0; i < id_list.length; i++){
            int result = 0;
            for(int j = 0; j < id_list.length; j++){
                if(id_report[i][j] == 1){
                    int count = 0;
                    for(int r = 0; r < id_list.length; r++){
                        if(id_report[r][j] == 1){
                            count++;
                        }
                    }
                    if(count >= k) {
                        result++;   
                    }
                }
            }
            answer[i] = result;
        }
        
        return answer;
    }
}