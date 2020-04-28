import java.awt.*;
import java.util.Random;

public class Bot {
	Grid myGrid;
	boolean turn;
	
	public Bot() {
		this.myGrid = new Grid();
		
		//! Placing ships for bot randomly
		this.randomPlacingBot(5); //! Carrier
		this.randomPlacingBot(4); //! BattleShip
		this.randomPlacingBot(3); //! Cruiser
		this.randomPlacingBot(3); //! Submarine
		this.randomPlacingBot(2); //! Destroyer
		
		this.turn=false;
	}
	
	//! a method to place a ship for bot in a random, but valid place
	public void randomPlacingBot(int size) {
		int x=-1,y=-1, orient=-1, shipIndex=-1;
		boolean shipIsValid=false;
		Random rand = new Random();
		
		while(!shipIsValid) {
			x=rand.nextInt(10);
			y=rand.nextInt(10);
			orient=rand.nextInt(2);
			boolean shipCanBePlaced=true;
			
			if(orient == 0) { //! horizontal
				if(y<=size) {
					for(int j=0;j<size;j++) {
						if(myGrid.table[x][y+j] == 1) {
							shipCanBePlaced=false;
							break;
						}
					}
					if(shipCanBePlaced) {
						//!System.out.println("Horizontal"); //! for debugging
						for(int j=0;j<size;j++)
							myGrid.table[x][y+j]=1;
						shipIsValid=true;
					}
				}
			}
			else if(orient == 1) {
				if(x<=size) {
					for(int i=0;i<size;i++) {
						if(myGrid.table[x+i][y] == 1) {
							shipCanBePlaced=false;
							break;
						}
					}
					if(shipCanBePlaced) {
						//!System.out.println("Vertical"); //! for debugging
						for(int i=0;i<size;i++)
							myGrid.table[x+i][y]=1;
						shipIsValid=true;
					}
				}
			}
		}
		//!System.out.println(x+" "+" "+y); //! for debugging

		//! Setting the info about ship
		switch(size) { //! determining the type of 
			case 5: shipIndex=0; myGrid.ships[shipIndex].name="Carrier"; 	break;
			case 4: shipIndex=1; myGrid.ships[shipIndex].name="BattleShip"; break;
			case 3: if(myGrid.ships[2].validity) { //! handling 2 ships problem of size 3
						shipIndex=3;
						myGrid.ships[shipIndex].name="Submarine";
					}
					else{
						shipIndex=2;
						myGrid.ships[shipIndex].name="Cruiser";
					}
					break;
			case 2: shipIndex=4; myGrid.ships[shipIndex].name="Destroyer"; break;
		}
		myGrid.ships[shipIndex].length=size;
		myGrid.ships[shipIndex].validity=true;
		myGrid.ships[shipIndex].xStart=x;
		myGrid.ships[shipIndex].yStart=y;
		if(orient == 0) {
			myGrid.ships[shipIndex].orientation='h';
			myGrid.ships[shipIndex].xEnd=x;
			myGrid.ships[shipIndex].yEnd=x+5;
		}
		else {
			myGrid.ships[shipIndex].orientation='v';
			myGrid.ships[shipIndex].xEnd=x+5;
			myGrid.ships[shipIndex].yEnd=y;
		}
	}

	//! method for shooting the user's grid for bot
	public boolean shoot(Grid userGrid) { //! randomly chooses some cell
		Random rand = new Random();
		int x=rand.nextInt(10);
		int y=rand.nextInt(10);
		
		if(userGrid.table[x][y] == 1) { //! there's a ship
			userGrid.cells[x][y].setBackground(Color.RED);
			userGrid.table[x][y]=2;
			this.turn=true;
			return true;
		}
		if(userGrid.table[x][y] == 0){ //! there's not a ship
			userGrid.cells[x][y].setBackground(Color.GREEN);
			userGrid.table[x][y]=2;
			this.turn=false;
			return false;
		}
		
		return true; //! the case where the index is 2, the bot still has a chance to shoot
	}
		
	//! method to check whether the bot won or no
	public boolean is_Won(User user) {
		boolean WON=true;
		for(int i=0;i<10;i++) {
			for(int j=0;j<10;j++) {
				if(user.myGrid.table[i][j] == 1) {
					WON=false;
					return WON;
				}
			}
		}
		return WON;
	}
}
