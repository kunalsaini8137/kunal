package kunalsaini;
import java.util.Scanner;
public class Stringmethods 
{
	public static void main(String args[])
	{
		int m;
		String n,r,p,t,s;
		System.out.println("enter a string");
		Scanner input=new Scanner(System.in);
		n=input.nextLine();
		m=n.length();
		System.out.println("Length of string is:" +m);
		System.out.println("enter a string to replace");
		Scanner replace= new Scanner(System.in);
	    r=replace.nextLine();
	    p=r.replace(n,r);
	    System.out.println("new word is:" +p);
	    System.out.println("enter a string to concatenate with saini");
	    Scanner cat=new Scanner(System.in);
	    t=cat.nextLine();
	    s=t.concat(" saini");
	    System.out.println("new string after concatenation with saini is:" +s);
	    }
    }

