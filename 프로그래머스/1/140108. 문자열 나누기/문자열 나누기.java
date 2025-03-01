class Solution {
    public int solution(String s) {
        int answer = 0;
        
        String x = "" + s.charAt(0);
        int xCnt = 1;
        int yCnt = 0;
        
        for(int i = 1; i < s.length(); i++){
            if(xCnt == 0){
                x = "" + s.charAt(i);
                xCnt++;
            } else if(x.equals(String.valueOf(s.charAt(i)))) {
                xCnt++;
            } else {
                yCnt++;
            }
            
            if(xCnt == yCnt){
                answer++;
                xCnt = 0;
                yCnt = 0;
                
            }
        }
        
        if(xCnt != 0 || yCnt != 0){
            answer++;
        }
        
        return answer;
    }
}