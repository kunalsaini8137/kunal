package kunalsaini;
import java.util.Scanner;
class FirstClass{
	boolean check(int n,int i) {
		if(n%i==0) {
			return true;
		}
		else
			return false;
	}
}
public class MultipleClasses1 {
	public static void main(String[] args) {
		Scanner sc = new Scanner (System.in);
		System.out.println("Enter a number");
		int n=sc.nextInt();
		FirstClass ob =new FirstClass();
		for(int i=1;i<n;i++) {
			if(ob.check(n, i)) {
				System.out.println(i);
			}
		}
		sc.close();
	}

}
