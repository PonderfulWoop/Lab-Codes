import java.util.*; 
  
class WildCardDemo 
{ 
    public static void main(String[] args) 
    {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter Choice:\n1.Integer\n2.Double");
        int in = sc.nextInt();
        
        if(in == 1){
            List<Integer> list= Arrays.asList(6,7,3,1,2,3,45,6); 
            System.out.println("Total sum is: "+sum(list)); 
        }  
        
        else if(in == 2){
            List<Double> list=Arrays.asList(4.1,5.1,6.1, 5.1, 6.2, 7.4);
            System.out.println("Total sum is: "+sum(list));
        }
        else{
            System.out.println("Wrong Choice");
        }
    } 
  
    private static double sum(List<? extends Number> list)  
    { 
        double sum=0.0; 
        for (Number i: list) 
        { 
            sum+=i.doubleValue(); 
        } 
  
        return sum; 
    } 
} 