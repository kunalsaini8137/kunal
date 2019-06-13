package kunalsaini;

import java.util.Scanner;

public class MultipleFunction
{
	static boolean check(int n,int i) {
		if(n%i==0) {
			return true;
		}
		else
			return false;
	}
	public static void main(String args[]) {
		Scanner sc =new Scanner(System.in);
		System.out.println("Enter a number");
		int n=sc.nextInt();
		for(int i=1;i<n;i++) {
			if(check(n,i)) {
				System.out.println(i);
			}
		}
		sc.close();
	}

}
