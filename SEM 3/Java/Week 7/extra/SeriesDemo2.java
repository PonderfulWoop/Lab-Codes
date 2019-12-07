package p2;


import p1.Series;

class ByTwos1 implements Series {

int start;
  int val;

  ByTwos1() {
    start = 0;
    val = 0;
  }

  // Implement the methods specified by Series.
  public int getNext() {
    val += 2;
    return val;
  }

  public void reset() {
    val = start;
  }

  public void setStart(int x) {
    start = x;
    val = x;
  }
 
}

class SeriesDemo2 {
  public static void main(String[] args) {
    ByTwos1 ob = new ByTwos1();

    for(int i=0; i < 5; i++)
      System.out.println("Next value is " + ob.getNext());

    System.out.println("\nResetting");
    ob.reset();
    for(int i=0; i < 5; i++)
      System.out.println("Next value is " + ob.getNext());

    System.out.println("\nStarting at 100");
    ob.setStart(100);
    for(int i=0; i < 5; i++)
      System.out.println("Next value is " + ob.getNext());
   
  }
}

