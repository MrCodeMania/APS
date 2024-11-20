import java.util.Arrays;

class Solution {
    public int solution(int[] mats, String[][] park) {
        int answer = -1;
        
        Arrays.sort(mats);
        
        for(int i = 0; i < park.length; i++){
            for(int j = 0; j < park[i].length; j++){
                if(park[i][j].equals("-1")){
                    for(int m = mats.length - 1; m >= 0; m--){
                        int count = 0;
                        boolean flag = true;
                        for(int k = i; k < park.length && k < i + mats[m]; k++){
                            for(int l = j; l < park[k].length && l < j + mats[m]; l++){
                                if(!(park[k][l].equals("-1"))){
                                    flag = false;
                                    k = park.length;
                                    break;
                                } else {
                                    count++;
                                }
                            }
                        }
                        
                        if(flag && count == mats[m]*mats[m]){
                           if(mats[m] > answer){
                               answer = mats[m];
                               break;
                           }     
                        }
                    }
                }
            }
        }
        
        return answer;
    }
}