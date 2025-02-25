class Solution {
    public int solution(int[] schedules, int[][] timelogs, int startday) {
        int answer = 0;
        
        int[] gaekeun = new int[schedules.length];
        
        for(int i = 0; i < schedules.length; i++){
            int limit;
            for(int j = 0; j < timelogs[i].length; j++, startday++){
                
                if(startday == 6 || startday == 7){
                    if(startday == 7){
                        startday = 0;
                    }
                    continue;
                }
                if(50 <= schedules[i] % 100 && schedules[i] % 100 <= 59){
                    limit = schedules[i] + 100 - (schedules[i] % 100) + (schedules[i] % 10);
                }  else { 
                    limit = schedules[i] + 10;
                }
                if(limit < timelogs[i][j]){
                    gaekeun[i] = -1;
                }
            }
        }
        
        for(int i = 0; i < schedules.length; i++){
            if(gaekeun[i] == 0){
                answer++;
            }
        }
        
        return answer;
    }
}