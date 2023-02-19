import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.StringTokenizer;

public class Backjoon2573 {
    static int N,M;
    static int[][] arr;
    static boolean[][] visited;
    static List<Node> list=new ArrayList<>();

    static int[] px={-1,1,0,0};
    static int[] py={0,0,-1,1};
    public static void main(String[] args) throws IOException {
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st=new StringTokenizer(br.readLine());

        N=Integer.parseInt(st.nextToken());
        M=Integer.parseInt(st.nextToken());

        arr=new int[N][M];

        for(int y=0; y<N; y++){
            st=new StringTokenizer(br.readLine());
            for(int x=0; x<M; x++) {
                arr[y][x] = Integer.parseInt(st.nextToken());
                if(arr[y][x]!=0) list.add(new Node(x, y, arr[y][x]));
            }
        }


        Collections.sort(list, (o1, o2)->Integer.compare(o2.height, o1.height));

        int year=0;

        while(true){
            int count=0;
            visited=new boolean[N][M];
            for (Node node : list) {
                if(node.height==0) continue;

                if(!visited[node.y][node.x]){
                    dfs(node.x, node.y);
                    count++;
                }
            }

            if(count==0){
                System.out.println(0);
                return;
            }

            if(count>=2) break;

            decreaseHeight();
            for (Node node : list) {
                arr[node.y][node.x]=node.height;
            }

            year++;
        }

        System.out.println(year);

        br.close();
    }

    static void decreaseHeight(){
        for (Node node : list) {
            if(node.height==0) continue;
            int minusHeight=getDecreaseHeight(node.x, node.y);
            node.height-=minusHeight;
            if(node.height<0) node.height=0;
        }
    }

    static void dfs(int x, int y){
        visited[y][x]=true;

        for(int i=0; i<px.length; i++){
            int currentX=x+px[i];
            int currentY=y+py[i];

            if(isValidIndex(currentX, currentY)){
                if(!visited[currentY][currentX] && arr[currentY][currentX]!=0)
                    dfs(currentX, currentY);
            }
        }
    }

    static int getDecreaseHeight(int x, int y){
        int count=0;

        for(int i=0; i<px.length; i++){
            int currentX=x+px[i];
            int currentY=y+py[i];

            if(isValidIndex(currentX, currentY)
                    && arr[currentY][currentX]==0)
                count++;
        }

        return count;
    }

    static boolean isValidIndex(int x, int y){
        return (x>=0 && x<M) && (y>=0 && y<N);
    }

    static class Node{
        int x,y;
        int height;

        public Node(int x, int y, int height) {
            this.x = x;
            this.y = y;
            this.height = height;
        }
    }
}
