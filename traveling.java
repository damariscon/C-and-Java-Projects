import java.util.Scanner;
public class Distance{
    public static void main(String[] args){
        int userSpeed;
        int travelTime;
        Scanner keyboard=new Scanner(System.in);
    
       
        	System.out.print("Enter vehicle speed (in mph): ");
            userSpeed=keyboard.nextInt();
            while(userSpeed<0){
                System.out.print("Enter vehicle speed (in mph): ");
                userSpeed=keyboard.nextInt();
            }
            System.out.print("Enter traveling time (in hours): ");
            travelTime=keyboard.nextInt();
            while(travelTime<1){
                System.out.print("Enter traveling time (in hours): ");
                travelTime=keyboard.nextInt();
            }    
            for (int count=1;count<=travelTime;count++) {
            	System.out.printf("After "+count+" hour(s) the distance is "+userSpeed*count+" miles.\n");
            }
    }
}
