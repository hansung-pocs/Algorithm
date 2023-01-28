import java.util.Stack;

public class 프로그래머스_12909 {
    class Solution {
        boolean solution(String s) {
            boolean answer = true;
            Stack<Character> stack = new Stack<>();

            for (int i = 0; i < s.length(); i++) {
                if(s.charAt(i) == '('){
                    stack.push(s.charAt(i));
                }
                else{
                    if(!stack.empty())
                        stack.pop();
                    else {
                        return false;
                    }
                }
            }

            if(!stack.empty()) answer = false;


            return answer;
        }
    }
}
