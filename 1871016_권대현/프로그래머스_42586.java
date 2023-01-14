import java.io.IOException;
import java.util.ArrayList;

public class 프로그래머스_42586 {
    public static void main(String[] args) throws IOException {
        int[] arr  = new int[]{55,60,65};
        int[] arr2  = new int[]{5, 10, 7};
        Solution solution = new Solution();
        ArrayList<Integer> ans = solution.solution(arr, arr2);
        System.out.println(ans.toString());
    }
    static class Solution {
        public ArrayList<Integer> solution(int[] progresses, int[] speeds) {
            ArrayList<Integer> answer = new ArrayList<Integer>();
            int pre = 101;
            int count = 0;
            for (int i = 0; i < progresses.length; i++) {
                int suf = (int) Math.ceil((100 - progresses[i]) / (double)speeds[i]);
                if(pre == 101) pre = suf;
                if(pre>=suf){
                    count++;
                }
                else {
                    answer.add(count);
                    count = 1;
                    pre = suf;
                }
            }
            if(count != 0){
                answer.add(count);
            }
            return answer;
        }
    }
}
