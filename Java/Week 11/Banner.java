import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
import java.util.*;
// This class extends JPanel. It overrides
// the paintComponent() method so that random
// lines are plotted in the panel.
class PaintPanel extends JPanel implements Runnable {
String msg = " A Simple Moving Banner.";
Thread t;
// Construct a panel.
PaintPanel() {
// Put a border around the panel.
setBorder(
BorderFactory.createLineBorder(Color.RED, 5));
t=new Thread(this);
t.start();
}
public void run() {
// Redisplay banner
for( ; ; ) {
try {
repaint();
Thread.sleep(250);
} catch(InterruptedException e) {}
}
}
// Override the paintComponent() method.
protected void paintComponent(Graphics g) {
// Always call the superclass method first.
super.paintComponent(g);
char ch;
ch = msg.charAt(0);
msg = msg.substring(1, msg.length());
msg += ch;
g.drawString(msg, 150,100);

}
}
// Demonstrate painting directly onto a panel.
class Banner {
JLabel jlab;
PaintPanel pp;
Banner() {
// Create a new JFrame container.
JFrame jfrm = new JFrame("mooving banner");
// Give the frame an initial size.
jfrm.setSize(500, 350);
// Terminate the program when the user closes the application.
jfrm.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
// Create the panel that will be painted.
pp = new PaintPanel();
// Add the panel to the content pane. Because the default
// border layout is used, the panel will automatically be
// sized to fit the center region.
jfrm.add(pp,BorderLayout.CENTER);
jlab=new JLabel("Scrolling Banner");
jfrm.add(jlab,BorderLayout.SOUTH);
// Display the frame.
jfrm.setVisible(true);
}
public static void main(String args[]) {

new Banner();
}
}