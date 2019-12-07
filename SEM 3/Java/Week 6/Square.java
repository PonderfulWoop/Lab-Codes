import myPackages.p2.Figure;

public class Square extends Figure{

	public int area(int h, int b){
		return h*b;
	}

	public static void main(String args[]){

		Square obj = new Square();
		System.out.println("Area of 5x5 Square : " + obj.area(5, 5));

	}
}