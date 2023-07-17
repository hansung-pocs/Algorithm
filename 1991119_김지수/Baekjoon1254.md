import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

//1254번
//문자 계수 추가할때마다 봐야하는 문자 하나씩 줄이기(i++)
//5글자면 처음에 5글자 처음부터 끝의 수 차근차근 비교, 다음은 4글자 맨앞과 맨뒤부터 차근차근

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String str = br.readLine();
        int len = str.length();
        int cnt = len;  //가장 짧은 팰린드롬의 길이
        boolean bo = false;
        int i = 0;  //맨앞표시
        while(!bo){
            bo = true;
            for (int j = i; j < len; j++) {
                if(str.charAt(j) != str.charAt(len-j+i-1)) bo =false; //남은글자수 앞과 마지막부터 차근차근 비교
            }
            if(!bo) i++;
        }
        cnt += i;
        System.out.println(cnt);
    }
}