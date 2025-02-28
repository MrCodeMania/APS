class Solution {
    public int solution(String t, String p) {
        int answer = 0;
        
        String substr = "";
        
        for(int i = 0; i < t.length(); i++){
            substr += t.charAt(i);
            
            if(i >= p.length()){
                substr = substr.substring(1);
            }
            
            if(i >= p.length() - 1){
                if(Long.parseLong(substr) <= Long.parseLong(p)){
                    answer++;
                }
            }
        }
        
        return answer;
    }
}