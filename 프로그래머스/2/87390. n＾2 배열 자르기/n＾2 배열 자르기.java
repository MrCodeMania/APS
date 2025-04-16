class Solution {
    public int[] solution(int n, long left, long right) {
        int[] answer = new int[(int)(right - left) + 1]; // 결과 저장 배열

        // 왼쪽 시작 인덱스
        long quotient = (left / n);
        long remain = (left % n);

        // 첫 번째 값은 left에 맞춰 계산 시작
        long start = remain + 1;
        int index = 0; // answer 배열의 인덱스

        for (long i = left; i <= right; i++) {
            long row = i / n;
            long col = i % n;

            // 각 행의 값과 열의 값을 비교해 결과를 도출
            answer[index++] = (int) Math.max(row, col) + 1;
        }

        return answer;
    }
}