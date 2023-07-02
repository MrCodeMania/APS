class Solution {
        public int[] solution(int[] sequence, int k) {
            int[] answer = {0, 0};

            int shrt = 99999999;

            int sum = 0;
            int i = 0;
            for (int j = 0; j < sequence.length; j++) {
                sum += sequence[j];

                while(sum >= k){
                    if(sum == k) {
                        if (j - i + 1 < shrt) {
                            shrt = j - i + 1;
                            answer[0] = i;
                            answer[1] = j;
                        }
                    }
                    sum -= sequence[i++];
                }
            }
    
            return answer;
        }
    }