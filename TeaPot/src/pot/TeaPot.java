package pot;

//The object has been broken down to 5 main functions that work in pair with 
//the respective component of the tea pot. Data and actions are developed together.
//The tea pot has 4 components. 
//teaType is for fetching
//size is for stuffing tea into the pot.
//boilingWater is for filling the pot with boiled water.
//status is for waiting for the pot to finish brewing.

public class TeaPot {
	private String teaType;
	private int size;
	private Boolean boilingWater;
	private Boolean status;
	
	public TeaPot() {
		this.size = 3;
		this.teaType = "";
		this.boilingWater = false;
		this.status = false;
	}
	
	public void fetchTea(int option) {
		if(option == 1) this.teaType = "Green Tea";
		else this.teaType = "Black Tea";
		System.out.println("Fetching " + teaType);
	}
	
	public void pourSpoonTeaIntoPot() {
		if(this.size == 0) System.out.println("The pot is already filled with tea");
		else if(this.teaType.compareTo("") == 0) System.out.println("Fetch tea first");
		else {
			while(this.size > 0) {
				System.out.println("Putting a spoon of " + this.teaType + " into the pot.\n");
				this.size = this.size - 1;	
			}
		}
	}
	
	public void addBoilingWater() {
		if(this.size != 0) System.out.println("Put tea into the pot first.");
		else if(this.boilingWater == true) System.out.println("The pot is already filled with boiled water.");
		else {
			System.out.println("Adding boiling water.\n");
			this.boilingWater = true;
		}
	}
	
	public void brewing() {
		if(this.status == true) System.out.println("Tea is ready.");
		else if (this.boilingWater == false) System.out.println("Fill the pot with boiled water first.");
		else {
			System.out.println("Brewing tea. Waiting...");
			this.status = true;
		}
		
	}
}
