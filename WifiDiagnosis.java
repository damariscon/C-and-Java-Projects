import java.util.Scanner;
public class WifiDiagnosis {
	public static void main(String [] args) {
		//Yes,no,ending variables
		Scanner keyboard=new Scanner(System.in);
		String userAnswer;
		String answerYes="Yes";
		String answerNo="No";
	    final String PROGRAMMER="Programmer: Damaris Constante";
	  //Ask user first question
	  		System.out.println("If you have a problem with internet connectivity, this WiFi diagnosis might work.");
	  		System.out.println("Reboot the computer and try to connect \nDid that fix the problem? (Yes or No)");
		userAnswer=keyboard.nextLine();//get user answer
		if (userAnswer.equalsIgnoreCase(answerYes)) {//user can input Yes or yes
			System.out.println("Done\n"+PROGRAMMER);		
		}
		else if(userAnswer.equalsIgnoreCase(answerNo)) { //Ask user second question if no
			System.out.println("Reboot the router and try to connect \nDid that fix the problem? (Yes or No)");
			userAnswer=keyboard.nextLine();//get user answer
			if(userAnswer.equalsIgnoreCase(answerYes)){
				System.out.println("Done\n"+PROGRAMMER);
			}
			else if(userAnswer.equalsIgnoreCase(answerNo)) {//Ask user third question if no
				System.out.println("Make sure the cables connecting the router are firmly plugged in and power"
						                    +" is getting to the router\nDid that fix the problem? (Yes or No)");
				userAnswer=keyboard.nextLine();//get user answer
				if(userAnswer.equalsIgnoreCase(answerYes)) {
					System.out.println("Done\n"+PROGRAMMER);
				}
				else if(userAnswer.equalsIgnoreCase(answerNo)) {//Ask user forth question if no
					System.out.println("Move the computer closer to the router and try to connect"
																				+"\nDid that fix the problem?");
					userAnswer=keyboard.nextLine();
					if(userAnswer.equalsIgnoreCase(answerYes)) {
						System.out.println("Done\n"+PROGRAMMER);
					}
					else if(userAnswer.equalsIgnoreCase(answerNo)) {//If answer if still no end program
						System.out.println("Contact your ISP");
						System.out.println("Done\n"+PROGRAMMER);
					}
					//if answer is anything else but yes or no display error message for each if statement and end program
					else {
						System.out.println("Invalid answer; Try again\n"+PROGRAMMER);
					}
				}
				else {
					System.out.println("Invalid answer; Try again\n"+PROGRAMMER); 
				}
			}
			else {
				System.out.println("Invalid answer; Try again\n"+PROGRAMMER);
			}
		}
		else{
			System.out.println("Invalid answer; Try again\n"+PROGRAMMER);
			}
		
	}

}