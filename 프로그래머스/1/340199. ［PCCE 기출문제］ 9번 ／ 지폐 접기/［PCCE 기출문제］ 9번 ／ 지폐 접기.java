class Solution {
    public int solution(int[] wallet, int[] bill) {
        int answer = 0;
        
        int wSmall = wallet[0] <= wallet[1] ? wallet[0] : wallet[1];
        int wBig = wallet[0] <= wallet[1] ? wallet[1] : wallet[0];
        int bSmall = bill[0] <= bill[1] ? bill[0] : bill[1];
        int bBig = bill[0] <= bill[1] ? bill[1] : bill[0];
        
        while(bSmall > wSmall || bBig > wBig){
            
            if(bill[0] < bill[1]){
                bill[1] /= 2;
            } else {
                bill[0] /= 2;
            }
            
            bSmall = bill[0] <= bill[1] ? bill[0] : bill[1];
            bBig = bill[0] <= bill[1] ? bill[1] : bill[0];
            
            answer++;
        }
        
        return answer;
    }
}