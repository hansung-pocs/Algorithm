import java.io.*;
        import java.util.*;

public class 백준_17298 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();

        int n = Integer.parseInt(br.readLine());
        int[] arr = new int[n];
        Stack<Integer> stack = new Stack<>();
        StringTokenizer st = new StringTokenizer(br.readLine());

        for (int i = 0; i < n; i++) {
            int value = Integer.parseInt(st.nextToken());
            arr[i] = value;
        }
        for (int i = 0; i < n; i++) {
            while(!stack.empty() && arr[stack.peek()]<arr[i]){
                arr[stack.pop()] = arr[i];
            }
            stack.push(i);
        }

        while (!stack.empty()){
            arr[stack.pop()] = -1;
        }

        arr[n - 1] = -1;
        for (int i = 0; i < n; i++) {
            sb.append(arr[i]).append(" ");
        }
        System.out.println(sb);
    }
}
