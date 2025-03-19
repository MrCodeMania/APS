class Solution {
    public int solution(String[] babbling) {
        int answer = 0;

        for(int i = 0; i < babbling.length; i++){
            int index = 0;
            String Last = "";
            if(babbling[i].length() == 2){
                if(babbling[i].equals("ye") || babbling[i].equals("ma")){
                    answer++;
                }
            }     
            while(index + 2 < babbling[i].length()){
                String two = babbling[i].substring(index, index + 2);
                String three = babbling[i].substring(index, index + 3);
                
                if((three.equals("aya") || three.equals("woo")) && !Last.equals(three)){
                    Last = three;
                    index += 3;
                    if(index == babbling[i].length()){
                        answer++;
                        break;
                    }
                } else if((two.equals("ye") || two.equals("ma")) && !Last.equals(two)){
                    Last = two;
                    index += 2;
                    if(index == babbling[i].length()){
                        answer++;
                        break;
                    }
                } else {
                    break;
                }

                if(index + 1 == babbling[i].length()) {
                    break;
                }

                if(index + 2 == babbling[i].length()){
                    two = babbling[i].substring(index, index + 2);
                    if((two.equals("ye") || two.equals("ma")) && !Last.equals(two)){
                        answer++;
                    }
                    break;
                }
            }
        }
        return answer;
    }
}