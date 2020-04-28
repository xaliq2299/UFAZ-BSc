import javax.swing.*;

import java.awt.event.ActionListener;
import java.awt.Color;
import java.awt.event.ActionEvent;

public class UserListener implements ActionListener{	
	User u;
	int counter; //! used for clicking: if even colored, if odd no color
	String shipName; //! There're 5 types of ships
	
	public UserListener(User u, String shipName) {
		counter=0; this.u=u; this.shipName=shipName;
	}
	
	public void setShipName(String shipName) {
		this.shipName=shipName;
	}
	
	//! each time cell is selected the following method handles everything
	public void actionPerformed ( ActionEvent e ) {
		//! data needed in advance
		Color color=Color.WHITE; //! each ship has its own color
		int count=0; //! size of ship (# of cells of color <color>)
		int xStart=-1, yStart=-1;
		int shipIndex=-1, size=0;
		boolean shipCanBeValid=true; char orientation='0';
		//! which ship?
		if(shipName.equals("Carrier")) {
			color=Color.BLUE;
			shipIndex=0;
			size=5;
		}
		else if(shipName.equals("Battleship")) {
			color=Color.YELLOW;
			shipIndex=1;
			size=4;
		}
		else if(shipName.equals("Cruiser")) {
			color=Color.MAGENTA;
			shipIndex=2;
			size=3;
		}
		else if(shipName.equals("Submarine")) {
			color=Color.PINK;
			shipIndex=3;
			size=3;
		}
		else if(shipName.equals("Destroyer")) {
			color=Color.BLACK;
			shipIndex=4;
			size=2;
		}
		u.myGrid.ships[shipIndex].validity=false; //! important point 
		
		//! each cell has its own counter
		//! counter is even or odd? (each time counter is incremented)
		if(counter%2 == 0) { //! arrange a ship cell to the current button (color)
			JButton button = (JButton) e.getSource();
			button.setBackground(color);
			
			//! counting number of cells of certain Color <color>
			for(int i=0;i<10;i++) {
				for(int j=0;j<10;j++) {
					if(u.myGrid.cells[i][j].getBackground() == color)
						count++;
				}
			}
			//!System.out.println(count); //! for debugging
			if( (count==size && shipIndex==0) || (count==size && shipIndex==1) ||
				(count==size && shipIndex==2) || (count==size && shipIndex==3)||
				(count==size && shipIndex==4) //! check 5 possible ship situations
			  ) {
				boolean tmp=false; //! temporary boolean that helps to find the coordinates of initial cell
				for(int i=0;i<10;i++) {
					for(int j=0;j<10;j++) {
						if(u.myGrid.cells[i][j].getBackground() == color) {
							xStart=i; yStart=j;
							tmp=true;
							break;
						}
					}
					if(tmp) break;
				}
				//!System.out.println("xStart="+xStart); //! for debugging
				//!System.out.println("yStart="+yStart); //! for debugging
					
				//! determining whether the chosen ship is valid or no
				shipCanBeValid=true;
				if(xStart != 9 && yStart !=9) {
					if(u.myGrid.cells[xStart+1][yStart].getBackground() == color) { //! one cell below
						if(xStart+size-1 <= 9) { //! is it possible to put the ship in those cells?
							orientation='v'; //! vertical
							for(int i=xStart+2;i<xStart+size;i++) { //! the remaining cells
								if(u.myGrid.cells[i][yStart].getBackground() != color) {
									shipCanBeValid=false; break;
								}
							}
						}
						else
							shipCanBeValid=false;
					}
					
					else if(u.myGrid.cells[xStart][yStart+1].getBackground() == color) { //! one cell to the right
						if(yStart+size-1 <= 9) { //! is it possible to put the ship in those cells?
							orientation='h'; //! horizontal
							for(int j=yStart+2;j<yStart+size;j++) { //! the remaining cells
								if(u.myGrid.cells[xStart][j].getBackground() != color) {
									shipCanBeValid=false; break;
								}
							}
						}
						else
							shipCanBeValid=false;
					}
					else shipCanBeValid=false; //! the case when no valid ship is presented
				}
				else if(yStart == 9) {
					if(u.myGrid.cells[xStart+1][yStart].getBackground() == color) { //! one cell below
						if(xStart+size-1 <= 9) { //! is it possible to put the ship in those cells?
							orientation='v'; //! vertical
							for(int i=xStart+2;i<xStart+size;i++) { //! the remaining cells
								if(u.myGrid.cells[i][yStart].getBackground() != color) {
									shipCanBeValid=false; break;
								}
							}
						}
						else shipCanBeValid=false;
					}
					else shipCanBeValid=false; //! the case when no valid ship is presented
				}
				else { //! xStart=9
					if(u.myGrid.cells[xStart][yStart+1].getBackground() == color) { //! one cell to the right (but at the last line)
						if(yStart+size-1 <= 9) { //! is it possible to put the ship in those cells?
							orientation='h'; //! horizontal
							for(int j=yStart+2;j<yStart+size;j++) { //! the remaining cells
								if(u.myGrid.cells[xStart][j].getBackground() != color) {
									shipCanBeValid=false; break;
								}
							}
						}
						else shipCanBeValid=false;
					}
					else shipCanBeValid=false; //! the case when no valid ship is presented
				}
				
				//! after ship's validity there comes setting the info about ship
				if(shipCanBeValid == false) { //! no valid ship is presented: remove colors, increase counter for further use
					for(int i=0;i<10;i++) {
						for(int j=0;j<10;j++) {		
							if(u.myGrid.cells[i][j].getBackground() == color) {
								u.myGrid.cells[i][j].setBackground(null);
								u.ul[i][j].counter++;
							}
						}
					}
				}
				else { //! ship is valid: set the data about ship
					switch(shipIndex) { //! setting names of ships
						case 0:  u.myGrid.ships[shipIndex].setName("Carrier"); break;
						case 1:  u.myGrid.ships[shipIndex].setName("BattleShip"); break;
						case 2:  u.myGrid.ships[shipIndex].setName("Cruiser"); break;
						case 3:  u.myGrid.ships[shipIndex].setName("Submarine"); break;
						case 4:  u.myGrid.ships[shipIndex].setName("Destroyer"); break;
						default: u.myGrid.ships[shipIndex].setName(""); break;
					}
					if(orientation == 'h') { //! horizontal
						u.myGrid.ships[shipIndex].orientation='h';						
						u.myGrid.ships[shipIndex].xEnd=xStart;
						u.myGrid.ships[shipIndex].yEnd=yStart+size-1;
					}
					else { //! vertical
						u.myGrid.ships[shipIndex].orientation='v';
						u.myGrid.ships[shipIndex].xEnd=xStart+size-1;
						u.myGrid.ships[shipIndex].yEnd=yStart;
					}
					u.myGrid.ships[shipIndex].validity=true;
					
					//! after everything is finished, ship is set and we remove listeners
					for(int i=0;i<10;i++) {
						for(int j=0;j<10;j++)
							u.myGrid.cells[i][j].removeActionListener(u.ul[i][j]);
					}
					//!System.out.println("orientation="+u.myGrid.ships[shipIndex].orientation); //! for debugging
					//!System.out.println("xEnd="+u.myGrid.ships[shipIndex].xEnd); //! for debugging
					//!System.out.println("yEnd="+u.myGrid.ships[shipIndex].yEnd); //! for debugging
				}
			}
			else if(count>5){ //! can't happen, because we don't have ship of size more than 5
				for(int i=0;i<10;i++) {
					for(int j=0;j<10;j++) {			
						if(u.myGrid.cells[i][j].getBackground() == color)
							u.myGrid.cells[i][j].setBackground(null);
					}
				}
			}
		}
		else { //! remove the ship cell from the current button (remove color)
			JButton button = (JButton) e.getSource();
			button.setBackground(null);
		}
		counter++; //! increment counter
	}
}
