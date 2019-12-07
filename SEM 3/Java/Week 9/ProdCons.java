import java.util.*;

class Tickets{
	boolean available = false;
	int quantity;

	public synchronized void produce(){
		if(available){
			try{
				wait();
			}catch(InterruptedException e){
				System.out.println("Interrupted Exception");
			}
		}
		available = true;
		System.out.println("The Ticket Booth has produced a Ticket");
		notify();
	}

	public synchronized void consume(){
		if(!available){
			try{
				wait();
			}catch(InterruptedException e){
				System.out.println("Interrupted Exception");
			}
		}
		available = false;
		System.out.println("The Ticket has been used");
		notify();
	}
}

class Producer extends Thread{
	Tickets tick;
	int t;

	public Producer(Tickets tick, int t){
		this.tick = tick;
		this.t = t;
	}

	public void run(){
		while(t!=0){
			tick.produce();
			try{
				Thread.sleep(100);
			}catch(InterruptedException e){
				e.printStackTrace();
			}
			t--;
		}
	}
}

class Consumer extends Thread {
    Tickets tick;
    int t;
 
    public Consumer(Tickets tick, int t) {
        this.tick = tick;
        this.t = t;
    }
 
    public void run() {
        do {
            tick.consume();
            try {
                sleep(100);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
            t--;
        } while (t>0);
    }
}

public class ProdCons{
    public static void main(String[] args) {
        Tickets ti = new Tickets();
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter number of Tickets");
        int t = sc.nextInt();
        Producer p = new Producer(ti, t);
        Consumer c = new Consumer(ti, t);
        p.start();
        c.start();
    }
}