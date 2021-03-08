import java.math.BigDecimal;
import java.util.Scanner;
public class Main {
	public static void main(String[] args) {
		Scanner scn = new Scanner(System.in);
		BigDecimal a = scn.nextBigDecimal();
		BigDecimal result = new BigDecimal(1);
		int b = scn.nextInt();
		for(int i=0; i<b; i++)
		{
			result = result.multiply(a);
		}
		System.out.println(result.toPlainString());
		scn.close();
	}
}
