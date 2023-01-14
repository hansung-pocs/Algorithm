import java.util.*;
import java.io.*;

class Location{ 
    // 익은 토마토의 위치와 bfs상 탐색 레벨을 나타내는 클래스 Location
    int x, y, z, level;

    public Location(int x, int y, int z, int level){
        this.x=x;
        this.y=y;
        this.z=z;
        this.level=level;
    }
}

public class Main{
    public static int M, N, H;
    // 각각 가로길이(x), 세로길이(y), 높이(H)
    public static int box[][][];
    public static int count;
    // 토마토가 다 익는데 필요한 일수 count 변수
    public static int px[]={-1,1,0,0,0,0};
    public static int py[]={0,0,-1,1,0,0};
    public static int pz[]={0,0,0,0,-1,1};
    // 상하좌우전후 탐색을 위한 x, y, z 좌표 세팅
    public static Queue<Location> q;
    // 익은 토마토의 위치를 저장할 큐
    public static void main(String[] args) throws IOException{
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));

        StringTokenizer st=new StringTokenizer(br.readLine());
        M=Integer.parseInt(st.nextToken());
        N=Integer.parseInt(st.nextToken());
        H=Integer.parseInt(st.nextToken());

        box=new int[H+1][N+1][M+1];
        // 3차원 배열의 경우 초기화시 new int[z][y][x] 의 형태를 초기화해야한다.
        q=new LinkedList<Location>();

        for(int h=1; h<=H; h++){
            for(int i=1; i<=N; i++){
                st=new StringTokenizer(br.readLine());
                for(int j=1; j<=M; j++){
                    box[h][i][j]=Integer.parseInt(st.nextToken());
                    if(box[h][i][j]==1){
                        q.add(new Location(i, j, h, 0));
                    }
                    // 익은 토마토일 경우 bfs 탐색하며 다 익는데 걸리는 일수를 구하기 위해
                    // 값을 받으며 미리 큐에 넣어준다.
                }
            }
        }

        if(check()){ // 토마토가 이미 다 익어있을 경우 0출력후 종료
            System.out.print(0);
            return;
        }

        count=0;
        bfs();

        if(!check()){ 
            // bfs 탐색후에도 토마토가 다 익지 않았을 경우
            // 익을 수 없는 위치(-1로 0이 둘러쌓여있거나 하는)
            // 에 존재한다는 의미이므로 -1 출력후 종료
            System.out.print(-1);
            return;
        }

        System.out.print(count);
        // 위 두 케이스 통과시 다 익는데 걸린 일수 출력
        br.close();

    }

    public static boolean check(){ //토마토가 다 익었는지 체크하는 함수
        for(int h=1; h<=H; h++)
            for(int i=1; i<=N; i++)
                for(int j=1; j<=M; j++)
                    if(box[h][i][j]==0) return false;
        // 3차원 배열이 [높이][세로][가로] 형식이므로 그에 맞게 루프 설정
        // 루프 도중 안 익은 토마토 발견 시 false return
        return true;
    }

    public static void bfs(){
        while(!q.isEmpty()){ 
            Location tomato=q.poll();
            count=tomato.level;
            //count 를 현재 탐색 중인 토마토의 bfs 레벨로 갱신해주며 진행한다.

            for(int i=0; i<6; i++){
                int x=tomato.x+px[i];
                int y=tomato.y+py[i];
                int z=tomato.z+pz[i];
                // 상하좌우전후 탐색을 위한 좌표 세팅

                if(x>=1 && x<=N && y>=1 && y<=M && z>=1 && z<=H){
                    // 좌표가 정상적인 인덱스 범위 내에 있으며
                    if(box[z][x][y]==0){
                        // 해당 좌표의 토마토가 익지 않았으면
                        box[z][x][y]=1;
                        // 익게 만들어준 후
                        q.offer(new Location(x, y, z, tomato.level+1));
                        // 해당 익은 토마토 위치에서 탐색을 실시할 수 있도록
                        // 큐에 토마토의 위치를 넣어준다. 익은 일수 파악을 위해
                        // 현재 탐색 토마토 레벨에 1을 더해 위치를 생성하여 넣는다.
                    }
                }
            }
        }
    }
}
