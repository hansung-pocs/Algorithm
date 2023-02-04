import java.io.*;
import static java.lang.Math.max;

public class 백준_9251 {
    static Integer[][] memo;
    static char[] s1;
    static char[] s2;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out)); //출력 라인
        s1 = br.readLine().toCharArray();
        s2 = br.readLine().toCharArray();
        memo = new Integer[s1.length][s2.length];
        int a = LCS(s1.length-1, s2.length-1);

        bw.write(String.valueOf(a));
        bw.flush();
    }

    public static int LCS(int i, int j) {
        if (i == -1 || j == -1) return 0;
        if (memo[i][j] == null) {
            if (s1[i] == s2[j]) {
                memo[i][j] = LCS(i - 1, j - 1) + 1;
            }
            else{
                memo[i][j] = max(LCS(i,j-1), LCS(i-1,j));
            }
        }
        return memo[i][j];
    }
}
