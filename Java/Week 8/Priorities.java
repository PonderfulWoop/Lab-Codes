class Threads extends Thread{
  int no;
  public Threads(int no){
    this.no = no;
  }
  public void run(){
    System.out.println("Thread no: "+no);
  }
}
class Priorities
{
    public static void main(String[]args) 
    { 
    	Threads t1 = new Threads(1); 
    	Threads t2 = new Threads(2); 
    	Threads t3 = new Threads(3); 
  
        System.out.println("t1 thread priority : " + 
                              t1.getPriority()); // Default 5 
        System.out.println("t2 thread priority : " + 
                              t2.getPriority()); // Default 5 
        System.out.println("t3 thread priority : " + 
                              t3.getPriority()); // Default 5 
  
        t1.setPriority(8); 
        t2.setPriority(6); 
        t3.setPriority(2);

        System.out.println("t1 thread priority : " + 
                              t1.getPriority());
        System.out.println("t2 thread priority : " + 
                              t2.getPriority());
        System.out.println("t3 thread priority : " + 
                              t3.getPriority());
    } 
}
