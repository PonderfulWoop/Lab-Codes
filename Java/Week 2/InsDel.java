import java.util.Scanner;

public class InsDel
{
   public static void Insert(int a[], int l)
   {
     Scanner s = new Scanner(System.in);
     System.out.println("Enter element to insert:");
     int elem = s.nextInt();
     System.out.println("Enter position to insert:");
     int pos = s.nextInt();
     pos--;
     for(int i = l; i>pos; i--)
     {
       a[i] = a[i-1];
     }
     a[pos] = elem;
     System.out.println("New Array");
     for(int i = 0; i<=l; i++)
     {
       System.out.println(a[i]);
     }
   }
   public static void Delete(int a[], int l)
   {
     Scanner s = new Scanner(System.in);
     System.out.println("Enter position to delete:");
     int pos = s.nextInt();
     pos--;
     
     for(int i = pos; i<(l-1); i++)
     {
       a[i] = a[i+1];
     }
     System.out.println("New Array");
     for(int i = 0; i<(l-1); i++)
     {
       System.out.println(a[i]);
     }
   }
   public static void main(String args[])
   {
      Scanner sc = new Scanner(System.in);
      System.out.println("Enter number of elements:");
      int n = sc.nextInt();
      n+=1;
      int arr[] = new int[n];
      n--;
      System.out.println("Enter Elements:");
      for(int i = 0; i<n; i++)
      {
        arr[i] = sc.nextInt();
      }
      
      System.out.println("Choose:\n1.Insert\t2.Delete");
      int choice = sc.nextInt();
      
      switch(choice)
      {
        case 1:
            Insert(arr, n);
            break;
        case 2:
            Delete(arr, n);
            break;
      }
      
   }
}
