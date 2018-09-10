import java.util.*;
import java.text.*;

class Student1{

	int regno; String name; GregorianCalendar date; int sem; float gpa, cgpa;
	static int count = 0;

	Student1()
	{
		regno=0;
		name="";
		sem=0;
		cgpa=0.0f;
		gpa=0.0f;
		date=new GregorianCalendar(0,0,0);
	}

	Student1(String name, GregorianCalendar date, int sem, float gpa, float cgpa){
		this.name = name;
		int year = date.get(Calendar.YEAR);
		this.sem = sem;
		this.gpa = gpa;
		this.cgpa = cgpa;
		String y = Integer.toString(year);
		count++;
		String r = y.substring(2,4) + Integer.toString(count);
		regno = Integer.parseInt(r);
	}

	public void Display(){

		System.out.println("Reg no is "+regno);
		System.out.println("Name is "+name);
		System.out.println("Sem is "+sem);
		System.out.println("CGPA is "+cgpa);
		System.out.println("GPA is "+gpa);
		System.out.println("------------------------------");

	}

	public void Sort_sem(Student1 s[], int no){

		for(int i = 0; i<no-1; i++){
			for(int j = i + 1; j < no; j++){
				if(s[i].sem < s[j].sem){
					Student1 st = s[i];
					s[i] = s[j];
					s[j] = st;
				}
				else if(s[i].sem == s[j].sem){
					if(s[i].cgpa < s[j].cgpa){

						Student1 st = s[i];
					    s[i] = s[j];
					    s[j] = st;

					}
				}
			}
		}

		for(int i = 0; i < no; i++){
			s[i].Display();
		}
	}

	public void Sort_Name(Student1 s[], int no){

		for(int i = 0; i<no-1; i++){
			for(int j = i + 1; j < no; j++){
				if(s[i].name.compareTo(s[j].name)>0){
					Student1 st = s[i];
					s[i] = s[j];
					s[j] = st;
				}
			}
		}

		for(int i = 0; i < no; i++){
			s[i].Display();
		}
	}

	public void disp_part_char(Student1 s[], int no, char ch){
		int flag = 0;
		for(int i = 0; i<no; i++){
			if(s[i].name.charAt(0) == ch){
				s[i].Display();
				flag = 1;
			}
		}
		if(flag == 0){
			System.out.println("No such Student exists in the database");
		}
	}

	public void disp_subs_name(Student1 s[], int no, String sub){

		for(int i = 0; i < no; i++){
			int temp = 0;
			for(int k = 0; k < s[i].name.length(); k++){
				while(temp < sub.length() && s[i].name.charAt(k) == sub.charAt(temp)){
					temp++;
				}
			}
			if(temp == sub.length()){
				s[i].Display();
			}
		}

	}
}

public class Student{
	public static void main(String args[]){

		Scanner sc = new Scanner(System.in);
		System.out.println("Enter number of Students:");
		int no = sc.nextInt();

		Student1 st = new Student1();
		Student1 s[] = new Student1[no];
		for(int i = 0; i < no; i++){

			System.out.println("Enter details of Student " + (i+1));
			System.out.println("Enter Name :");
			String name = sc.next();
			System.out.println("Enter Year :");
			int year = sc.nextInt();
			System.out.println("Enter Semester :");
			int sem = sc.nextInt();
			System.out.println("Enter GPA :");
			float gpa = sc.nextFloat();
			System.out.println("Enter CGPA :");
			float cgpa = sc.nextFloat();

			s[i] = new Student1(name, new GregorianCalendar(year, 8, 18), sem, gpa, cgpa);

		}

		System.out.println("Data Saved");

		int ch = 0;
		while(ch != 5){
			System.out.println("Enter Choice:");
			System.out.println("1. Sort by Semester and CGPA");
			System.out.println("2. Sort by Name");
			System.out.println("3. Display names which start with a particular Character");
			System.out.println("4. Display names which contain a particular substring");
			System.out.println("5. Exit");
			ch = sc.nextInt();
			if(ch == 1){

				st.Sort_sem(s, no);

			}
			else if(ch == 2){

				st.Sort_Name(s, no);
			}
			else if(ch == 3){

				System.out.println("Enter Character to Check: ");
				char c = sc.next().charAt(0);
				st.disp_part_char(s, no, c);
			}
			else if(ch == 4){
				System.out.println("Enter substring to Check: ");
				String c = sc.next();
				st.disp_subs_name(s, no, c);
			}
		}

	}
}