import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class Backjoon15683 {
    static int N, M;
    static int[][] arr;
    static int[][] checked;
    static List<Cctv> list=new ArrayList<>();

    public static void main(String[] args) throws IOException {
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st=new StringTokenizer(br.readLine());

        N=Integer.parseInt(st.nextToken());
        M=Integer.parseInt(st.nextToken());

        arr=new int[N][M];
        checked=new int[N][M];
        
        // 사무실 정보를 입력받으며 Cctv 정보를 리스트에 저장한다.
       for(int y=0; y<N; y++){
           st=new StringTokenizer(br.readLine());
           for(int x=0; x<M; x++){
               arr[y][x]=Integer.parseInt(st.nextToken());
               if(arr[y][x]%6!=0) list.add(new Cctv(x, y, arr[y][x]));
           }
       }

       int minValue=N*M; // 사각지대수의 최대값은 N*M

        /**
         * 비트마스킹을 이용하여 Cctv 조합의 경우의 수를 표현
         * 각 조합에 따른 사각지대수를 구하고 minValue 를 갱신해준다.
         */
        for(int i=0; i<(1<<(2* list.size())); i++){
            initCheckedArr(arr, checked);
            int value=i;

            String answer="";
            for(int j=0; j<list.size(); j++){
                int direction=value%4;
                answer+=direction;
                value/=4;

                checkedByTypeWithDirection(list.get(j), direction);
            }

            minValue=Math.min(minValue, unCheckedCount(checked));
        }

        System.out.println(minValue);
       br.close();
    }

    // checked 배열 초기화 메서드
    static void initCheckedArr(int[][] arr, int[][] checked){
        for(int i=0; i<arr.length; i++)
            System.arraycopy(arr[i], 0, checked[i], 0, arr[i].length);
    }

    //사각지대수 count 메서드
    static int unCheckedCount(int[][]checked){
        int count=0;
        for (int[] checks : checked) {
            for (int check : checks) {
                if(check==0) count++;
            }
        }

        return count;
    }

    //Cctv 감시방향은 4방향, 설정된 방향에 따라 감시구역을 설정하는 메서드
    static void checkedByDirection(int x, int y, int direction){
        int i;

        switch(direction){
            case 0:
              for(i=x+1; i<M; i++){
                  if(checked[y][i]==6) break;

                  checked[y][i]=7;
              }
              break;
            case 1:
                for(i=y+1; i<N; i++){
                    if(checked[i][x]==6) break;

                    checked[i][x]=7;
                }

                break;
            case 2:
                for(i=x-1; i>=0; i--){
                    if(checked[y][i]==6) break;

                    checked[y][i]=7;
                }
                break;
            case 3:
                for(i=y-1; i>=0; i--){
                    if(checked[i][x]==6) break;

                    checked[i][x]=7;
                }
                break;
        }
    }

    // 타입과 회전에 따른 방향에 의해 감시 구역을 표시하는 메서드
    static void checkedByTypeWithDirection(Cctv cctv, int direction){
        int x=cctv.x;
        int y=cctv.y;
        int type=cctv.type;

        switch (type){
            case 1:
                checkedByDirection(x, y, direction);
                break;

            case 2:
                if(direction==0||direction==2){
                    checkedByDirection(x, y, 0);
                    checkedByDirection(x, y, 2);
                }else{
                    checkedByDirection(x, y, 1);
                    checkedByDirection(x, y, 3);
                }

                break;
            case 3:
                switch(direction){
                    case 0:
                        checkedByDirection(x, y, 0);
                        checkedByDirection(x, y, 3);
                        break;
                    case 1:
                        checkedByDirection(x, y, 0);
                        checkedByDirection(x, y, 1);
                        break;
                    case 2:
                        checkedByDirection(x, y, 1);
                        checkedByDirection(x, y, 2);
                        break;
                    case 3:
                        checkedByDirection(x, y, 2);
                        checkedByDirection(x, y, 3);
                        break;
                }
                break;

            case 4:
                switch (direction){
                    case 0:
                        checkedByDirection(x,y,0);
                        checkedByDirection(x,y,2);
                        checkedByDirection(x,y,3);
                        break;
                    case 1:
                        checkedByDirection(x,y,0);
                        checkedByDirection(x,y,1);
                        checkedByDirection(x,y,3);
                        break;
                    case 2:
                        checkedByDirection(x,y,0);
                        checkedByDirection(x,y,1);
                        checkedByDirection(x,y,2);
                        break;
                    case 3:
                        checkedByDirection(x,y,1);
                        checkedByDirection(x,y,2);
                        checkedByDirection(x,y,3);
                        break;
                }
                break;

            case 5:
                for(int i=0; i<4; i++)
                    checkedByDirection(x, y, i);
                break;
        }
    }

    //Cctv 표현 클래스
    static class Cctv{
        int x,y,type;

        public Cctv(int x, int y, int type) {
            this.x = x;
            this.y = y;
            this.type = type;
        }
    }
}
