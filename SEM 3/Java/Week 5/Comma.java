import java.util.Scanner;

class Comma{
	public static void main(String args[]){
		Scanner sc = new Scanner(System.in);
		System.out.println("Enter the string");
		String str = sc.next();
		String str2 = "";
		int counter = 0;
		for(int i = str.length() - 1; i >= 0; i--){

			str2 = str2 + str.charAt(i);
			counter++;
			if(counter == 3){
				str2 = str2 + ',';
				counter = 0;
			}
		}
        str = "";

		for(int j = str2.length() - 1; j >= 0 ; j--){

			str = str + str2.charAt(j);
		}

		System.out.println(str);

	}
}
