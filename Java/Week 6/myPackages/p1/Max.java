package myPackages.p1;

import java.util.Scanner;

public class Max{
	public int max(int a, int b, int c){
		if(a>b){
			if(a>c)
				return a;
			else
				return c;
		}
		else{
			if(b>c)
				return b;
			else
				return c;
		}
	}

	public float max(float a, float b, float c){

		if(a>b){
			if(a>c)
				return a;
			else
				return c;
		}
		else{
			if(b>c)
				return b;
			else
				return c;
		}
	}

	public int max(int a[]){
		int largest = a[0];
		for(int i = 1; i<a.length; i++){
			if(a[i]>largest)
				largest = a[i];
		}

		return largest;
	}

	public int max(int a[][], int r){

		int largest = a[0][0];

		for(int i = 0; i<r; i++){
			for(int j = 0; j<a[i].length; j++){
				if(a[i][j]>largest)
					largest = a[i][j];
			}
		}

		return largest;
	}
}