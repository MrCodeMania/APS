import java.util.*;

class Solution {
    public int solution(int[][] targets) {
        int answer = 0;
        //모든 폭격 미사일을 요격하기 위해 필요한 요격 미사일 수의 최솟값을 return
        
        // 끝나는 기준 오름차순 정렬
        Arrays.sort(targets, (o1, o2)->(o1[1]-o2[1]));
        
        int pos = Integer.MIN_VALUE;
        
        for(int[] t:targets){
            if(pos<t[0]){
                pos = t[1]-1;
                answer++; //요격 미사일 추가
            }
            
        }
        return answer;
    }
}