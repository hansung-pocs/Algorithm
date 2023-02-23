import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Backjoon1916{
    static int V, E;
    static int dist[];

    static List<List<Node>> list=new ArrayList<>();
    static PriorityQueue<Node> pq=new PriorityQueue<>((n1, n2)->Integer.compare(n1.cost, n2.cost));
    public static void main(String[] args) throws IOException {
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
        V=Integer.parseInt(br.readLine());
        E=Integer.parseInt(br.readLine());

        dist=new int[V+1];
        list.add(new ArrayList<>());
        for(int i=1; i<=V; i++)
            list.add(new ArrayList<>());

        StringTokenizer st;
        for(int i=0; i<E; i++){
            st=new StringTokenizer(br.readLine());
            int u=Integer.parseInt(st.nextToken());
            int v=Integer.parseInt(st.nextToken());
            int cost=Integer.parseInt(st.nextToken());

            list.get(u).add(new Node(v, cost));
        }

        st=new StringTokenizer(br.readLine());
        int start=Integer.parseInt(st.nextToken());
        int end=Integer.parseInt(st.nextToken());

        dijkstra(start);

        System.out.println(dist[end]);
        br.close();
    }

    static void dijkstra(int start){ //O(VlogE)
        Arrays.fill(dist, Integer.MAX_VALUE);
        dist[start]=0;

        pq.offer(new Node(start, 0));

        while(!pq.isEmpty()){ //V번 실행(정점의 개수)
            Node current=pq.poll(); //O(logE)

            if(dist[current.idx]<current.cost)
                continue;

            for(Node next:list.get(current.idx)){ //O(E)
                if(dist[next.idx]> current.cost+next.cost){
                    dist[next.idx]= current.cost+next.cost;
                    pq.offer(new Node(next.idx, dist[next.idx]));
                }
            }
        }
    }

    static class Node{
        int idx, cost;

        public Node(int idx, int cost) {
            this.idx = idx;
            this.cost = cost;
        }
    }
}
