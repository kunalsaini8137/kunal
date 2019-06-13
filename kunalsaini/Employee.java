package kunalsaini;
import java.util.Scanner;
class EmployeeDetails{
	String name;
	int id;
	EmployeeDetails(){
		name="Nipun";
		id=40;
	}
	EmployeeDetails(String nm,int idd){
		name=nm;
		id=idd;
	}
	void display() {
		System.out.println(name+"\n"+id);
	}
}
public class Employee {
	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		EmployeeDetails ob = new EmployeeDetails();
		String nm;
		int idd;
		nm=sc.nextLine();
		idd=sc.nextInt();
		EmployeeDetails ob1=new EmployeeDetails(nm,idd);
		ob.display();
		ob1.display();
	}
}
