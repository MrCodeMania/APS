
import java.util.*;

class Solution {

    int countOnes(int n, long index) {
        if (n == 0) return index >= 0 ? 1 : 0;

        long sectionSize = (long)Math.pow(5, n - 1);
        long onesPerSection = (long)Math.pow(4, n - 1);

        for (int i = 0; i < 5; i++) {
            long start = sectionSize * i;
            long end = sectionSize * (i + 1) - 1;

            if (start <= index && index <= end) {
                if (i == 2) return (int)(onesPerSection * 2);
                if (i < 2) return (int)(countOnes(n - 1, index - start) + onesPerSection * i);
                return (int)(countOnes(n - 1, index - start) + onesPerSection * (i - 1));
            }
        }
        return 0;
    }

    public int solution(int n, long l, long r) {
        return countOnes(n, r - 1) - countOnes(n, l - 2);
    }
}