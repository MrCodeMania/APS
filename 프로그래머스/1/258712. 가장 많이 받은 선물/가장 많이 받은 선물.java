class Solution {
    public int solution(String[] friends, String[] gifts) {
        int maxVal = 0;
        
        int[][] presentRecord;
        presentRecord = new int[friends.length][];
        for(int i = 0; i < friends.length; i++){
            presentRecord[i] = new int[friends.length];
        }
        
        int[] presentVal;
        presentVal = new int[friends.length];
        
        int[] nextVal;
        nextVal = new int[friends.length];
        
        for(int i = 0; i < gifts.length; i++){
            String sender = gifts[i].split(" ")[0];
            String receiver = gifts[i].split(" ")[1];
            
            for(int f = 0; f < friends.length; f++){
                if(sender.equals(friends[f])){
                    presentVal[f]++;
                    for(int g = 0; g < friends.length; g++){
                        if(receiver.equals(friends[g])){
                            presentRecord[f][g]++;
                            break;
                        }
                    }
                } else if(receiver.equals(friends[f])){
                    presentVal[f]--;
                }
            }
        }
        
        for(int i = 0; i < friends.length; i++){
            for(int j = i + 1; j < friends.length; j++){
                
                // 2번의 경우
                if((presentRecord[i][j] == 0 && presentRecord[j][i] == 0) || presentRecord[i][j] == presentRecord[j][i]){
                    if(presentVal[i] > presentVal[j]){
                        nextVal[i]++;
                    } else if(presentVal[i] < presentVal[j]){
                        nextVal[j]++;
                    } else continue;
                    
                }
                // 1번의 경우
                else if(presentRecord[i][j] > 0 || presentRecord[j][i] > 0){
                    if(presentRecord[i][j] > presentRecord[j][i]){
                        nextVal[i]++;
                    } else if(presentRecord[i][j] < presentRecord[j][i]){
                        nextVal[j]++;
                    }
                }
            }
        }
        
        for(int i = 0; i < nextVal.length; i++){
            if(maxVal < nextVal[i]){
                maxVal = nextVal[i];
            }
        }         
        
        return maxVal;
    }
}