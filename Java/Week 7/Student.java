import java.io.*;
import java.util.*;

class SeatsFilledException extends Exception{
	public SeatsFilledException(){
		System.err.println("Seats are Full");
	}
}

public class Student{
	String name;
	int regno, compno;
	Scanner sc = new Scanner(System.in);
	

	public void input() throws SeatsFilledException{
		System.out.println("Enter the year of registration: ");
		int year = sc.nextInt();
		System.out.println("Enter Seat number: ");
		int num = sc.nextInt();
		regno = (year%100)*100 + num;
		compno = (year%100)*100 + 25;
		if(regno>compno){
			throw new SeatsFilledException();
		}
		else{
			System.out.println("Enter Name: ");
		    name = sc.next();
		}
	}

	public void display(){
		System.out.println("Details: ");
		System.out.println("Name: " + name);
		System.out.println("Registration number: "+regno);
	}

	public static void main(String args[]){
		Student obj = new Student();
		int flag = 1;
		try{
			obj.input();
		}catch(SeatsFilledException e){
			flag = 0;
			e.printStackTrace();
		}
		if(flag == 1)
		    obj.display();
	}
}