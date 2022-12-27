import java.util.Scanner;

public class BJ_10974 {
	// 백준알고리즘 10974번 모든순열
	static int N;
	static int[] arr;
	static boolean[] visited;
	static int[] output;

	public static void main(String[] args) {
		// TODO Auto-generated method stub

		Scanner sc = new Scanner(System.in);
		N = sc.nextInt();

		arr = new int[N];
		output = new int[N];
		visited = new boolean[N];

		for (int i = 0; i < N; i++) {
			arr[i] = i + 1;
		}

		perm(arr, output, visited, 0, N, N);

	}

	// 순서를 지키면서 n 개중에서 r 개를 뽑는 경우
	static void perm(int[] arr, int[] output, boolean[] visited, int depth, int n, int r) {
		if (depth == r) {
			print(output, r);
			return;
		}

		for (int i = 0; i < n; i++) {
			if (visited[i] != true) {
				visited[i] = true;
				output[depth] = arr[i];
				perm(arr, output, visited, depth + 1, n, r);
				visited[i] = false;
				;
			}
		}
	}

	static void print(int[] arr, int r) {
		for (int i = 0; i < r; i++)
			System.out.print(arr[i] + " ");
		System.out.println();
	}
}
