import java.util.Scanner;
import java.util.ArrayList;
import java.util.List;
// 백준알고리즘 1174번 줄어드는수

public class BJ_1174 {

	static int N;
	static int[] arr = { 9, 8, 7, 6, 5, 4, 3, 2, 1, 0 };
	static List<Long> list = new ArrayList<>();

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		N = sc.nextInt();

		DFS(0, 0);
		list.sort(null);

		try {
			System.out.println(list.get(N - 1));
		} catch (Exception e) {
			System.out.println(-1);
		}

	}

	public static void DFS(long num, int inx) {
		if (!list.contains(num)) {
			list.add(num);
		}

		if (inx >= 10) {
			return;
		}

		DFS((num * 10 + arr[inx]), inx + 1);
		DFS(num, inx + 1);
	}
}
