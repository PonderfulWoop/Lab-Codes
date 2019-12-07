import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
import java.text.NumberFormat;

 public class RanCircle {
 	
        RanCircle(){
        
	JFrame jfrm=new JFrame("Random Circle");
	ppanel jp=new ppanel();
        jfrm.setSize(500,300);
	jfrm.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
	jfrm.add(jp);
	jp.setVisible(true);
        jfrm.setVisible(true);
      	}
	
	public static void main(String[] args) {
	SwingUtilities.invokeLater(new Runnable() {
	public void run() {
	new RanCircle(); 
	}
	});
	}
 }
class ppanel extends JPanel{
    JLabel jlab;       
    int x,y,p,q;
    NumberFormat nf;
    ppanel(){
           setSize(400,200);
           nf = NumberFormat.getInstance();
           nf.setMaximumFractionDigits(2);
           jlab=new JLabel("Hello");
	   add(jlab);
	   addMouseListener(new MouseAdapter(){
 		public void mousePressed(MouseEvent me){
 		    x=0;
 		    y=0;
 		    x=me.getX();
 		    y=me.getY();
 		 }
 		});
 		addMouseMotionListener(new MouseMotionAdapter(){
 		
 			public void mouseDragged(MouseEvent me){
 				p=0;
 				q=0;
 				p=me.getX();
 				q=me.getY();
 				repaint();
 			}
		});
	}
        protected void paintComponent(Graphics g){
	   super.paintComponent(g);
	   g.drawOval(x,y,(p-x),(p-x));
	   double r=(p-x)/(2*37.8);
	   double area=3.14*r*r;
           jlab.setText("Radius: "+nf.format(r)  +"   Area of circle: " + nf.format(area));
	}
}