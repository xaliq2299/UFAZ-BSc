public class Ship {
	int length;
	String name;
	int xStart, yStart;
	int xEnd, yEnd;
	boolean validity;
	char orientation;
	
	public Ship() {this.validity=false;}
	
	public Ship(String name) {
		this.name=name;
		if(name.equals("Carrier"))
			this.length=5;
		else if(name.equals("BattleShip"))
			this.length=4;
		else if(name.equals("Cruiser"))
			this.length=3;
		else if(name.equals("Submarine"))
			this.length=3;
		else if(name.equals("Destroyer"))
			this.length=2;

		this.validity=false;
	}
	
	public void setName(String name) {
		this.name=name;
	}
}