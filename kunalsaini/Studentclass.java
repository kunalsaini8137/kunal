package kunalsaini;
import java.util.Scanner;
class Student
{
	int rn,m1,m2,m3;
	String name;
	Student()
	{
		name="kunal";
		m1=m2=m3=rn=0;
	}
	Student(String n,int m11,int m22,int m33,int rnn)
	{
		name=n;
		m1=m11;
		m2=m22;
		m3=m33;
		rn=rnn;	
	}
	void display()
	{
		System.out.println("name is:"+name+"\nroll no. is:"+rn);
	}
	void average()
	{	
		float avg=(float)((m1+m2+m3)/3);

	System.out.println("average is:"+avg);
}
}
public class Studentclass 
{
	public static void main(String args[])
	{
		Scanner ob=new Scanner(System.in);
		System.out.println("enter the details");
		String n=ob.nextLine();
		int rnn=ob.nextInt();
		int m11=ob.nextInt();
		int m22=ob.nextInt();
		int m33=ob.nextInt();
		Student ob1=new Student(n,m11,m22,m33,rnn);
		ob1.display();
		ob1.average();
		Student ob2=new Student();
		ob2.display();
		ob2.average();
		}
}
