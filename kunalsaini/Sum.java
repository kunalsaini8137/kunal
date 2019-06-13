package kunalsaini;
import java.util.Scanner;
public class Sum 
{
	public static void main(String args[])
	{
    int a,b,sum;
    System.out.println("enter two numbers");
	Scanner input=new Scanner(System.in);
	a=input.nextInt();
	b=input.nextInt();
	sum=a+b;
	System.out.println("sum of two numbers"+sum);
	}
}
