import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;
import java.util.List;

class Solution {
    public int[][] solution(int[][] data, String ext, int val_ext, String sort_by) {

        int idx = 0;
        String[] cmd = {"code", "date", "maximum", "remain"};

        for(int i = 0; i < 4; i++){
            if(cmd[i].equals(sort_by)){
                idx = i;
                break;
            }
        }

        int finalIdx = idx;
        Arrays.sort(data, new Comparator<int[]>(){
            @Override
            public int compare(int[] o1, int[] o2) {
                if(o1[finalIdx] > o2[finalIdx]) {
                    return 1;
                } else if(o1[finalIdx] == o2[finalIdx]){
                    return 0;
                } else {
                    return -1;
                }
            }
        });

        idx = 0;
        for(int i = 0; i < 4; i++){
            if(cmd[i].equals(ext)){
                idx = i;
                break;
            }
        }

        List<int[]> list = new ArrayList<>();

        for(int i = 0; i < data.length; i++){
            if(data[i][idx] < val_ext){
                list.add(data[i]);
            }
        }

        int[][] answer = new int[list.size()][];
        for(int i = 0; i < list.size(); i++){
            answer[i] = new int[4];
        }
        for(int i = 0; i < list.size(); i++){
            answer[i] = list.get(i);
        }

        return answer;
    }
}