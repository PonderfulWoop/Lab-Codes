import java.util.Scanner;

class Mixer1{

	int arr[];
	Scanner sc = new Scanner(System.in);

	void accept(int n){
		arr = new int[n];

        System.out.println("Enter "+n+" Elements: ");

		for(int i = 0; i<n; i++){
			arr[i] = sc.nextInt();
		}
	}

	Mixer1 mix(Mixer1 obj){
		Mixer1 resultant = new Mixer1();
		int totlength = this.arr.length + obj.arr.length;
		resultant.arr = new int[totlength];

		int j = 0;

		for(int i = 0; i<totlength; i++){
			if(i<this.arr.length){
				resultant.arr[i] = this.arr[i];
			}
			else{
				resultant.arr[i] = obj.arr[j];
				j++;
			}
		}

		return resultant;
	}

	void SortnDisp(Mixer1 o){
		int temp;
		for(int i = 0; i<o.arr.length-1; i++){
			for(int k = i+1; k<o.arr.length; k++){
				if(o.arr[i]>o.arr[k]){
					temp = o.arr[i];
					o.arr[i] = o.arr[k];
					o.arr[k] = temp;
				}
			}
		}

		System.out.println("Elements : ");
		for(int i = 0; i<o.arr.length; i++){
			System.out.print(o.arr[i]+"\t");
		}
		System.out.println();
	}
}

class Mixer{
	public static void main(String args[]){
		
		Mixer1 obj1 = new Mixer1();
		Mixer1 obj2 = new Mixer1();
		Mixer1 res;

		Scanner sc = new Scanner(System.in);
		
		System.out.println("Enter number of Elements for Array 1:");
		int n1 = sc.nextInt();
		
		System.out.println("Enter number of Elements for Array 1:");
		int n2 = sc.nextInt();

		System.out.println("Enter Elements for Array 1:");
		obj1.accept(n1);

		System.out.println("Enter Elements for Array 1:");
		obj2.accept(n2);

		res = obj1.mix(obj2);

		res.SortnDisp(res);

	}
}