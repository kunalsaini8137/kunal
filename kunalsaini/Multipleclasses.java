package kunalsaini;

class addition
{	
	int a,b,total;
	void add()
	{
		total=a+b;
	}
}
public class Multipleclasses 

{
	public static void main(String args[])
	{
	 addition obj=new addition();
	 obj.a=40;
	 obj.b=50;
     obj.add();
     System.out.println("addition:"+obj.total);
	}
	
}
