import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class BJ_1025 {

	static int N, M;
	static int[][] array;
	static String[] arr;
	static int answer = -1;

	public static void main(String[] args) throws IOException {

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());

		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());

		arr = new String[N + 1];
		array = new int[N][M];

		for (int i = 0; i < N; ++i) {
			arr[i] = br.readLine();
			for (int j = 0; j < M; ++j) {
				array[i][j] = arr[i].charAt(j) - '0';
			}
		} // 입력부분

		for (int i = 0; i < N; ++i) { 
			for (int j = 0; j < M; ++j) { 

				solve(j, i);
			}
		}

		System.out.println(answer);

	}

	public static void solve(int c, int r) {
		for (int i = -N; i < N; ++i) { 
			for (int j = -M; j < M; ++j) {

				if (i == 0 && j == 0)
					continue; 

				int x = c; 
				int y = r; 

				int sqr = 0;

				while (0 <= x && x < M && 0 <= y && y < N) {
					sqr *= 10;
					sqr += array[y][x];

					int root = (int) Math.sqrt(sqr);

					if (Math.pow(root, 2) == sqr)
						answer = Math.max(answer, sqr);

					x += j;
					y += i;
				}
			}
		}
	}

}
