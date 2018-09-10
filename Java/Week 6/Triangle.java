import myPackages.p2.Figure;


public class Triangle extends Figure{

	public int area(int h, int b){
		return h*b;
	}

	public static void main(String args[]){

		Triangle obj = new Triangle();
		System.out.println("Area of a triangle with H = 10 and B = 5 : " + (0.5*obj.area(5, 10)));

	}
}