import java.util.*;

interface Stack{
	void push(int i);
	void pop();
	void display();
}

class FixedStack implements Stack{
	final int size = 10;
	int arr[] = new int[size];
	static int top = -1;

	public void push(int elem){

		if(top == size - 1){
			System.out.println("Stack is full");
			return;
		}
		else{
			top++;
			arr[top] = elem;
		}
	}

	public void pop(){

		if(top == -1){
			System.out.println("Underflow");
		}
		else{
			arr[top] = 0;
			top--;
		}
	}

	public void display(){
		System.out.println("Stack is: ");
		for(int i = 0; i<=top; i++){
			System.out.print(arr[i]+"\t");
		}
		System.out.println();
	}
}

class DynamicStack implements Stack{
	static int arr[];
	static int top = -1;
	int newSize = 0;

	DynamicStack(int size){
		arr = new int[size];
	}
    public void incSize(int newSize){
    	if(newSize<arr.length){
    		System.out.println("The size cannot be smaller");
    	}
    	else{
    		this.newSize = newSize;
    		int l = arr.length;
    		int newArr[]= new int[this.newSize];
    	    for(int i = 0; i<arr.length; i++)
    	    	newArr[i] = arr[i];
    	    arr = null;
    	    arr = new int[newArr.length];
    	    for(int i = 0; i<l; i++)
    	    	arr[i] = newArr[i];
    	}
    }
	public void push(int elem){

		if(top == arr.length - 1){
			System.out.println("Stack is full");
			return;
		}
		else{
			top++;
			arr[top] = elem;
		}
	}

	public void pop(){

		if(top == -1){
			System.out.println("Underflow");
		}
		else{
			arr[top] = 0;
			top--;
		}
	}

	public void display(){
		System.out.println("Stack is: ");
		for(int i = 0; i<arr.length; i++){
			System.out.print(arr[i]+"\t");
		}
		System.out.println();
	}
}

class StackMain{
	public static void main(String args[]){
		
		FixedStack fs = new FixedStack();
		Scanner sc = new Scanner(System.in);
		
		int ch = 0;


		System.out.println("Enter choice: ");
		System.out.println("1. FixedStack");
		System.out.println("2. DynamicStack");
		ch = sc.nextInt();

		switch(ch){
			case 1:
			int ch2 = 0;
			while(ch2 != 4){
				System.out.println("Choose: ");
				System.out.println("1. Push");
				System.out.println("2. Pop");
				System.out.println("3. Display");
				System.out.println("4. Exit");
				ch2 = sc.nextInt();
				switch(ch2){
					case 1:
					int in;
					System.out.println("Enter number ");
					in = sc.nextInt();
					fs.push(in);
					break;

					case 2:
					fs.pop();
					break;

					case 3:
					fs.display();
					break;
				}
			}
			break;

			case 2:
			int ch3 = 0;
			System.out.println("Enter size: ");
			int s = sc.nextInt();
			DynamicStack ds = new DynamicStack(s);
			while(ch3 != 5){
				System.out.println("Choose: ");
				System.out.println("1. Push");
				System.out.println("2. Pop");
				System.out.println("3. Display");
				System.out.println("4. Increase Stack Size");
				System.out.println("5. Exit");
				ch3 = sc.nextInt();

				switch(ch3){
					case 1:
					int in;
					System.out.println("Enter number ");
					in = sc.nextInt();
					ds.push(in);
					break;

					case 2:
					ds.pop();
					break;

					case 3:
					ds.display();
					break;

					case 4:
					System.out.println("Enter new Size");
					int ns = sc.nextInt();
					ds.incSize(ns);
					break;
				}
			}
		}
		

	}

}