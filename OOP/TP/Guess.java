import java.util.Scanner;

public class Guess {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        System.out.print("Enter a random number between 1 and 100 and I will guess it : ");
        int num = input.nextInt();
        int low = 1;
        int high = 100;
        while(low <= high) {
            int guess = (high + low) / 2;
            
            
        }
    }
 }

