class Solution {
     
    int maxSubscriber = 0;
    int maxSales = 0;
    
    public void DFS(int[][] users, int[] emoticons, int[] sum, int index){

        if(index == emoticons.length) {
            int subscriber = 0;
            int sales = 0;

            for(int i = 0; i < users.length; i++) {
                if(users[i][1] <= sum[i]){
                    subscriber ++;
                } else {
                    sales += sum[i];
                }
            }

            if(maxSubscriber == subscriber){
                if(maxSales <= sales){
                    maxSales = sales;
                }
            }
            if(maxSubscriber < subscriber){
                maxSubscriber = subscriber;
                maxSales = sales;
            }

            return;
        }

        for(int rate = 9; rate >= 6; rate--){
            int sales = (emoticons[index] * rate) / 10;

            for(int i = 0; i < users.length; i++){
                if(users[i][0] <= (10 - rate) * 10) {
                    sum[i] += sales;
                }
            }

            DFS(users, emoticons, sum, index + 1);

            for(int i = 0; i < users.length; i++){
                if(users[i][0] <= (10 - rate) * 10) {
                    sum[i] -= sales;
                }
            }

        }

    }


    public int[] solution(int[][] users, int[] emoticons) {
        int[] answer = {};

        DFS(users, emoticons, new int[users.length], 0);

        return new int[]{maxSubscriber, maxSales};
    }
}