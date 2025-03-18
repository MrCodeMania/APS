class Solution {
    public String solution(String X, String Y) {
        String answer = "";
        
        // 돌면서 0~9 개수 세서 두 그룹에 적재하고
        // 9부터 0~9 두 그룹 중 작은 개수만큼 나열한다.
        // 0을 나열할 차례인데 길이가 0이면 0을 반환
        // answer의 길이가 0이면 -1을 반환, 

        int[] xGroup = new int[10];
        int[] yGroup = new int[10];
        
        for(int i = 0; i < X.length(); i++){
            xGroup[X.charAt(i) - '0']++;
        }
        
        for(int i = 0; i < Y.length(); i++){
            yGroup[Y.charAt(i) - '0']++;
        }
        
        for(int i = 9; i >= 0; i--){
            if(i == 0 && answer.length() == 0){
                xGroup[i] = xGroup[i] > 0 ? 1 : 0;
                yGroup[i] = yGroup[i] > 0 ? 1 : 0;
            }
            
            if(xGroup[i] >= yGroup[i] && yGroup[i] > 0){
                answer += (i + "").repeat(yGroup[i]);
            } else if(xGroup[i] <= yGroup[i] && xGroup[i] > 0){
                answer += (i + "").repeat(xGroup[i]);
            }
        }
        
        if(answer.length() == 0){
            answer = "-1";
        }
        
        return answer;
    }
}