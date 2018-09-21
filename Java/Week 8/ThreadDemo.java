class MultThread extends Thread
{
  int n;
  MultThread(int n1)
  {
	  
	  n=n1;
  }
  public void run()
  {
 
     for (int i=1; i<=10; i++)
     {
      
        System.out.println( +n+ " * "+i+" : " +(n*i));
      }
   }
}

class ThreadDemo {

	public static void main(String[] args) {
		
	    
	    MultThread   firstThread = new MultThread(5);
	   
	    MultThread   secondThread = new MultThread(7);
	   
	    firstThread.start();
	    try{
	    	firstThread.join();
	    }catch(InterruptedException e){}
	    secondThread.start();
	}

}
