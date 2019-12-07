import java.util.Scanner;

class Complex1{

	double real, complex;

	void assign(double real, double complex){

		this.real = real;
		this.complex = complex;
	}

	void display(Complex1 o){

		String sign = "";
		if(o.complex<0)
			System.out.println(o.real+ " " + o.complex + "i");
		else
			System.out.println(o.real+ " + " + o.complex + "i");

        

	}

	Complex1 add(Complex1 obj)
	{
		Complex1 result = new Complex1();
		
		result.real = this.real + obj.real;
		result.complex = this.complex + obj.complex;

		return result;

	}

	Complex1 sub(Complex1 obj)
	{

		Complex1 result = new Complex1();
		
		result.real = this.real - obj.real;
		result.complex = this.complex - obj.complex;

		return result;
	}
}

class Complex{
	public static void main(String args[]){

		Complex1 obj1 = new Complex1();
		Complex1 obj2 = new Complex1();

		Complex1 addition, subtraction;

		Scanner sc = new Scanner(System.in);
		System.out.println("Enter real and imaginary part of Number 1:");
		double r1 = sc.nextDouble();
		double i1 = sc.nextDouble();

		System.out.println("Enter real and imaginary part of Number 2:");
		double r2 = sc.nextDouble();
		double i2 = sc.nextDouble();

		obj1.assign(r1, i1);
		obj2.assign(r2, i2);

		addition = obj1.add(obj2);
		subtraction = obj1.sub(obj2);

		System.out.println("Addition :");
		addition.display(addition);

		System.out.println("Subtraction :");
		subtraction.display(subtraction);
	}

}