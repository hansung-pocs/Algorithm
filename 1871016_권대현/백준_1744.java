import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Collections;
import java.util.PriorityQueue;

public class 백준_1744 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());
        PriorityQueue<Integer> pq = new PriorityQueue<>(Collections.reverseOrder());
        PriorityQueue<Integer> rpq = new PriorityQueue<>();

        for (int i = 0; i < n; i++) {
            int value = Integer.parseInt(br.readLine());
            if (value < 0) {
                rpq.add(value);
            } else {
                pq.add(value);
            }
        }
        int sum = 0;
        while (pq.size() > 1 && pq.peek() != 0) {
            int v1 = pq.poll();
            if (!pq.isEmpty() && pq.peek() != 0) {
                int v2 = pq.poll();
                if (v1 > 1 && v2 > 1)
                    sum += v1 * v2;
                else {
                    sum += v1 + v2;
                }
            } else {
                sum += v1;
            }
        }
        while (rpq.size() > 1) {
            int v1 = rpq.poll();
            if (!rpq.isEmpty()) {
                int v2 = rpq.poll();
                sum += v1 * v2;
            }
        }
        while (pq.size() + rpq.size() > 0) {
            if (!pq.isEmpty() && !rpq.isEmpty()) {
                int v = pq.poll();
                int rv = rpq.poll();
                if (v != 0) {
                    sum += v + rv;
                }
            } else if (!pq.isEmpty()) {
                int v = pq.poll();
                sum += v;
            } else {
                int rv = rpq.poll();
                sum += rv;
            }
        }
        System.out.println(sum);
    }
}
