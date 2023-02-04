import java.util.ArrayDeque;

public class 프로그래머스_118670 {
    class Solution {
        public int[][] solution(int[][] rc, String[] operations) {
            int[][] answer = new int[rc.length][rc[0].length];
            ArrayDeque<Integer> left = new ArrayDeque<>();
            ArrayDeque<ArrayDeque<Integer>> mid = new ArrayDeque<>();
            ArrayDeque<Integer> right = new ArrayDeque<>();

            for (int i = 0; i < rc.length; i++) {
                left.addLast(rc[i][0]);
                ArrayDeque<Integer> midQue = new ArrayDeque<>();
                for (int j = 1; j < rc[i].length-1; j++) {
                    midQue.addLast(rc[i][j]);
                }
                mid.addLast(midQue);
                right.addLast(rc[i][rc[i].length-1]);
            }

            for (int i = 0; i < operations.length; i++) {
                if(operations[i].equals("Rotate")){
                    mid.peekFirst().addFirst(left.pollFirst());
                    right.addFirst(mid.peekFirst().pollLast());
                    mid.peekLast().addLast(right.pollLast());
                    left.addLast(mid.peekLast().pollFirst());
                }
                else {
                    left.addFirst(left.pollLast());
                    mid.addFirst(mid.pollLast());
                    right.addFirst((right.pollLast()));
                }
            }

            for (int i = 0; i < rc.length; i++) {
                answer[i][0] = left.pollFirst();
                for (int j = 1; j < rc[i].length-1; j++) {
                    answer[i][j] = mid.peekFirst().pollFirst();
                }
                mid.pollFirst();
                answer[i][rc[i].length-1] = right.pollFirst();
            }

            return answer;
        }
    }
}
