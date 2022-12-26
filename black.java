//pocs 신승혜
package main; 

import java.util.*; 

public class black {
   public static void main(String[] args) { 
      Scanner scanner=new Scanner(System.in); 
      
      int n=scanner.nextInt(); //카드의 개수 입력받기. 
      int m=scanner.nextInt(); //기준값 입력받기. 
      int arr[]=new int[n]; //배열 선언 후 크기 지정.  
      int result=0;  
      
      for(int i=0;i<arr.length;i++) { //값 n개를 받기.
         arr[i]=scanner.nextInt(); //배열에 하나씩 저장.
      }
      
      //이제 3중 for문을 돌려서 세 합이 m이하이되, m과 가장 가까운 수를 출력할 것임. 
      //예시 생각해보면 쉬움. 
      
      for(int i=0;i<n-2;i++) { 
         for(int j=i+1;j<n-1;j++){ //i의 다음 순서부터. 
            for(int p=j+1;p<n;p++) {
               int test=arr[i]+arr[j]+arr[p]; 
               
               if(result<test&&test<=m) { //m이하인데, 
                  result=test; 
               }
            }
         }
      }
      System.out.println(result); 
   }
}