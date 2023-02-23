import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class Main{
    static int N, M, totalDistance;
    static boolean[] visited;
    static int[][] city;
    static Node[] selectedChickenSpots;
    static List<Node> homes=new ArrayList<>();
    static List<Node> chickenList=new ArrayList<>();

    public static void main(String[] args) throws IOException {
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st=new StringTokenizer(br.readLine());
        N=Integer.parseInt(st.nextToken());
        M=Integer.parseInt(st.nextToken());

        city=new int[N][N];
        selectedChickenSpots=new Node[M];

        for(int i=0; i<N; i++){
            st=new StringTokenizer(br.readLine());
            for(int j=0; j<N; j++){
                city[i][j]=Integer.parseInt(st.nextToken());
                if(city[i][j]==1) homes.add(new Node(i, j));
                if(city[i][j]==2) chickenList.add(new Node(i,j));
            }
        }

        visited=new boolean[chickenList.size()];
        totalDistance=Integer.MAX_VALUE;
        dfs(0, 0);
        System.out.println(totalDistance);
        br.close();
    }

    static int getTotalChickenDistance(){
        int result=0;
        for (Node home : homes) {
            result+=getMinChickenDistance(home);
        }
        return result;
    }

    static int getMinChickenDistance(Node home){
        int minDistance=Integer.MAX_VALUE;
        for (Node spot : selectedChickenSpots) {
            minDistance=Math.min(minDistance, getChickenDistance(home, spot));
        }
        return minDistance;
    }

    static int getChickenDistance(Node home, Node chickenSpot){
        return Math.abs(home.x-chickenSpot.x)+Math.abs(home.y-chickenSpot.y);
    }

    static void dfs(int depth, int start){
        if(depth==M){
            totalDistance=Math.min(totalDistance, getTotalChickenDistance());
        }
        else{
            for(int i=start; i<visited.length; i++){
                if(!visited[i]){
                    visited[i]=true;
                    selectedChickenSpots[depth]=chickenList.get(i);
                    dfs(depth+1, i+1);
                    visited[i]=false;
                }
            }
        }
    }

    static class Node{
        int x,y;

        public Node(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }
}
