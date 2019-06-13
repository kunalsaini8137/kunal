package kunalsaini;
import java.util.Scanner;
public class Oddeven 
{
	public static void main(String args[])
	{
		int n;
		System.out.println("enter a number");
		Scanner input=new Scanner(System.in);
		n=input.nextInt();
		
		if(n%2==0)
				System.out.println("number is even"+n);
			else
				System.out.println("number is odd"+n);
			
		
	}

}
