package kunalsaini;
import java.util.Scanner;
public class grade 
{
	public static void main(String args[])
	{
		int m,passingmarks=40;
		char grade;
		Scanner input = new Scanner(System.in);
		System.out.println("enter the marks obtained");
		m=input.nextInt();
		if(m>=passingmarks)
		{
		if(m>=90)
		grade='A';
		else if(m>=75)
		grade='B';
		else if(m>=60)
		grade='C';
		else
		grade='D';	
		System.out.println("passed and your grade is"+grade);
		}
		else
			grade='F';
		System.out.println("failed and ur grade is"+grade);
		
	}

}
