import java.util.*;

class Gen<T>{
	T nums[], x, y;
	int posX, posY;
	Gen(T n[], T x, T y){
		this.nums = n;
		this.x = x;
		this.y = y;
	}
	public void swap(){
		for(int i = 0; i<nums.length; i++){
			if(nums[i].equals(x)){
				posX = i;
				break;
			}
		}

		for(int i = 0; i<nums.length; i++){
			if(nums[i].equals(y)){
				posY = i;
				break;
			}
		}

		T temp = nums[posX];
		nums[posX] = nums[posY];
		nums[posY] = temp;
      
		for(int i = 0; i<nums.length; i++){
			System.out.print(nums[i] + "\t");
		}
		System.out.println();
	}
}

class ExchangeElements{
	public static void main(String args[]){
		Integer[] n = {1,3,2,1,33,4};
		Double[] d = {2.3, 4.6, 54.0, 23.5};
		String[] s = {"Hello", "World", "Java"};

		Gen<Integer> ob = new Gen<Integer>(n, 33, 3);
		Gen<Double> ob2 = new Gen<Double>(d, 4.6, 2.3);
		Gen<String> ob3 = new Gen<String>(s, "World", "Java");
		System.out.println("List(s) before swapping: ");
		
		for(int i = 0; i < n.length; i++){
			System.out.print(n[i]+"\t");
		}
		System.out.println();

		for(int i = 0; i < d.length; i++){
			System.out.print(d[i]+"\t");
		}
		System.out.println();
		for(int i = 0; i < s.length; i++){
			System.out.print(s[i]+"\t");
		}
		System.out.println();
		System.out.println("Lists(s) after swapping");
		ob.swap();
		ob2.swap();
		ob3.swap();
 	}
}