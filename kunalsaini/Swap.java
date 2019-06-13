package kunalsaini;
import java.util.Scanner;
public class Swap 
{
	public static void main(String args[])
	{
		int temp,a,b;
		System.out.println("Enter two numbers to swap");
		Scanner obj=new Scanner(System.in);
	    a=obj.nextInt();
	    b=obj.nextInt();
	    temp=a;
	    a=b;
	    b=temp;
		System.out.println("numbers after swapping are \n"+a+"\n"+b);
		
	}
	

}
