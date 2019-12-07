import java.util.Scanner;


public class Bubblesort
{
   public static void ascen(int a[], int k)
   {
        int temp = 0;
        for(int i = 0; i<k-1; i++)
        {
          for(int j = i + 1; j < k; j++)
          {
             if(a[i]>a[j])
             {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
             }
          }
        }
        for(int i = 0; i<k; i++)
        {
          System.out.println(a[i]);
        }  
   }
   public static void descen(int a[], int k)
   {
        int temp = 0;
        for(int i = 0; i<k-1; i++)
        {
          for(int j = i + 1; j < k; j++)
          {
             if(a[i]<a[j])
             {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
             }
          }
        }
        for(int i = 0; i<k; i++)
        {
          System.out.println(a[i]);
        }  
   }
   public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter number of elements:");
        int n = sc.nextInt();
        int arr[] = new int[n];
        System.out.println("Enter elements");
        for(int i = 0; i<n; i++)
        {
           arr[i] = sc.nextInt();
        }
        System.out.println("Ascending order :");
        ascen(arr, n);
        
        System.out.println("Descending order :");
        descen(arr, n);
        
   }
}
