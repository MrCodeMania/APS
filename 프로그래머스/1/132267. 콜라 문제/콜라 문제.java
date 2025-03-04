class Solution {
    public int solution(int a, int b, int n) {
        int answer = 0;
        int remain = 0;
        
        while(n > 0) {
            remain += n % a;
            answer += b  * (n / a);
            n = b  * (n / a);
            
            if(remain >= a) {
                remain -= a;
                answer += b;
                n += b;
            }
        }
        return answer;
    }
}