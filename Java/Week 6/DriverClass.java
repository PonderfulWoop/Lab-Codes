import java.util.Scanner;

class Person{
	private String name;
	private int birthdate_day, birthdate_month, birthdate_year;

	Person(String name, int day, int month, int year){
		this.name = name;
		birthdate_day = day;
		birthdate_month = month;
		birthdate_year = year;
	}

	public String getName(){
		return name;
	}

	public int getDay(){
		return birthdate_day;
	}

	public int getMonth(){
		return birthdate_month;
	}

	public int getBYear(){
		return birthdate_year;
	}
}

class CollegeGrad extends Person{

	private int gpa;
	private int year;

	CollegeGrad(int gpa, int year, String n, int d, int m, int y){
		super(n, d, m, y);
		this.gpa = gpa;
		this.year = year;
	}

	public int getGPA(){
		return gpa;
	}

	public int getYear(){
		return year;
	}

}

public class DriverClass{
	public static void main(String args[]){
		Scanner sc = new Scanner(System.in);
		System.out.println("Enter Name, GPA, Year of graduation, birthdate of the student: ");
		String name = sc.next();
		int gpa = sc.nextInt();
		int y = sc.nextInt();
		int bd = sc.nextInt();
		int bm = sc.nextInt();
		int by = sc.nextInt();

		CollegeGrad grad1 = new CollegeGrad(gpa, y, name, bd, bm, by);

		System.out.println("Details: ");
		System.out.println("Name : "+grad1.getName());
		System.out.println("Year of graduation : "+grad1.getYear());
		System.out.println("GPA : "+grad1.getGPA());
		System.out.println("Birthdate : "+grad1.getDay()+"-"+grad1.getMonth()+"-"+grad1.getBYear());


	}
}