import java.util.Scanner;

public class MatAdd
{
   public static void add(int a[][], int b[][], int r, int c)
   {  
      System.out.println("Resultant Matrix : ");
      for(int i = 0; i < r; i++)
      {
         for(int j = 0; j < c; j++)
         {
           System.out.print((a[i][j] + b[i][j]) + "\t");
         }
         System.out.println();
      }
   } 
   public static void main(String args[])
   {
      Scanner sc = new Scanner(System.in);
      
      System.out.println("Enter number of rows and columns for the Matrices");
      int r = sc.nextInt();
      int c = sc.nextInt();
      
      
      int mat1[][] = new int[r][c];
      int mat2[][] = new int[r][c];
      
      System.out.println("Enter Elements for matrix 1:");
      
      for(int i = 0; i<r; i++)
      {
        for(int j = 0; j<c; j++)
        {
          mat1[i][j] = sc.nextInt();
        }
      }
      
      System.out.println("Enter Elements for matrix 2:");
      
      for(int i = 0; i<r; i++)
      {
        for(int j = 0; j<c; j++)
        {
          mat2[i][j] = sc.nextInt();
        }
      }
      
      add(mat1, mat2, r, c);
   }
}
