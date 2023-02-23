import java.io.*;
import java.util.StringTokenizer;
import java.util.regex.Pattern;

public class Boj_1987 {
    static int R;
    static int C;
    static int MAX;
    static int[] X = {-1, 0, 1, 0};
    static int[] Y = {0, -1, 0, 1};
    static boolean[] have = new boolean[26];

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine(), " ");
        R = Integer.parseInt(st.nextToken());
        C = Integer.parseInt(st.nextToken());
        char[][] graph = new char[R][C];
        for (int i = 0; i < R; i++) {
            String str = br.readLine();
            for (int j = 0; j < C; j++) {
                graph[i][j] = str.charAt(j);
            }

        }
        MAX = Integer.MIN_VALUE;
        BT(graph, 0, 0, "");
        bw.write(String.valueOf(MAX));
        bw.flush();
        bw.close();
    }

    public static void BT(char[][] graph, int x, int y, String s) {
        StringBuilder sBuilder = new StringBuilder(s);
        sBuilder.append(graph[x][y]);
        int alpha = graph[x][y]-'A';
        have[alpha] = true;
        for (int i = 0; i < 4; i++) {
            int nextX = x + X[i];
            int nextY = y + Y[i];
            if (nextX >= 0 && nextX < R && nextY >= 0 && nextY < C) {
                if (!have[graph[nextX][nextY]-'A']) {
                    BT(graph, nextX, nextY, sBuilder.toString());
                }
            }
            if (MAX < sBuilder.toString().length()) {
                MAX = sBuilder.toString().length();
            }
        }
        have[alpha] = false;
        sBuilder.deleteCharAt(sBuilder.toString().length() - 1);
    }
}
