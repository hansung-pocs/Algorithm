import java.io.*;
import java.util.Arrays;
import java.util.StringTokenizer;

/**
 * 이 풀이는 바람직한 풀이는 아니나, dp를 구현한 한 방식으로써
 * 소개하는 바이다.
 */
public class Backjoon2096 {
    static int N;
    static int[][] value; // 원 배열값을 저장하기 위한 배열
    static int[][] minDp; // 누적 최소값을 도출하기 위한 dp 배열
    static int[][] maxDp; // 누적 최대값을 도출하기 위한 dp 배열
    public static void main(String[] args) throws IOException {
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));

        N=Integer.parseInt(br.readLine());

        value=new int[N][3];
        minDp=new int[N][3];
        maxDp=new int[N][3];

        for(int i=0; i<N; i++){
            StringTokenizer st=new StringTokenizer(br.readLine());
            for(int j=0; j<3; j++){
                value[i][j]=Integer.parseInt(st.nextToken());
                if(i==0){
                    minDp[i][j]=value[i][j];
                    maxDp[i][j]=value[i][j];
                }
                else{ // dp 배열의 초기값을 -1로 둔다.
                    minDp[i][j]=-1;
                    maxDp[i][j]=-1;
                }
            }
        }

        for(int y=0; y<N-1; y++)
            for(int x=0; x<3; x++){
                renewMinValue(y, x);
                renewMaxValue(y,x);
            }

        Arrays.sort(minDp[N-1]);
        Arrays.sort(maxDp[N-1]);
        System.out.println(maxDp[N-1][2]+" "+minDp[N-1][0]);

        br.close();
    }

    /**
     * 아래 메서드들은 dp 배열을 갱신하는 메서드들로
     * 현재 위치에서 이동가능한 위치의 dp배열값을 
     * 현재 위치 dp배열값 + 이동위치 원 배열 값과
     * 비교하여 작거나 클시 dp 배열을 갱신해주는 로직으로 구성되어 있다.
     */
    static void renewMinValue(int y, int x){
        if(minDp[y+1][x]==-1)
            minDp[y+1][x]=minDp[y][x]+value[y+1][x];
        else{
            if(minDp[y+1][x]>minDp[y][x]+value[y+1][x])
                minDp[y+1][x]=minDp[y][x]+value[y+1][x];
        }

        switch(x){
            case 0:
                if(minDp[y+1][x+1]==-1)
                    minDp[y+1][x+1]=minDp[y][x]+value[y+1][x+1];
                else{
                    if(minDp[y+1][x+1]>minDp[y][x]+value[y+1][x+1])
                        minDp[y+1][x+1]=minDp[y][x]+value[y+1][x+1];
                }
                break;
            case 1:
                if(minDp[y+1][x-1]==-1)
                    minDp[y+1][x-1]=minDp[y][x]+value[y+1][x-1];
                else{
                    if(minDp[y+1][x-1]>minDp[y][x]+value[y+1][x-1])
                        minDp[y+1][x-1]=minDp[y][x]+value[y+1][x-1];
                }

                if(minDp[y+1][x+1]==-1)
                    minDp[y+1][x+1]=minDp[y][x]+value[y+1][x+1];
                else{
                    if(minDp[y+1][x+1]>minDp[y][x]+value[y+1][x+1])
                        minDp[y+1][x+1]=minDp[y][x]+value[y+1][x+1];
                }

                break;
            case 2:
                if(minDp[y+1][x-1]==-1)
                    minDp[y+1][x-1]=minDp[y][x]+value[y+1][x-1];
                else{
                    if(minDp[y+1][x-1]>minDp[y][x]+value[y+1][x-1])
                        minDp[y+1][x-1]=minDp[y][x]+value[y+1][x-1];
                }
                break;
        }
    }

    static void renewMaxValue(int y, int x){
        if(maxDp[y+1][x]==-1)
            maxDp[y+1][x]=maxDp[y][x]+value[y+1][x];
        else{
            if(maxDp[y+1][x]<maxDp[y][x]+value[y+1][x])
                maxDp[y+1][x]=maxDp[y][x]+value[y+1][x];
        }

        switch(x){
            case 0:
                if(maxDp[y+1][x+1]==-1)
                    maxDp[y+1][x+1]=maxDp[y][x]+value[y+1][x+1];
                else{
                    if(maxDp[y+1][x+1]<maxDp[y][x]+value[y+1][x+1])
                        maxDp[y+1][x+1]=maxDp[y][x]+value[y+1][x+1];
                }
                break;
            case 1:
                if(maxDp[y+1][x-1]==-1)
                    maxDp[y+1][x-1]=maxDp[y][x]+value[y+1][x-1];
                else{
                    if(maxDp[y+1][x-1]<maxDp[y][x]+value[y+1][x-1])
                        maxDp[y+1][x-1]=maxDp[y][x]+value[y+1][x-1];
                }

                if(maxDp[y+1][x+1]==-1)
                    maxDp[y+1][x+1]=maxDp[y][x]+value[y+1][x+1];
                else{
                    if(maxDp[y+1][x+1]<maxDp[y][x]+value[y+1][x+1])
                        maxDp[y+1][x+1]=maxDp[y][x]+value[y+1][x+1];
                }

                break;
            case 2:
                if(maxDp[y+1][x-1]==-1)
                    maxDp[y+1][x-1]=maxDp[y][x]+value[y+1][x-1];
                else{
                    if(maxDp[y+1][x-1]<maxDp[y][x]+value[y+1][x-1])
                        maxDp[y+1][x-1]=maxDp[y][x]+value[y+1][x-1];
                }
                break;
        }
    }
}
