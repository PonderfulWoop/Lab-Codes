import java.util.*;

class Stack<T>{
	T arr[];
	int top;
	Stack(T num[]){
		this.arr = num;
		top = -1;
	}

	void push(T elem){
		if(top==arr.length-1)
		{
			System.out.println("Error: Stack full");
		}
		else
		{
		arr[++top]=elem;
		}
	}

	String pop(){
		if(top == -1){
			return "Error: Empty Stack";
		}
		else{
			return arr[top--].toString();
		}
	}

	void display(){
		String s = arr.getClass().getName().toString();
		System.out.println(s.substring(2, s.length()-1)+" Stack: ");
		for(int i = 0; i<=top; i++){
			System.out.print(arr[i].toString()+"\t");
		}
		System.out.println();
	}
}

class Employee
{
	
	String name;
	int id;
	Employee(String n, int i)
	{
		
		name=n;
		id=i;
		
	}

	public String toString(){
		return name;
	}
}
class Student
{
	String name;
	int regno;
	Student(String n, int r)
	{
		name=n;
		regno=r;
	}

	public String toString(){
		return name;
	}
}



class GenStack{
	public static void main(String args[]){
		Scanner sc = new Scanner(System.in);
		System.out.println("Enter number of Employees");
		int e = sc.nextInt();
		System.out.println("Enter number of Students");
		int stu = sc.nextInt();


		Employee E[] = new Employee[e];
		Student S[] = new Student[stu];

		Stack<Employee> emp = new Stack<Employee>(E);
		Stack<Student> stud = new Stack<Student>(S);

		System.out.println("Enter details for Employees");
		for(int i = 0; i<e; i++){
			String name = sc.next();
			int id = sc.nextInt();
			E[i] = new Employee(name, id);
			emp.push(E[i]);
		}

		System.out.println("Enter details for Students");
		for(int i = 0; i<stu; i++){
			String name = sc.next();
			int id = sc.nextInt();
			S[i] = new Student(name, id);
			stud.push(S[i]);
		}
		System.out.println("Stack: ");
		emp.display();
		stud.display();

		System.out.println("Stack after removal: ");
		emp.pop();
		stud.pop();
		emp.display();
		stud.display();
	}
}