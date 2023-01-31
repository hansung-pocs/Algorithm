import java.util.Arrays;
import java.util.Stack;

public class 프로그래머스_42584 {
    public int[] solution(int[] prices) {
        int[] answer = new int[prices.length];

        Stack<Integer> stack = new Stack<>();
        int days = 1;
        int pop;

        for (int i = 0; i < prices.length; i++) {
            while (!stack.empty() && prices[stack.peek()] > prices[i]) {
                pop = stack.pop();
                answer[pop] = i - pop;
            }
            stack.push(i);
        }

        for (int i = prices.length - 2; i >= 0; i--) {
            if (answer[i] == 0) {
                answer[i] = days;
            }
            days++;
        }

        System.out.println(Arrays.toString(answer));

        return answer;
    }
}
