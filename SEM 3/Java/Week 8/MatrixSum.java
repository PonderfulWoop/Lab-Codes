import java.util.*;
import java.io.*;

class RowSum extends Thread{
	private int arr[][];
	private int r, c, n;
    public int rowS = 0;
    public RowSum(int arr[][], int r, int c, int n){
    	this.arr = arr;
    	this.r = r;
    	this.c = c;
    	this.n = n;
    }
	public void run(){
		rowS = 0;
		for(int i = 0; i<arr[n].length; i++)
			rowS+=arr[n][i];

	}
	public int getPartialSum(){
		return rowS;
	}
}

class MatrixSum{
	public static void main(String arg[]){

		Scanner sc = new Scanner(System.in);
		int finSum = 0;
		System.out.println("Enter rows and cols");
		int r = sc.nextInt();
		int c = sc.nextInt();
		int arr[][] = new int[r][c];
		System.out.println("Enter the elems");
		for(int i = 0; i<r; i++){
			for(int j = 0; j<c; j++){
				arr[i][j] = sc.nextInt();
			}
		}
		RowSum threads[] = new RowSum[r];
		for(int i = 0; i < r; i++){
			threads[i] = new RowSum(arr, r, c, i);
			threads[i].start();
			try{
                    threads[i].join();
                }
            catch(InterruptedException e){}
            
            System.out.println("Partial Sum of Row "+(i+1)+" = "+threads[i].getPartialSum());
            finSum+=threads[i].getPartialSum();
		}

		System.out.println("Final Sum = "+finSum);
	}
}
