import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.Arrays;
import java.util.Iterator;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(br.readLine());
        for (int i = 0; i < T; i++) {
            String p = br.readLine();
            int n = Integer.parseInt(br.readLine());
            String x = br.readLine();
            ArrayDeque<String> deque = strToDeque(n, x);
            runAC(p, deque);
        }
    }

    public static ArrayDeque<String> strToDeque(int n, String x) {
        x = x.substring(1, x.length() - 1);
        String[] strArr = x.split(",");
        return new ArrayDeque<>(Arrays.asList(strArr).subList(0, n));
    }

    public static void runAC(String p, ArrayDeque<String> deque) {
        String[] commands = p.split("");
        boolean reverseSwitch = false;
        for (String command : commands) {
            switch (command) {
                case "R":
                    reverseSwitch = !reverseSwitch;
                    break;
                case "D":
                    if (deque.isEmpty()) {
                        System.out.println("error");
                        return;
                    }
                    if (!reverseSwitch) {
                        deque.pollFirst();
                    } else {
                        deque.pollLast();
                    }
                    break;
            }
        }
        if (!reverseSwitch) {
            System.out.println(deque.toString().replaceAll(" ",""));
        } else {
            System.out.println(reverseToString(deque).replaceAll(" ",""));
        }
    }

    public static String reverseToString(ArrayDeque<String> deque) {
        Iterator<String> it = deque.descendingIterator();
        if (!it.hasNext())
            return "[]";

        StringBuilder sb = new StringBuilder();
        sb.append('[');
        while (it.hasNext()) {
            String e = it.next();
            sb.append(e);
            if (!it.hasNext()) {
                sb.append(']');
                break;
            }
            sb.append(',').append(' ');
        }
        return sb.toString();
    }
}
