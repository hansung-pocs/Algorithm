import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Backjoon9663 {
    static int N;
    static int[] trace;
    static int count=0;

    public static void main(String[] args) throws IOException {
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
        N=Integer.parseInt(br.readLine());

        trace=new int[N];

        dfs(0);
        System.out.println(count);
    }

    static boolean isValid(int depth){
        for(int i=0; i<depth; i++){
            if(trace[i]==trace[depth] || depth-i == Math.abs(trace[depth]-trace[i]))
                return false;
        }

        return true;
    }

    static void dfs(int depth){
        if(depth==N){
            count++;
        } else{
          for(int i=0; i<N; i++){
              trace[depth]=i;
              if(isValid(depth)){
                  dfs(depth+1);
              }
          }
        }
    }
}
