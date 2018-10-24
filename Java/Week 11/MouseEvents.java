// Demonstrate the mouse event handlers.
import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

public class MouseEvents extends JFrame
implements MouseListener, MouseMotionListener {
String msg = ""; JLabel jl;
int mouseX = 0, mouseY = 0; // coordinates of mouse
MouseEvents() {
jl=new JLabel();
setLayout(new FlowLayout());
addMouseListener(this);
addMouseMotionListener(this);
add(jl);
setSize(500,400);
setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
setVisible(true);
}
// Handle mouse clicked.
public void mouseClicked(MouseEvent me) {
// save coordinates
mouseX = 0;
mouseY = 10;
msg = "Mouse clicked.";
jl.setText(msg+",at"+me.getX()+","+me.getY());
}
// Handle mouse entered.
public void mouseEntered(MouseEvent me) {
// save coordinates
mouseX = 0;
mouseY = 10;
msg = "Mouse entered.";
jl.setText(msg+",at"+mouseX+","+mouseY);
}
// Handle mouse exited.
public void mouseExited(MouseEvent me) {
// save coordinates
mouseX = 0;
mouseY = 10;
msg = "Mouse exited.";
jl.setText(msg+",at"+mouseX+","+mouseY);
}
// Handle button pressed.
public void mousePressed(MouseEvent me) {
// save coordinates
mouseX = me.getX();
mouseY = me.getY();
msg = "Down";
jl.setText(msg+",at"+mouseX+","+mouseY);
}
// Handle button released.
public void mouseReleased(MouseEvent me) {
// save coordinates
mouseX = me.getX();
mouseY = me.getY();
msg = "Up";
jl.setText(msg+",at"+mouseX+","+mouseY);
}
// Handle mouse dragged.
public void mouseDragged(MouseEvent me) {
// save coordinates
mouseX = me.getX();
mouseY = me.getY();
msg = "*";

jl.setText(msg+",at"+mouseX+","+mouseY);
}
// Handle mouse moved.
public void mouseMoved(MouseEvent me) {
msg="mouse moved";
jl.setText(msg+",at"+mouseX+","+mouseY);
}

public static void main(String args[]){
MouseEvents mv=new MouseEvents();

}
}