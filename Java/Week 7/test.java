class test{
	void meth(int j, int i){
		i *= 2;
		j /= 2;
	}
	public static void main(String args[]){
		test obj = new test();
		int a = 10;
		int b = 20;
		System.out.println(a+" "+b);
		obj.meth(a,b);
		System.out.println(a+" "+b);
		
	}
}