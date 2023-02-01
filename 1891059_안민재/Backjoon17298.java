import java.io.*;
import java.util.Stack;
import java.util.StringTokenizer;

public class Backjoon17298 {
    public static void main(String[] args) throws IOException {
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw=new BufferedWriter(new OutputStreamWriter(System.out));

        int n=Integer.parseInt(br.readLine());
        int[] arr=new int[n];

        Stack<Integer> stack=new Stack<>();
        int[] result=new int[n];

        StringTokenizer st=new StringTokenizer(br.readLine());
        for(int i=0; i<arr.length; i++)
            arr[i]=Integer.parseInt(st.nextToken());

        /**
         * 가장 오른쪽 값부터 오큰수 탐색 과정을 진행한다.
         * peek 이 오큰수가 아닐 경우, pop
         * 오큰수가 존재할 시(스택이 비지 않았을시) peek 을 결과로 넣어주고
         * 그 외 -1을 결과로 넣어준다.
         * 현재 탐색값을 오큰수 후보에 포함시켜 탐색간 착오가 없게 한다.
         */
        for(int i=arr.length-1; i>=0; i--){
            while(!stack.isEmpty()&&stack.peek()<=arr[i])
                stack.pop();

            result[i]=stack.isEmpty()?-1:stack.peek();

            stack.push(arr[i]);
        }

        for (int value : result) {
            bw.write(String.valueOf(value)+" ");
        }

        br.close();
        bw.flush();
        bw.close();
    }
}
