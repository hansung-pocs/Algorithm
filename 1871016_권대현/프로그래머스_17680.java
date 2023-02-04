import java.io.IOException;
import java.util.Collections;
import java.util.HashMap;

public class 프로그래머스_17680 {
    public static void main(String[] args) throws IOException {
        String[] arr  = new String[]{"Jeju", "Pangyo", "NewYork", "newyork"};
        Solution solution = new Solution();
        int ans = solution.solution(2, arr);
        System.out.println(ans);
    }

    static class Solution {
        public int solution(int cacheSize, String[] cities) {
            int answer = 0;
            int lru = 0;
            HashMap<String, Integer> cache = new HashMap<>(cacheSize);

            for(String city : cities){
                city = city.toLowerCase();
                if(cache.containsKey(city)){
                    cache.put(city, lru);
                    lru++;
                    answer += 1;
                }
                else{
                    if(cache.size() < cacheSize){
                        cache.put(city, lru);
                    }
                    else if(cache.size() == cacheSize && cacheSize > 0){
                        Integer minValue = Collections.min(cache.values());
                        cache.values().remove(minValue);
                        cache.put(city, lru);
                    }
                    lru++;
                    answer += 5;
                }
            }

            return answer;
        }
    }
}
