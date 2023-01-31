import java.util.Stack;

public class Programmers42584 {
    public int[] solution(int[] prices){
        int[] result=new int[prices.length];
        Stack<Node> stack=new Stack<>();

        /**
         * 스택에 값(주식 가격)과 인덱스를 함께 다루는 Node 형태로 넣어주며
         * prices 배열의 맨뒤(가장 마지막 주식가격)부터 연산을 시행한다.
         * 가격이 떨어지지 않았을 경우(peek>현재 value) 계속 pop 해주고
         * 떨어진 경우를 만났을 경우 해당 일자(해당 값의 인덱스)에서 현재 일자를
         * 빼서 주식이 떨어지지 않은 일 수를 구하여 result 배열에 저장하는 구조
         * 만약 주식이 마지막날까지 떨어지지 않았을 경우를 구하기 위해
         * stack.size()!=1 라는 while문의 정지 조건을 설정하였다.
         */

        stack.push(new Node(prices[prices.length-1], prices.length-1));
        for(int i=prices.length-1; i>=0; i--){
            while(stack.size()!=1 && stack.peek().value>=prices[i])
                stack.pop();

            result[i]=stack.peek().index-i;
            stack.push(new Node(prices[i], i));
        }

        return result;
    }

    /**
     * 값과 인덱스를 함께 다루는 클래스, Node
     */
    class Node{
        int value;
        int index;

        public Node(int value, int index) {
            this.value = value;
            this.index = index;
        }
    }
}
