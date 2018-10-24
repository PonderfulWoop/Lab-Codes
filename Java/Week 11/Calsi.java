import java.awt.*; 
import java.awt.event.*; 
import javax.swing.*;

class Calsi extends JFrame { 
 
  JTextField first,second; 
  JButton b;
  JLabel n1,n2,n3,n4;

public static void main(String args[]) {
SwingUtilities.invokeLater(
new Runnable() {
public void run() {
new Calsi();
}
});
}
 
    Calsi() {
        super("Calculator");
    setSize(225,300);
    setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    JLabel fst = new JLabel("First number:"); 
    JLabel scnd = new JLabel("Second number:");
    
    first = new JTextField(8); 
    second = new JTextField(8);
    
    b=new JButton("compute");
    n1=new JLabel("");
    n2=new JLabel("");
    n3=new JLabel("");
    n4=new JLabel("");
    setLayout(new FlowLayout());
 
    add(fst); add(first);
    add(scnd); add(second); 
         
    add(b); 
    add(n1);
    add(n2);
    add(n3);
    add(n4);
  
    b.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent ae)
 		{  compute(); }
            }); 
   setVisible(true);
  } 
  void compute(){
     int a,b;
     a=Integer.parseInt(first.getText());
     b=Integer.parseInt(second.getText());
     n1.setText("Sum is : "+(a+b));
     n2.setText("Difference is : "+(a-b));
     n3.setText("Product is : "+(a*b));
     n4.setText("Quotient is : "+(a/b));
     }
 
}