import java.util.Scanner;

public class NormTrace
{
      public static void NnT(int a[][], int rnc)
      {
          int TraceSum = 0;
          int NormSum = 0;
         for(int i = 0; i<rnc; i++)
         {
            for(int j = 0; j<rnc; j++)
            {  
              NormSum+=a[i][j]*a[i][j];
            }
         }
         
         for(int j = 0; j<rnc; j++)
         {  
            TraceSum+=a[j][j];
         }
         
         System.out.println("Trace = " + TraceSum);
         System.out.println("Normal = " + Math.sqrt(NormSum));
         
      }
      public static void main(String args[])
      {
         Scanner sc = new Scanner(System.in);
      
         System.out.println("Enter number of rows and columns for the Matrix");
         int rnc = sc.nextInt();
      
         int mat[][] = new int[rnc][rnc];
      
         System.out.println("Enter Elements for the matrix");
      
         for(int i = 0; i<rnc; i++)
         {
            for(int j = 0; j<rnc; j++)
            {  
              mat[i][j] = sc.nextInt();
            }
         }
      
      NnT(mat, rnc);
      }
}
