import java.util.Scanner;

class Counter1{
	static int statcount = 0;
	int count = 0;

	static void showCount(){
		System.out.println("Static Count Value: " + statcount);
	}
}

class Counter{
	public static void main(String args[]){
		 Scanner sc = new Scanner(System.in);

		 System.out.println("Enter number of Objects you want to create: ");
		 int num = sc.nextInt();

		 Counter1 objArray[] = new Counter1[num];
		 
		 for(int i = 0; i < num; i++){
		 	objArray[i] = new Counter1();
		 	Counter1.statcount++;
		 	objArray[i].count++;
		 	try{
		 		Thread.sleep(1000);
		 	}
		 	catch(InterruptedException e){

		 	}
		 	
		 	Counter1.showCount();
		 	System.out.println("Normal Count Value: " + objArray[i].count);
	    }
    }
}