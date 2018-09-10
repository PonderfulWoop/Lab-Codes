package com.course.buildings;

public class Building
{
	private int sf;
	private float st;
	public void set(int a,float b)
	{
		this.sf=a;
		this.st=b;
	}
	public void get()
	{
		System.out.println("Square feet: "+this.sf);
		System.out.println("Stories: "+this.st);
	}

}
