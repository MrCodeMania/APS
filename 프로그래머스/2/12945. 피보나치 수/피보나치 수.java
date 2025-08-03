class Solution {
    public int solution(int n) {
        
        long[] fibonacci = new long [100001];
        fibonacci[0] = 0; fibonacci[1] = 1;
        
        for(int i = 2; i <= 100000; i++){
            fibonacci[i] = (fibonacci[i - 1] + fibonacci[i - 2]) % 1234567;
            
            if(i == n) {
                return (int)fibonacci[n];
            }
        }
        
        
        return 0;
    }
}