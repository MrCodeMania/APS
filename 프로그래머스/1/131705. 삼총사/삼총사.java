class Solution {
    int answer = 0;
    
    public void DFS(int[] number, int i, int sum, int cnt){
        if(cnt == 3){
            if(sum == 0){
                answer++;
            }
        }
        
        for(int j = i + 1; j < number.length; j++){
            sum = sum + number[j];
            DFS(number, j, sum, cnt + 1);
            sum = sum - number[j];
        }
    }
    
    public int solution(int[] number) {
        
        DFS(number, -1, 0, 0);
        return answer;
    }
}