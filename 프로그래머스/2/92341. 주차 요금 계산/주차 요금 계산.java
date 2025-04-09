import java.util.*;

class Solution {
    public int[] solution(int[] fees, String[] records) {
        int[] answer = {};
        TreeMap<String, List<Integer>> recordsByCarNum = new TreeMap<>();

        for (int i = 0; i < records.length; i++) {
            String[] temp = records[i].split(" ");
            String[] timeParts = temp[0].split(":");
            int time = Integer.parseInt(timeParts[0]) * 60 + Integer.parseInt(timeParts[1]);
            String carNum = temp[1];

            recordsByCarNum.putIfAbsent(carNum, new ArrayList<>());
            recordsByCarNum.get(carNum).add(time);
        }

        answer = new int[recordsByCarNum.size()];
        int index = 0;

        for (Map.Entry<String, List<Integer>> entry : recordsByCarNum.entrySet()) {
            List<Integer> times = entry.getValue();
            int inTime = 0;
            double totalInTime = 0;

            for (int i = 0; i < times.size(); i++) {
                if (i % 2 == 0) {
                    inTime = times.get(i);
                } else {
                    totalInTime += times.get(i) - inTime;
                }
            }

            if (times.size() % 2 == 1) {
                totalInTime += (23 * 60 + 59) - inTime;
            }
            
            answer[index++] = fees[1] + (int)Math.ceil(((totalInTime - fees[0] > 0 ? totalInTime - fees[0] : 0) / fees[2])) * fees[3];
        }

        return answer;
    }
}
