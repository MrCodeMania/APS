import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;



public class Main {

    static class Station implements Comparable<Station>{
        private long cost;
        private int index;

        public Station(long cost, int index){
            this.cost = cost;
            this.index = index;
        }

        @Override
        public int compareTo(Station s){
            if(this.cost < s.cost)
                return -1;
            else if (this.cost > s.cost)
                return 1;
            else {
                if(this.index < s.index)
                    return -1;
                else if (this.index > s.index)
                    return 1;
                else return 0;
            }
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.valueOf(br.readLine());

        String[] dist = br.readLine().split(" ");
        String[] money = br.readLine().split(" ");

        int index = 0;
        List<Station> stations = new ArrayList<>();

        long[] totalDist = new long[100001];

        for(int i = 0; i < N; i++){
            stations.add(new Station(Long.valueOf(money[i]), i));
            if(i < N - 1) {
                totalDist[i] = Long.valueOf(dist[i]);
            }
        }

        for(int i = N - 1; i >= 0; i--){
            totalDist[i] += totalDist[i + 1];
        }

        Collections.sort(stations);

        // 최솟값의 인덱스부터 처리하지 않은 dist까지 연산
        // 전 인덱스보다 높은 경우 continue;
        // 전 인덱스보다 낮은 경우 처리한 dist만큼 제거 후 연산

        int lastIndex = 100001;
        long sum = 0;
        long calcDist = 0;

        for(int i = 0; i < N; i++) {
            long cost = stations.get(i).cost;
            int idx = stations.get(i).index;

            if(idx > lastIndex){
                continue;
            } else {
                sum += cost * (totalDist[idx] - calcDist);
                calcDist += totalDist[idx] - calcDist;
                lastIndex = idx;
            }

            if(calcDist == totalDist[0]){
                break;
            }
        }

        System.out.println(sum);
    }
}