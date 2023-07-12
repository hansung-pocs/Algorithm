import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.Deque;

//12904번
//S에 A와B를 추가하면서 T에 맞출생각하지말고 T에서 마지막글자를 통해 T를 S에 맞출생각을 한다

public class Main {
public static void main(String[] args) throws IOException {
BufferedReader br = new BufferedReader(new InputStreamReader(System.in)); //선언
String S = br.readLine();
String T = br.readLine();

        Deque<Character> deque = new ArrayDeque<>();
        for (Character ch : T.toCharArray()) {
            deque.addLast(ch);
        }

        //front true면 정방향(마지막 글자확인), false면 반대방향(첫번째 글자확인)
        boolean front = true;
        //덱 사이즈가 S랑 같아질때까지 T의 마지막글자 확인
        while(deque.size()>S.length()){
            if(front){  //정방향
                if(deque.peekLast() == 'A'){
                    deque.removeLast();
                }
                else{
                    deque.removeLast();
                    front = false;
                }
            }
            else{  //반대방향
                if(deque.peekFirst() == 'A'){
                    deque.removeFirst();
                }
                else{
                    deque.removeFirst();
                    front = true;
                }
            }
        }

        //StringBuffer사용해서 덱에서 흩어져있는 문자들 합쳐서 문자열 맞추기
        StringBuffer sb = new StringBuffer();

        if (front) {  //정방향이면 앞부터 순서대로
            while (!deque.isEmpty()) {
                sb.append(deque.removeFirst());
            }
        }
        else {  //반대방향이면 뒤부터 순서대로
            while (!deque.isEmpty()) {
                sb.append(deque.removeLast());
            }
        }

        //해석된 T와 S 비교
        if (sb.toString().equals(S)) System.out.println("1");
        else System.out.println("0");
    }
}