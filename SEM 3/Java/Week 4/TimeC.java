import java.util.Scanner;

class Time1{

	int hours, minutes, seconds;

	Time1(){
		hours = minutes = seconds = 0;
	}

	Time1(int hours, int minutes, int seconds){
		this.hours = hours;
		this.minutes = minutes;
		this.seconds = seconds;
	}

	void displayTime(Time1 o){

		System.out.println(o.hours + ":" + o.minutes + ":" + o.seconds);
	}

	Time1 add(Time1 obj){

		Time1 result = new Time1();
		int totTime = (this.hours * 3600 + this.minutes * 60 + this.seconds) + (obj.hours * 3600 + obj.minutes * 60 + obj.seconds);
		
		result.seconds = totTime % 60;
		totTime = totTime/60;
		result.minutes = totTime  % 60;
		totTime = totTime/60;
		result.hours = totTime;

		return result;

	}

	Time1 sub(Time1 obj){

		Time1 result = new Time1();
		int totTime = (this.hours * 3600 + this.minutes * 60 + this.seconds) - (obj.hours * 3600 + obj.minutes * 60 + obj.seconds);

		if(totTime<0) totTime*=-1;

		result.seconds = totTime % 60;
		totTime = totTime/60;
		result.minutes = totTime  % 60;
		totTime = totTime/60;
		result.hours = totTime;

		return result;

	}

	boolean comp(Time1 obj){

		Time1 result = new Time1();
		int totTime1 = (this.hours * 3600 + this.minutes * 60 + this.seconds);
		int totTime2 = (obj.hours * 3600 + obj.minutes * 60 + obj.seconds);
		
		if(totTime1>totTime2){
			return true;
		}
		else{
			return false;
		}

	}

}

class TimeC{
	
	public static void main(String args[]){

		Time1 resAdd, resSub;

		Scanner sc = new Scanner(System.in);
		
		System.out.println("Enter hours, minutes, seconds for Time 1:");
		int h1 = sc.nextInt();
		int m1 = sc.nextInt();
		int s1 = sc.nextInt();

		System.out.println("Enter hours, minutes, seconds for Time 2:");
		int h2 = sc.nextInt();
		int m2 = sc.nextInt();
		int s2 = sc.nextInt();

		Time1 obj1 = new Time1(h1, m1, s1);
		Time1 obj2 = new Time1(h2, m2, s2);

		resAdd = obj1.add(obj2);
		resSub = obj1.sub(obj2);
        
        System.out.println("Addition: ");
		resAdd.displayTime(resAdd);

		System.out.println("Subtraction: ");
		resSub.displayTime(resSub);

		if(obj1.comp(obj2))
			System.out.println("Time 1 is larger");
		else
			System.out.println("Time 2 is larger");

	}
}