import java.util.Scanner;

public class primeArr
{
  public static boolean isPrime(int n)
  {
     for(int i = 2; i<=n/2; i++)
     {
       if(n%i == 0)
          return false;
     }
     return true;
  }
  public static void printP(int a[])
  {
    for(int i = 0; i<a.length; i++)
    {
      if(isPrime(a[i]))
         System.out.println(a[i]);
    }
  }
  public static void main(String args[])
  {
     Scanner sc = new Scanner(System.in);

     System.out.println("Enter number of elements:");
     int n = sc.nextInt();
     int arr[] = new int[n];
     
     System.out.println("Enter Elements: ");
     for(int i = 0; i<n; i++)
        arr[i] = sc.nextInt();
        
     System.out.println("List of Primes:");
     printP(arr);
  }
}
