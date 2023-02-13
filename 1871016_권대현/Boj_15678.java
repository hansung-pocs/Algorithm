import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Comparator;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class Boj_15678 {
    static class Pair {
        int index;
        long value;

        public Pair(int index, long value) {
            this.index = index;
            this.value = value;
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine(), " ");
        int N = Integer.parseInt(st.nextToken());
        int D = Integer.parseInt(st.nextToken());
        PriorityQueue<Pair> pq = new PriorityQueue<>(((o1, o2) -> Long.compare(o2.value, o1.value)));

        StringTokenizer st2 = new StringTokenizer(br.readLine(), " ");

        long max = Long.MIN_VALUE;

        for (int i = 1; i <= N; i++) {
            // 더이상 더할 수 없는 값(index + D 값이 i보다 작은)을 지워준다.
            while (!pq.isEmpty() && pq.peek().index + D < i) {
                pq.poll();
            }
            long tmp = 0;

            // 0보다 크고, 더할 수 있는 값 중 가장 큰 값
            // 0보다 커야 음수가 연속으로 나올 때 더하는 것을 방지할 수 있다.
            if(!pq.isEmpty() && pq.peek().value>0){
                tmp = pq.peek().value;
            }
            // 다음에 들어올 값과 위의 계산한 값 더해서 추가
            tmp += Integer.parseInt(st2.nextToken());
            pq.add(new Pair(i, tmp));
            // 가장 큰 값을 저장한 max와 비교
            max = Math.max(tmp, max);
        }
        System.out.println(max);
    }
}
