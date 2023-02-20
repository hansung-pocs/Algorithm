import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;

public class Boj_1759 {
    static int L;
    static int C;
    static String[] mo = {"a", "e", "i", "o", "u"};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine(), " ");
        L = Integer.parseInt(st.nextToken());
        C = Integer.parseInt(st.nextToken());
        ArrayList<String> arr = new ArrayList<>();
        StringTokenizer st2 = new StringTokenizer(br.readLine(), " ");
        while (st2.hasMoreTokens()) {
            arr.add(st2.nextToken());
        }
        Collections.sort(arr);
        BT(arr, 0, "", 0);
    }

    public static void BT(ArrayList<String> arr, int idx, String pass, int cnt) {
        if (pass.length() == L) {
            if (cnt >= 1 && pass.length() - cnt >= 2)
                System.out.println(pass);
            return;
        }
        StringBuilder passBuilder = new StringBuilder(pass);
        for (int i = idx; i < C; i++) {
            passBuilder.append(arr.get(i));
            int tempCnt = cnt + check(arr.get(i));
            BT(arr, i + 1, passBuilder.toString(), tempCnt);
            passBuilder.deleteCharAt(pass.length());
        }
    }

    public static int check(String s) {
        for (int i = 0; i < 5; i++) {
            if (s.equals(mo[i]))
                return 1;
        }
        return 0;
    }
}
