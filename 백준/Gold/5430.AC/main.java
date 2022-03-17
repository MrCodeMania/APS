import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class problem {
    static int[] arr = new int[100001];

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int t = Integer.parseInt(br.readLine());

        for (int testcase = 0; testcase < t; testcase++) {

            Arrays.fill(arr, 0);


            String p = br.readLine();

            int n = Integer.parseInt(br.readLine());

            String[] str = br.readLine().split("[,\\[\\]]");

            int idx = 0;

            for (int i = 1; i < str.length; i++) {
                arr[idx++] = Integer.parseInt(str[i]);
            }

            int start = 0;
            int dir = 0;
            int error = 0;
            int cnt = 0;

            for (int i = 0; i < p.length(); i++) {
                if (p.charAt(i) == 'R')
                    dir = (dir + 1) % 2;
                else {
                    if (idx - 1 < start) {
                        error = 1;
                        break;
                    }
                    if (dir == 1)
                        arr[--idx] = 0;
                    else
                        arr[start++] = 0;
                    cnt++;
                }

            }

            if (error == 1)
                System.out.print("error");
            else {
                System.out.print("[");

                int a, b, c;
                if (dir == 0) {
                    a = 0;
                    b = n - 1;
                    c = 1;
                } else {
                    a = n - 1;
                    b = 0;
                    c = -1;
                }

                if (a >= 0) {
                    for (int i = a; i != b + c; i += c) {
                        if (arr[i] > 0) {
                            cnt++;
                            if (n - cnt == 0) {
                                cnt = i;
                                break;
                            }
                            System.out.print(arr[i] + ",");
                        }
                    }
                }
                if (arr[cnt] != 0)
                    System.out.print(arr[cnt]);
                System.out.print("]");
            }

            System.out.println();

        }

    }
}