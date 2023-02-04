import java.io.BufferedReader;
import java.io.InputStreamReader;

public class BJ_17609 {

	static int N;

	public static void main(String[] args) throws Exception {

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		StringBuilder sb = new StringBuilder();

		N = Integer.parseInt(br.readLine());

		for (int i = 0; i < N; i++) {
			String str = br.readLine();
			sb.append(solve(str)).append('\n');
		}

		System.out.println(sb);

	}

	private static String solve(String str) {

		String answer = "0";

		String rev = new StringBuilder(str).reverse().toString();
		if (str.equals(rev)) {
			answer = "0";
		} else {
			int start = 0;
			int end = str.length() - 1;
			while (start <= end) {
				String str1 = null;
				String rev1 = null;
				if (str.charAt(start) != str.charAt(end)) {
					if (str.charAt(start + 1) == str.charAt(end)) {
						str1 = new StringBuilder(str).deleteCharAt(start).toString();
						rev1 = new StringBuilder(str1).reverse().toString();
						if (!str1.equals(rev1)) {
							if (str.charAt(start) == str.charAt(end - 1)) {
								str1 = new StringBuilder(str).deleteCharAt(end).toString();
							}
						}
					} else if (str.charAt(start) == str.charAt(end - 1)) {
						str1 = new StringBuilder(str).deleteCharAt(end).toString();
						rev1 = new StringBuilder(str1).reverse().toString();
						if (!str1.equals(rev1)) {
							if (str.charAt(start + 1) == str.charAt(end)) {
								str1 = new StringBuilder(str).deleteCharAt(start).toString();
							}
						}
					} else {
						answer = "2";
						break;
					}

					String Afrev = new StringBuilder(str1).reverse().toString();
					if (str1.equals(Afrev)) {
						answer = "1";
						break;
					} else {
						answer = "2";
						break;
					}
				}
				start++;
				end--;
			}
		}

		return answer;
	}

}