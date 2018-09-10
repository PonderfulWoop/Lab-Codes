import myPackages.p1.Max;

public class UseMax{
	public static void main(String args[]){
		Max obj = new Max();
		int arr[] = {2,4,5,6,7,8,9,2,3,2,1};
		int arr2[][] = {{1,2,3}, {4,5,6}, {7,8,9}, {3,2,1}};
		System.out.println("Max Methods : ");
		System.out.println("Max of 3 integer numbers : " + obj.max(2,4,1));
		System.out.println("Max of 3 floating numbers : " + obj.max(2.1f, 5.6f, 1.1f));
		System.out.println("Max of an array : " + obj.max(arr));
		System.out.println("Max of a Matrix : " + obj.max(arr2, 4));
	}
}