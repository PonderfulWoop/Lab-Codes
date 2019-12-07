import java.util.*;

interface Series{

	int getNext();
	void reset();
	void setValue(int s);

}
class ByTwos1 implements Series{

	static int val = 0;

	public int getNext(){
		val += 2;
		return val;
	}

	public void reset(){
		val = 0;
	}

	public void setValue(int i){
		val = i;
	}
}

class ByTwos{
	public static void main(String args[]){
		ByTwos1 obj = new ByTwos1();

		for(int i = 0; i<6; i++){
			System.out.print(obj.getNext()+"\t");
		}
		System.out.println();

		obj.reset();

		System.out.println("Enter a default value: ");
		Scanner sc = new Scanner(System.in);
		int s = sc.nextInt();

		obj.setValue(s);

		System.out.println("Series with default value as "+s);

		for(int i = 0; i<6; i++){
			System.out.print(obj.getNext()+"\t");
		}
		System.out.println();
	}
}


