#include <iostream>
using namespace std;
 
int disArr[4][2]={{-1,0},{0,1},{1,0},{0,-1}}; //북동남서
int cel=0; //칸 갯수
int N,M,r,c,d;
int room[50][50]; //M의 최대가 50


//청소할 칸 갯수를 검사하고 출력하는 함수 
void solve()
{
    int next,nextR,nextC; //다음 위치와 관련된 변수
    while(true)
    {
        if(room[r][c]==0)    //1.현재 위치를 청소한다.
        {    
            room[r][c]=2;
            cel++;
        }
        for(int i=0;i<4;i++) //2.현재 위치에서 현재 방향을 기준으로 왼쪽방향부터 차례대로 탐색을 진행한다
        {
            d=(d+3)%4; //d+3은 왼쪽
            nextR=r+disArr[d][0]; 
            nextC=c+disArr[d][1];
            next= room[nextR][nextC];
            if(next==0)     //2-1.청소하지 않은 공간이 있다면 회전하고 1칸 전진.
            {
                r=nextR;
                c=nextC;
                break;
            }
                            //2-2.없다면 회전하고 반복
        }
        if(next==0)         //2-1 후에 청소하기 위해
            continue;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                          
        //네 방향 모두 청소가 되어있음
        int behind=(d+2)%4; //후진하되, 방향은 고정이니
        nextR=r+disArr[behind][0];
        nextC=c+disArr[behind][1];
        int next= room[nextR][nextC];
        if(next!=1)         //3.뒤에 벽이 없음-방향 유지, 1칸 후진
        {
            r=nextR;
            c=nextC;
        }else{              //4.뒤에 벽이 있음-종료 및 종료
            cout<<cel;
            return;
        }
    }
}

int main(){
    cin>>N>>M;
    cin>>r>>c>>d;
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<M;j++)
        {
            cin>>room[i][j];
        }
    }
    solve();
    return 0;
}