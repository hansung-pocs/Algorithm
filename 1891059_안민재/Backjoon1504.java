import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

import static java.lang.Integer.*;

public class Backjoon1504 {
    static int N,E;
    static int V1, V2;
    static int[] dist;
    static List<List<Node>> list=new ArrayList<>();

    public static void main(String[] args) throws IOException {
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st=new StringTokenizer(br.readLine());
        N= parseInt(st.nextToken());
        E= parseInt(st.nextToken());

        dist=new int[N+1];
        list.add(null);
        for(int i=0; i<N; i++)
            list.add(new ArrayList<>());

        for(int i=0; i<E; i++){
            st=new StringTokenizer(br.readLine());
            int u= parseInt(st.nextToken());
            int v=parseInt(st.nextToken());
            int w=parseInt(st.nextToken());

            list.get(u).add(new Node(v, w));
            list.get(v).add(new Node(u, w));
        }

        st=new StringTokenizer(br.readLine());
        V1=parseInt(st.nextToken());
        V2=parseInt(st.nextToken());

        Integer[] route1=new Integer[3];
        Integer[] route2=new Integer[3];

        dijkstra(1);
        route1[0]=dist[V1];
        route2[0]=dist[V2];

        dijkstra(V1);

        route1[1]=dist[V2];

        route2[1]=dist[V2];
        route2[2]=dist[N];

        dijkstra(V2);
        route1[2]=dist[N];


        Integer result=Math.min(getPathCost(route1), getPathCost(route2));
        System.out.println(result==MAX_VALUE?-1:result);
        br.close();
    }

    static Integer getPathCost(Integer[] route){
        int pathCost=0;
        for (int cost : route) { //O(3)
            if(cost==MAX_VALUE)
                return MAX_VALUE;

            pathCost+=cost;
        }

        return pathCost;
    }

    static void dijkstra(int start){
        PriorityQueue<Node> pq=new PriorityQueue<>(Comparator.comparingInt(n->n.weight));

        Arrays.fill(dist, MAX_VALUE);
        dist[start]=0;
        pq.offer(new Node(start, 0));

        while(!pq.isEmpty()){ //O(N)
            Node current=pq.poll(); //O(logE)

            if(dist[current.number]<current.weight)
                continue;

            for (Node node : list.get(current.number)) { //O(N_E)
                if(dist[node.number]>current.weight+node.weight){
                    dist[node.number]=current.weight+node.weight;
                    pq.offer(new Node(node.number, dist[node.number])); // O(logE)
                }
            }
        }
    }
    static class Node{
        int number;
        int weight;

        public Node(int number, int weight) {
            this.number = number;
            this.weight = weight;
        }
    }
}
