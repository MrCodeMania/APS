class Solution {

        public int[] solution(String[] keymap, String[] targets) {
            int[] answer = new int[targets.length];

            int[] minTimes = new int[26];

            for(int cnt = 0; cnt < 26; cnt++) {
                for (int i = 0; i < 100; i++) {
                    for (int j = 0; j < keymap.length; j++) {
                        if (keymap[j].length() <= i) {
                            continue;
                        }
                        if (keymap[j].charAt(i) == ('A' + cnt)) {
                            minTimes[cnt] = i + 1;
                            i = 100;
                            break;
                        }
                    }
                }
            }

            for(int i = 0; i < targets.length; i++){
                int sum = 0;
                answer[i] = -1;
                for(int j = 0; j < targets[i].length(); j++){
                    if(minTimes[targets[i].charAt(j) - 'A'] == 0){
                        sum = 0; break;
                    }
                    sum += minTimes[targets[i].charAt(j) - 'A'];
                }
                
                if(sum > 0){
                    answer[i] = sum;
                }
            }

            return answer;
        }
    }