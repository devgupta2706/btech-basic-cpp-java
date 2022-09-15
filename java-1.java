
// Java program to show WARNING_MESSAGE dialog
// in Java. Importing different Package.
import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

class Demo extends JFrame implements ActionListener {
   // Declaration of object of JButton class.
   JButton b1;

   // Constructor of Demo class
   Demo() {
      // Setting layout as null of JFrame.
      this.setLayout(null);

      // Initialization of object of "JButton" class.
      b1 = new JButton("Button 2");

      // Setting Bounds of a JButton.
      b1.setBounds(130, 05, 100, 50);

      // "this" keyword in java refers to current object.
      // Adding JButton on JFrame.
      this.add(b1);

      // Adding Listener toJButton.
      b1.addActionListener(this);
   }

   // Override Method
   public void actionPerformed(ActionEvent evt) {
      if (evt.getSource() == b1) {

         // Code To popup an WARNING_MESSAGE Dialog.
         JOptionPane.showMessageDialog(this, "Enter a valid String",
               "WARNING", JOptionPane.WARNING_MESSAGE);
      }
   }
}

class MessageDialogs2 {

   // Driver code
   public static void main(String args[]) {
      // Creating Object of demo class.
      Demo f = new Demo();

      // Setting Bounds of a Frame.
      f.setBounds(200, 200, 400, 300);

      // Setting Resizable status of frame as false
      f.setResizable(false);

      // Setting Visible status of frame as true.
      f.setVisible(true);
   }
}
