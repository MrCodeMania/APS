import java.util.Queue;
import java.util.*;

 class Solution {

    // 현재 위치, 진행할 방향, 횟수 를 필드로 가지는 클래스
    // 큐에 담아 BFS 로 처리

    Queue<Move> bfsQueue = new LinkedList<>();
    int[][] dir = {{-1,0},{0,-1},{1,0},{0,1}};
    boolean[][] visited;

    public int BFS(String[] board){

        // 북, 서, 남, 동
        while(!bfsQueue.isEmpty()){
            Move front = bfsQueue.poll();

            while(true){
                if(front.pos[0] + dir[front.dir][0] < 0 || front.pos[0] + dir[front.dir][0] >= board.length || front.pos[1] + dir[front.dir][1] < 0 || front.pos[1] + dir[front.dir][1] >= board[0].length()){
                    break;
                }

                front.pos[0] += dir[front.dir][0];
                front.pos[1] += dir[front.dir][1];

                if(board[front.pos[0]].charAt(front.pos[1]) == 'D' || (front.pos[1] == 0 && front.dir == 1) || (front.pos[0] == board.length - 1 && front.dir == 2) || (front.pos[0] == 0 && front.dir == 0) || (front.pos[1] == board[0].length() - 1 && front.dir == 3) ){

                    if(board[front.pos[0]].charAt(front.pos[1]) == 'D'){
                        front.pos[0] -= dir[front.dir][0];
                        front.pos[1] -= dir[front.dir][1];
                    }
                    if(board[front.pos[0]].charAt(front.pos[1]) == 'G'){
                        return front.time;
                    }

                    if(!visited[front.pos[0]][front.pos[1]]){
                        visited[front.pos[0]][front.pos[1]] = true;
                        bfsQueue.add(new Move(new int[]{front.pos[0], front.pos[1]}, (front.dir + 1) % 4, front.time + 1));
                        bfsQueue.add(new Move(new int[]{front.pos[0], front.pos[1]}, (front.dir + 3) % 4, front.time + 1));
                    }
                    break;
                }
            }
        }
        return -1;
    }

    public int solution(String[] board) {

        int row = 0, col = 0;

        visited = new boolean[board.length][];
        for(int i = 0; i < board.length; i++)
            visited[i] = new boolean[board[i].length()];
        
        for(int i = 0; i < board.length; i++){
            for(int j = 0; j < board[i].length(); j++){
                if(board[i].charAt(j) == 'R'){
                    row = i; col = j;
                    i = board.length;
                    break;
                }
            }
        }

        visited[row][col] = true;

        for(int i = 0; i < 4; i++)
            bfsQueue.add(new Move(new int[]{row, col}, i, 1));

        return BFS(board);
    }
}

class Move{
    int[] pos;
    int dir;
    int time;

    public Move(int[] pos, int dir, int time){
        this.pos = pos;
        this.dir = dir;
        this.time = time;
    }
}