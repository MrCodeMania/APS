class Solution {
    public int[] solution(String s) {
        int[] answer = new int[s.length()];
        int[] alphabet = new int[26];
        
        for(int i = 0; i < s.length(); i++){
            if(i == 0 || alphabet[s.charAt(i) - 'a'] == 0){
                answer[i] = -1;
            } else {
                answer[i] = i + 1 - alphabet[s.charAt(i) - 'a'];
            }
            alphabet[s.charAt(i) - 'a'] = i + 1;
        }
        return answer;
    }
}