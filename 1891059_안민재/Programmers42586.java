import java.util.*;

//  프로그래머스 42586 - 기능 개발

public class Solution {
    // 일자별 배포되는 기능의 개수 계산
    public static int[] solution(int[] progresses, int[] speeds){
        Queue<Integer> queue = new ArrayDeque<>();
        List<Integer> list = new ArrayList<>();

        // 큐에 작업별 필요한 일수 계산하여 offer
        for(int i=0; i<progresses.length; i++)
            queue.offer(getRelease(progresses[i], speeds[i]));

        // 첫 작업의 일수부터 비교 시작
        Integer maxPre=queue.poll();
        int count=1;

        while(!queue.isEmpty()){
            /*
                앞선 기능의 필요 일수가 현재 일수보다 크거나
                같을 경우 함께 배포된다.
             */
            if(maxPre>=queue.peek()){
                queue.poll();
                count++; // 함께 배포되는 기능 수
            }
            else{ // 이외의 경우
                // 함께 배포되는 기능 수 list에 add
                list.add(count);
                // 비교 기준 maxPre 갱신
                maxPre=queue.poll();
                count=1;
            }
        }
        // 마지막 요소까지 검사한 count, list 에 add
        list.add(count);

        // int 배열로 변환하여 반환
        return list.stream().mapToInt(i->i).toArray();
    }

    /*
        progress complete 에 필요한 일수 계산 메서드
        100-progress 보다 speed*days 가 크거나 같아야 한다.
     */
    public static int getRelease(int progress, int speed){
        int day=0;
        while(true){
            progress+=speed;
            day++;
            if(progress>=100) break;
        }

        return day;
    }
}
