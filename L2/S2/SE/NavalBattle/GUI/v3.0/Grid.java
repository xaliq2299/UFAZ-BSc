import javax.swing.*;
import java.awt.*;

public class Grid extends JFrame {
	private static final long serialVersionUID = 1L;
	Ship ships[]; //! in grid we have ships which are stored in array
	JButton cells[][]; //! each grid consists of 10x10 (100) cells
	int table[][]; //! 10x10 table that can have value 0 (no ship) or 1 (there's ship) or 2 (already visited)
	
	public Grid() {
		this.setPreferredSize(new Dimension(250,250));;
		this.setLayout(new GridLayout(10,10));

		this.table = new int[10][10];
		for(int i=0;i<10;i++) 
			for(int j=0;j<10;j++) 
				this.table[i][j]=0; //! at first there's no ship
		this.cells = new JButton[10][10];

		for(int i=0;i<10;i++) {
			for(int j=0;j<10;j++) {
				this.cells[i][j] = new JButton();
				this.add(this.cells[i][j]);
			}
		}
		//!important, not to have nullPointerException
		this.ships=new Ship[5];
		for(int i=0;i<5;i++)
			this.ships[i] = new Ship();
	}
}