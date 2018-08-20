import java.util.Scanner;

public class LinearSearch
{
   public static int searchElem(int a[], int n, int key)
   {
      for(int i = 0; i<n; i++)
      {
         if(a[i] == key)
            return i+1;
      }
      
      return -1;
   }
   public static void main(String args[])
   {
      Scanner sc = new Scanner(System.in);
      System.out.println("Enter number of elements:");
      int n = sc.nextInt();
      int arr[] = new int[n];
      System.out.println("Enter Elements:");
      for(int i = 0; i<n; i++)
      {
        arr[i] = sc.nextInt();
      }
      System.out.println("Enter element to search: ");
      int no = sc.nextInt();
      if(searchElem(arr, n, no) == -1)
         System.out.println("Element not found");
      else
         System.out.println("Element found at position : " + searchElem(arr, n, no));
   }
}
