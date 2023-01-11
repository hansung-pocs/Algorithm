import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class BJ_18111 {

	// 백준알고리즘 18111번 마인크래프트
	// mama 없는 corea soccer 같은 문제네요.
    // 구현 과 브루투포스 알고리즘의 복합문제였습니다.

	static int N;
	static int M;
	static int B;
	static int time = Integer.MAX_VALUE;
	static int height;
	static int[] result = new int[2];
	static int[][] arr;

	public static void main(String[] args) throws Exception {

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		StringTokenizer st = new StringTokenizer(br.readLine());
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		B = Integer.parseInt(st.nextToken()); // 인벤토리에 현재 내가 가지고있는 블록 수

		// 블록을 캐서 인벤토리에 넣는 작업은 2초
		// 인벤토리에서 블록을 꺼내어 놓는 작업은 1초

		arr = new int[N][M];
		int max = 0;

		for (int i = 0; i < N; i++) {
			st = new StringTokenizer(br.readLine());
			for (int j = 0; j < M; j++) {
				arr[i][j] = Integer.parseInt(st.nextToken());
				max = Math.max(max, arr[i][j]);
			}
		}

		solve(max);

		System.out.println(time + " " + height);
	}

	private static void solve(int max) {

		for (int i = 0; i <= max; i++) {
			result = excavation(i);
			if (time > result[0]) {
				time = result[0];
				height = result[1];
			} else if (time == result[0] && height < result[1]) {
				time = result[0];
				height = result[1];
			}
		}
	}

	private static int[] excavation(int height) {

		int block = B;
		int time = 0;

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				int value = arr[i][j];

				if (value == height) {
					continue;
				}
				if (value > height) {
					time += (value - height) * 2;
					block += (value - height);
				} else {
					time += height - value;
					block -= (height - value);
				}
			}
		}
		if (block < 0) {
			result[0] = 999999999;
			return result;
		}

		result[0] = time;
		result[1] = height;

		return result;

	}

}
