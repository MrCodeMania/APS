import java.util.*;

class Solution
{
    public int solution(int [][]board)
    {
        int max = 0;

        if(board.length == 1 || board[0].length == 1){
            max = 1;
        }
        
        for(int i = 1; i < board.length; i++){
            for(int j = 1; j < board[i].length; j++){
                if (board[i][j] == 1) {
                    board[i][j] = Math.min(board[i - 1][j],
                                  Math.min(board[i][j - 1], board[i - 1][j - 1])) + 1;
                    max = Math.max(max, board[i][j]);
                }
            }
        }

        return max * max;
    }
}