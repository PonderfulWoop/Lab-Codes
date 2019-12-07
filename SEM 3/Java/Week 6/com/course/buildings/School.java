package com.course.buildings;
import java.util.*;
public class School extends Building
{
	private int cr;
	private int gl;
	public void set(int a,int b, int st, float sq)
	{
		super.set(st,sq);
		this.cr=a;
		this.gl=b;
	}
	public void get()
	{
		super.get();
		System.out.println("Classrooms: "+this.cr);
		System.out.println("Grade Level: "+this.gl);
	}

}