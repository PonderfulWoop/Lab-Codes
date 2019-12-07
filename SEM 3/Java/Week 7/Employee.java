import java.util.*;
import java.io.*;

class Employee{
	String name;
	int age;
	double salary;
	float takeHomeSalary;
	char grade;

	InputStreamReader r = new InputStreamReader(System.in);
	BufferedReader br = new BufferedReader(r);

	public void input() throws IOException{
		System.out.println("Enter Name");
		name = new String(br.readLine());
		System.out.println("Enter Age");
		age = Integer.parseInt(br.readLine());
		System.out.println("Enter Salary");
		salary = Float.parseFloat(br.readLine());
		takeHomeSalary = (float)salary*0.75f;
		System.out.println("Enter grade");
		grade = br.readLine().charAt(0);
	}

	public void display(){
		System.out.println("Name: "+name);
		System.out.println("Age: "+age);
		System.out.println("Salary: "+salary);
		System.out.println("Take Home Salary: "+takeHomeSalary);
		System.out.println("Grade: "+grade);

	}

	public static void main(String args[]){
		Scanner sc = new Scanner(System.in);
		int ch = 0;
        Employee e = new Employee();
		while(ch != 3){

			System.out.println("Enter Choice: ");
      		System.out.println("1. Input");
	    	System.out.println("2. Display");
		    System.out.println("3. Exit");
		    ch = sc.nextInt();

		    switch(ch){
		    	case 1:
		    	try{
		    		e.input();
		    	}catch(IOException exception){
		    		System.out.println("There is an IO Exception!!!!");
		    	}
		    	break;

		    	case 2:
		    	e.display();
		    	break;
		    }
		}
	}
}