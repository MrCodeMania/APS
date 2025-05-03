import java.util.*;

class Solution {

    String naryConvert(int n, int k){
        String ret = "";
        boolean first = true;

        for(int i = 20; i >= 0; i--) {
            if(n >= Math.pow(k, i)){
                ret += (int)(n / Math.pow(k, i));
                n = n - (int)(n / Math.pow(k, i)) * (int)Math.pow(k, i);
                first = false;
            } else if(!first){
                ret += "0";
            }
        }

        return ret;
    }

    int isPrime(String num){
        if(num.length() > 0){
            long lNum = Long.parseLong(num);
            if(lNum == 1){
                return 0;
            } else if(lNum == 2){
                return 1;
            }

            for(int i = 2; i <= Math.sqrt(lNum); i++){
                if(lNum % i == 0){
                    return 0;
                }
            }

            return 1;
        }

        return 0;
    }

    public int solution(int n, int k) {
        int answer = 0;

        // 진수변환
        String kNary = naryConvert(n, k);

        // 0부터 소수판별
        String temp = "";
        for(int i = 0; i < kNary.length(); i++){
            if('0' == kNary.charAt(i)){
                answer += isPrime(temp);
                temp = "";
            } else {
                temp = temp + kNary.charAt(i);
            }
        }

        if(temp.length() > 0){
            answer += isPrime(temp);
        }

        return answer;
    }
}