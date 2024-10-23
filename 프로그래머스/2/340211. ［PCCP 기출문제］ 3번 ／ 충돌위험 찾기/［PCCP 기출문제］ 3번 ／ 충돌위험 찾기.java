import java.util.*;

class Solution {
    public int solution(int[][] points, int[][] routes) {
        int answer = 0;
        
        int[][] robots = new int[routes.length][];
        for(int i = 0; i < routes.length; i++){
            robots[i] = new int[2];
        }
        
        for(int i = 0; i < routes.length; i++){
            robots[i][0] = points[routes[i][0] - 1][0];
            robots[i][1] = points[routes[i][0] - 1][1];
        }
        
        HashMap<List<Integer>, Integer> map = new HashMap<>();
        
        for(int i = 0; i < routes.length; i++){
            List<Integer> temp = new ArrayList<Integer>();
            temp.add(robots[i][0]);
            temp.add(robots[i][1]);

            if(map.get(temp) == null){
                map.put(temp, 0);
            } else {
                map.replace(temp, 1);
            }
        }
        
        answer += map.values().stream().mapToInt(Integer::intValue).sum();
        
        boolean isContinue = true;
        while(isContinue){
            isContinue = false;
            
            map = new HashMap<>();
            
            // if need robots move then perform logic
            for(int i = 0; i < routes.length; i++){
                for(int j = 0; j < routes[i].length - 1; j++){
                    if(routes[i][j] == -1){
                        continue;
                    }

                    isContinue = true;

                    boolean arrived = false;
                    //System.out.println("before : " + robots[routes[i][0] - 1][0] + " " + robots[routes[i][0] - 1][1]);
                    // first row, second col
                    if(!(robots[i][0] == points[routes[i][j + 1] - 1][0])){
                        if(robots[i][0] < points[routes[i][j + 1] - 1][0]){
                            robots[i][0] += 1;
                        } else {
                            robots[i][0] -= 1;
                        }
                    } else {
                        if(!(robots[i][1] == points[routes[i][j + 1] - 1][1])){
                            if(robots[i][1] < points[routes[i][j + 1] - 1][1]){
                                robots[i][1] += 1;
                            } else {
                                robots[i][1] -= 1;
                            }
                        } else {
                            arrived = true;
                        }
                    }

                    if(arrived){
                        //System.out.println(routes[i][0] + " " + routes[i][1]);
                        routes[i][j] = -1;
                        continue;
                    }


                    List<Integer> temp = new ArrayList<Integer>();
                    temp.add(robots[i][0]);
                    temp.add(robots[i][1]);

                    //System.out.println(routes[i][0] + " " + routes[i][1]);
                    //System.out.println("move : " + robots[routes[i][0] - 1][0] + " " + robots[routes[i][0] - 1][1]);

                    if(map.get(temp) == null){
                        map.put(temp, 0);
                    } else {
                        //System.out.println("exists : " + robots[routes[i][0] - 1][0] + " " + robots[routes[i][0] - 1][1]);
                        map.replace(temp, 1);
                    }
                    
                    break;
                }
            }
            
            // map value sum
            // one round
            answer += map.values().stream().mapToInt(Integer::intValue).sum();
        }
        
        return answer;
    }
}