import java.io.BufferedReader;
import java.io.InputStreamReader;

public class BJ_12919 {

	static String S;
	static String T;
	static int answer = 0;

	public static void main(String[] args) throws Exception {
		// TODO Auto-generated method stub

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		S = br.readLine();
		T = br.readLine();

		solve(S, T);

		System.out.println(answer);

	}

	private static void solve(String s, String t) {
		if (s.length() == t.length()) {
			if (s.equals(t)) {
				answer = 1;
			}

			return;
		}
		int ans = 0;
		if (t.charAt(0) == 'B') {
			String substring = t.substring(1);
			StringBuilder sb = new StringBuilder(substring);
			String string = sb.reverse().toString();
			solve(s, string);
		}

		if (t.charAt(t.length() - 1) == 'A') {
			solve(s, t.substring(0, t.length() - 1));
		}
		return;

	}

}
