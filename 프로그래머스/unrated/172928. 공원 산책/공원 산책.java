class Solution {

        public int[][] d = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        public int row, col;
        public int rMax, cMax;

        public void Run(String[] park, String[] move, int[] original){
            int dir = 0;
            switch (move[0]){
                case "N": dir = 0; break;
                case "S": dir = 1; break;
                case "W": dir = 2; break;
                case "E": dir = 3; break;
            }

            int dist = Integer.parseInt(move[1]);

            for(int i = 0; i < dist; i++){
                if(row + d[dir][0] < 0 || row + d[dir][0] >= rMax || col + d[dir][1] < 0 || col + d[dir][1] >= cMax){
                    row = original[0];
                    col = original[1];
                    break;
                } else if(park[row + d[dir][0]].charAt(col + d[dir][1]) == 'X'){
                    row = original[0];
                    col = original[1];
                    break;
                }
                row += d[dir][0];
                col += d[dir][1];
            }
        }

        public int[] solution(String[] park, String[] routes) {

            rMax = park.length;
            cMax = park[0].length();

            for(int i = 0; i < park.length; i++){
                for(int j = 0; j < park[i].length(); j++){
                    if('S' == park[i].charAt(j)){
                        row = i; col = j;
                        break;
                    }
                }
            }

            for(int i = 0; i < routes.length; i++){
                String[] move = routes[i].split(" ");
                Run(park, move, new int[]{row, col});
            }

            return new int[]{row, col};
        }
    }