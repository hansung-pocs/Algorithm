import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Stack;

public class Backjoon9935 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String src=br.readLine();
        String boomStr=br.readLine();

        int length=src.length();
        int boomStrLength=boomStr.length();

        Stack<Character> stack=new Stack<>();
        Character end=boomStr.charAt(boomStrLength-1);

        for(int i=0; i<length; i++){
           stack.push(src.charAt(i));

           boolean isBoomStr=true;

           if(stack.size()>=boomStrLength &&
                   stack.peek().equals(end)){
               int index=stack.size()-1;

               for(int j=boomStrLength-1; j>=0; j--){
                   if(stack.get(index).equals(boomStr.charAt(j)))
                       index--;
                   else{
                       isBoomStr=false;
                       break;
                   }
               }

               if(isBoomStr){
                   for(int j=0; j<boomStrLength; j++)
                       stack.pop();
               }

           }
        }

        StringBuffer sb=new StringBuffer();

        while(!stack.isEmpty())
            sb.append(stack.pop());

       sb=sb.reverse();
        System.out.println(sb.toString().equals("")?"FRULA":sb);

       br.close();
    }
}
