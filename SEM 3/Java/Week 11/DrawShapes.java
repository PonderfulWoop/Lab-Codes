import java.awt.*;
import java.awt.event.*;
import java.applet.*;
import javax.swing.*;

 class ppanel extends JPanel{ 
       	int x,y,p,q;
        JButton j1,j2,j3,j4;
        String s="Rect";
 	ppanel()
 	{
        j1=new JButton("Rect");
        add(j1); 
        j2=new JButton("circle");
        add(j2);
        j3=new JButton("arc");
        add(j3);
        j4=new JButton("line");
        add(j4);
        j1.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent ae)
 			{       s="Rect";  }
            });
        j2.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent ae)
 			{       s="circle";  }
            });
        j3.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent ae)
 			{       s="arc";  }
            });
        j4.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent ae)
 			{       s="line";  }
            });
 	addMouseListener(new MouseAdapter(){
 		
 			public void mousePressed(MouseEvent me){
 			
 				x=0;
 				y=0;
 				x=me.getX();
 				y=me.getY();
 		
 			}
 		
 		});
 	addMouseMotionListener(new MouseMotionAdapter()
 		{
 				public void mouseDragged(MouseEvent me)
 			{
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
 		g.setColor(Color.blue);
 		if(s=="Rect") 
                  g.fillRoundRect(x,y,(p-x),(q-y),10,15);
                else if(s=="circle")
	          g.fillOval(x,y,(p-x),(p-x));
                else if(s=="arc")
                  g.fillArc(x,y,(p-x),(q-y),0,120);
                else if(s=="line") 
                  g.drawLine(x,y,p,q);
 	}
 }
class DrawShapes{
     DrawShapes(){
        JFrame jf= new JFrame("Drawing Shapes");
        ppanel pp=new ppanel();
        jf.add(pp);
        jf.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        jf.setSize(500,600);
        jf.setVisible(true);
       }
     public static void main(String args[]){
       SwingUtilities.invokeLater(new Runnable() {
	public void run() {
	new DrawShapes(); 
	}
	});
     }
}