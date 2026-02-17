import java.util.Scanner;

class Welcome {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        System.out.print("Enter your name : ");
        String name = input.nextLine();
        System.out.print("Enter your year of birth : ");
        int birthYear = input.nextInt();
        int age = 2026 - birthYear;
        System.out.println("Welcome "+ name);
        System.out.println("Your age is : " + age);

    }
}