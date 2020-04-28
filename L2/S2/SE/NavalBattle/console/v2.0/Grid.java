
public class Grid {
	int size = 10;
	int board[][] = new int[size][size];
	Boat boats[] = new Boat[10];           // boats of this grid
	int nBoats ;
	//initializing the board with -1 values
	public void initGrid() {
		for(int i=0; i< size;i++) 
			for(int j=0; j<size; j++)
				board[i][j] = -1;
		nBoats = 0;
	}
	
	// showing the grid
    public void showGrid(){
    	for(int i=65; i< size+65; i++) {
    		System.out.printf("\t%c",i);
    	}
        System.out.println();
        
        for(int row=0 ; row < size ; row++ ){
            System.out.print((row+1)+"");
            for(int column=0 ; column < size ; column++ ){
                  System.out.print("\t"+this.board[row][column]);
            	
            }                              
            System.out.println();
        }

    }
    
   // adding a boat to a board of a grid
    public void addBoat(Boat b) {         					
    	boats[nBoats] = b;
    	nBoats++;
    	for(int i=0; i<b.length; i++) {
    		if(i<2)
    			this.board[b.positions[i][0]][b.positions[i][1]] = -2;    		
    		else {
    			if(b.vertical == false)
    				this.board[b.positions[0][0]+b.length-i][b.positions[0][1]] = -2;
    			else
    				this.board[b.positions[0][0]][b.positions[0][1]+b.length-i] = -2;
    		}
    	}
    }
    // checking whether a boat can be added to this grid or not
    public boolean canAdd(Boat b) { 
    	if(b.vertical == true) {
    		for(int xF = b.positions[0][0]-1,count = 0; count< 3; count++, xF++) {
				for(int yF = b.positions[0][1]-1 ,count2 = 0; count2 < b.length +2; count2++, yF++ )
					if(xF > -1 && yF > -1 && xF < 10 && yF < 10) {
						if(this.board[xF][yF] == -2)
							return false;
						}
			}
    	}
    	else {
    		for(int xF = b.positions[0][0]-1,count = 0; count< b.length+2; count++, xF++) {
				for(int yF = b.positions[0][1]-1 ,count2 = 0; count2 < 3; count2++, yF++ ) 
					if(xF > -1 && yF > -1 && xF < 10 && yF < 10) {
						if(this.board[xF][yF] == -2)
							return false;
						}					
				}
			}    	
    	return true;
    } 
    public int checkShoot(int x, int y,Grid enemyGrid) { 
    	if( this.board[x][y] >= 0 ) {      // this position has already been shoot before
    		return 3;                      // return error code
    	}
    	if ( this.board[x][y] == -1) {    // there is no boat
    		this.board[x][y] = 0;
    		enemyGrid.board[x][y] = 0;
    		return 0; 
    	}
    	else if(this.board[x][y] == -2) { // there is a ship
    		this.board[x][y] = 1;
    		enemyGrid.board[x][y] = 1;
    		for(int i=0; i<nBoats; i++) {

    			if(boats[i].vertical == true) {
    				if( x == boats[i].positions[0][0] && y<= boats[i].positions[1][1] && y>= boats[i].positions[0][1] ) {
							if( boats[i].length == 1 ) {    		    							
								boatSurround(boats[i],enemyGrid,this,boats[i].length,true);
								this.board[x][y] = 2;   
								enemyGrid.board[x][y] = 2;
								return 2;
							}
    						for(int y1 = boats[i].positions[0][1]; y1<=boats[i].positions[1][1]; y1++) {
    							if(this.board[x][y1] == 1) {

    								if(y1 == boats[i].positions[1][1]) { // means boat is sank,change all to 2
    									boatSurround(boats[i],enemyGrid,this,boats[i].length,true);
    									boatSank(boats[i],x,enemyGrid);
    		    						return 2;
    								}
    							}
    							else {
    			        			return 1;
    							}
    								
    						}
    					}
    			}
    					
    			else {  // horizontal 				
    				if( y == boats[i].positions[0][1] && x<= boats[i].positions[1][0] && x>= boats[i].positions[0][0] ) {
						for(int x1 = boats[i].positions[0][0]; x1<=boats[i].positions[1][0]; x1++) {
							if(this.board[x1][y] == 1) {
								if(x1 == boats[i].positions[1][0]) { // means boat is sank,change all to 2
									boatSurround(boats[i],enemyGrid,this,boats[i].length,false);
									boatSankh(boats[i],x,enemyGrid);
		    						return 2;
								}
							}
							else {
					    		return 1;
							}			
						}
					}    			
    			}
    			if(i == nBoats-1) {  // sth went wrong
        			return 1;
    			}
    		}
    				
    	}
    	return 0;
    }
    
	// boat surround function, make all surrounding = 0 
    public void boatSurround(Boat b,Grid enemyGrid, Grid thisGrid,int length, boolean vertical) {
    	int i,j;
    	if(length == 1) { i =3; j =3;}
    	else if(vertical == true) {i=3; j= b.length+2;}
    	else { i = b.length+2;j= 3; }
    	for(int xF = b.positions[0][0]-1,count = 0; count< i; count++, xF++) {
			for(int yF = b.positions[0][1]-1 ,count2 = 0; count2 <j ; count2++, yF++ )
				if(xF > -1 && yF > -1 &&  xF < 10 && yF < 10) {
					enemyGrid.board[xF][yF] = 0;
					thisGrid.board[xF][yF] = 0;
				}
    	}
    }
    // when boat sank, change the boards of user and enemy
    public void boatSank(Boat b,int x,Grid enemyGrid) {
		for(int y2 = b.positions[0][1]; y2<=b.positions[1][1]; y2++) {
			this.board[x][y2] = 2;   
			enemyGrid.board[x][y2] = 2;
		}
    }
    public void boatSankh(Boat b,int y,Grid enemyGrid) {

		for(int x2 = b.positions[0][0]; x2<=b.positions[1][0]; x2++) {
			this.board[x2][y] = 2;   		    
			enemyGrid.board[x2][y] = 2;
		}
    }
}