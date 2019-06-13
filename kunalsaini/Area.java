package kunalsaini;
import java.util.Scanner;
public class Area 
{
	public static void main(String args[])
	{
		int Square,rat,rect,a,l,b,base,h;
		System.out.println("enter the side of square");
		Scanner obj=new Scanner(System.in);
		a=obj.nextInt();
		Square=a*a;
		System.out.println("Area of square is:"+Square);
		System.out.println("enter the length and breadth of Rectangle");
		l=obj.nextInt();
		b=obj.nextInt();
		rect=l*b;
		System.out.println("Area of rectangle is:"+rect);
		System.out.print("enter the base and height of triangle");
		base=obj.nextInt();
		h=obj.nextInt();
		rat=(base*h)/2;
		System.out.println("Area of right angle triangle:"+rat);	
	}

}
