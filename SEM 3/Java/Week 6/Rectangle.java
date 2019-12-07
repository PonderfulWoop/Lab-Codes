import myPackages.p2.Figure;


public class Rectangle extends Figure{

	public int area(int h, int b){
		return h*b;
	}

	public static void main(String args[]){

		Rectangle obj = new Rectangle();
		System.out.println("Area of 5x10 Rectangle : " + obj.area(5, 10));

	}
}