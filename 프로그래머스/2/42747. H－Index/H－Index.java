import java.util.*;

class Solution {
    public int solution(int[] citations) {
       
        Arrays.sort(citations);
        
        for (int i = citations.length; i >= 1; i--)
        {
            int index = citations.length - 1;

            while (citations[index] >= i)
            {
                if (index == citations.length - i)
                {
                    return i;
                }
                index--;
            }
        }
        
        return 0;
    }
}