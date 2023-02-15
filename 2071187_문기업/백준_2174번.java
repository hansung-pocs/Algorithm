import java.util.Vector;
import java.util.Scanner;

class Simulator{


    private int width,height;

    private Robot robot[]; // simulation에 사용할 로봇들을 담는다.
    private int robotNum=0;
    private int size=0;

    private Vector<Integer> v1=new Vector<Integer>();
    private Vector<Character> v2=new Vector<Character>();
    private int repeat[];
    private int repeatNum=0;
    private int repeatSize=0;

    public int getHeight(){return height;} // 가로,세로 길이를 반환해준다.
    public int getWidth(){return width;}


    public void appendRobot(Robot r) //시물레이션에 로봇을 추가해주는 함수..
    {
        robot[size++]=r;
    }



    public Robot reRobot(int num){ //해당로봇을 리턴해준다.
        return robot[num];
    }

    public int robotNum(){
        return robotNum;
    }
    public int robotIndex(Robot r){
        int num=0;
        for(int i=0;i<robotNum;i++)
        {
            if(robot[i]==r)
            {
                num=i;
            }
        }
        return num;
    }
    public boolean wallCrush(Robot r) // 로봇이 벽에 충돌하는지 좌표로 확인하기
    {
        if(r.rx()<1||r.rx()>getWidth()|| r.ry()<1 || r.ry()>getHeight()){
            return true;
        }
        return false;
    }

    public boolean robotCrush(Robot r) // 로봇이 다른 로봇과 충돌하는지 확인하기
    {

        for(int i=0;i<robotNum();i++)
        {
            if(reRobot(i)==r) // 현재로봇과 같으면 지나간다.
                continue;

            if(r.rx()==reRobot(i).rx() && r.ry()==reRobot(i).ry() ) // x,y좌표가 같으면 경고문출력, true반환
            {
                System.out.println("Robot "+(robotIndex(r)+1)+" crashes into robot "+(i+1) );
                return true;
            }
        }

        return false; //아닐경우 false리턴...
    }



    public void run(){
        int A,B,N,M;
        Scanner sc=new Scanner(System.in);

        A=sc.nextInt(); B=sc.nextInt();
        this.width=A; this.height=B;

        N=sc.nextInt(); M=sc.nextInt();
        this.robotNum=N; robot=new Robot[N];
        this.repeatNum=M; //몇번 반복하는지 정해준다,
        repeat=new int[repeatNum];

        for(int i=0;i<N;i++) //robot먼저 생성
        {
            int x=sc.nextInt();
            int y=sc.nextInt();
            char dir=sc.next().charAt(0);
            //정보를 입력받은 뒤, 로봇객체 생성, 로봇추가
            Robot r=new Robot(x,y,dir);
            appendRobot(r);
        }


        for(int i=0;i<M;i++) //명령 수행
        {
            int num=sc.nextInt();
            char command=sc.next().charAt(0);
            int eachRepeat=sc.nextInt();

            v1.add(num); v2.add(command);
            repeat[repeatSize++]=eachRepeat;

        }

        int check=0;
        for(int i=0;i<M;i++)
        {

            int num=v1.get(i); char command=v2.get(i);
            for(int j=0;j<repeat[i];j++)
            {
                robot[num-1].command(command); //명령어,방향, 로봇번호 입력
                // 로봇 및 벽 충돌확인
                if(wallCrush(robot[num-1]))
                {
                    System.out.println("Robot "+num+" crashes into the wall" );
                    check=1;
                    break;
                }
                if(robotCrush(robot[num-1]))
                {
                    check=1;
                    break;
                }

            }
            if(check==1)
                break;
        }
        if(check==0)
            System.out.println("OK");

    }


}

class Robot {
    private int loc[]=new int[2];
    private char direction;

    private int go[][]={{1,0},{0,1},{-1,0},{0,-1}}; // 이동좌표 벡터
    private char dir[]={'E','N','W','S'}; // 방향

    public Robot(int x,int y, char direction) // 생성자를 만들어준다.
    {
        this.loc[0]=x;
        this.loc[1]=y;
        this.direction=direction;
    }




    public int rx(){return this.loc[0];}
    public int ry(){return this.loc[1];}

    public char reDirection(int num)
    {
        return dir[num];
    }


    public int[] gogo(char dir) //이동함수
    {
        int []arr=new int[2];
        switch(dir){
            case'E': arr= go[0];break;
            case'N': arr= go[1];break;
            case'W': arr= go[2];break;
            case'S': arr= go[3];break;
        }
        return arr;
    }

    public char getDirection(){return direction;}


    public void command(char command) // command는 명령, dir은 향하고 있는 방향 , N은 로봇 번호
    {
        int arr[]=gogo(direction);
        int x=arr[0];
        int y=arr[1];

        if(command=='F'){
            loc[0]+=x;
            loc[1]+=y;
        }
        else {
            int length=4; //방향의 종류
            int now=0; // 현재의 방향의 인덱스

            for(int i=0;i<4;i++)
            {
                if(reDirection(i)==this.direction)
                {
                    now=i;
                    break;
                }
            }

            if(command=='L')
            {
                now=((now+1)+length)%length;
                direction=reDirection(now);

            }
            else if(command=='R')
            {
                now=((now-1)+length)%length;
                direction=reDirection(now);
            }

        }

    }

}



public class 백준_2174번 {
    public static void main(String[] args) {
        Simulator s1=new Simulator();

        s1.run();
    }
}