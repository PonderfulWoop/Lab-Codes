package com.course.buildings;


public class House extends Building
{
	private int beds;
	private int bath;
	public void set(int a,int b, int st, float sq)
	{	super.set(st, sq);
		this.beds=a;
		this.bath=b;
	}
	public void get()
	{
		super.get();
		System.out.println("Bedrooms: "+this.beds);
		System.out.println("Bathrooms "+this.bath);
	}

}