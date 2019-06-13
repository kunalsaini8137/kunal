package kunalsaini;
import java.util.Scanner;

public class Largest 
{
public static void main(String args[])
{
	int a,b,c;
	System.out.println("enter three no. of your choice");
	Scanner obj=new Scanner(System.in);
	a=obj.nextInt();
	b=obj.nextInt();
	c=obj.nextInt();
	if(a>b&&a>c)
	{
		System.out.println("largest no. is"+a);
	}
	else if(b>a&&b>c) 
	{
		System.out.println("largest no. is"+b);
	}
	else if(c>a&&c>b)
	{
		System.out.println("largest no. is"+c);
	}
	else
	{
		System.out.println("no.s are not distinct");
	}
	
		}
}