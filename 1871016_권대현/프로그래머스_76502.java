import java.util.Stack;

public class 프로그래머스_76502 {
    static class Solution {
        public static boolean check(String s){
            Stack<Character> stack = new Stack<>();

            for (int i = 0; i < s.length(); i++) {
                char ch = s.charAt(i);
                switch (ch) {
                    case '(', '{', '[' -> stack.push(ch);
                    case ')' -> {
                        if (stack.empty()) return false;
                        if (stack.peek() == '(')
                            stack.pop();
                    }
                    case '}' -> {
                        if (stack.empty()) return false;
                        if (stack.peek() == '{')
                            stack.pop();
                    }
                    case ']' -> {
                        if (stack.empty()) return false;
                        if (stack.peek() == '[')
                            stack.pop();
                    }
                }
            }
            return stack.empty();
        }
        public int solution(String s) {
            int answer = 0;
            String s1 = s;

            for (int j = 0; j < s1.length(); j++) {
                if(check(s1)) answer++;

                String st = s1.substring(0,1);
                s1 = s1.substring(1);
                s1 += st;
            }

            System.out.println(answer);
            return answer;
        }
    }
}
