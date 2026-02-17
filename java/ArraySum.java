import java.util.Scanner;

public class ArraySum {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        System.out.print("Enter the size of the array : ");
        int size = input.nextInt();
        int[] arr = new int[size];
        for(int i = 0 ; i < size ; i++) {
            System.out.printf("Enter the value arr[%d] : " , i);
            arr[i] = input.nextInt();
        }
        int sum = 0;
        for(int i = 0 ; i < size ; i++) {
            sum += arr[i];
        }
        System.out.printf("The sum of the array is %d \n" , sum);
    }
}
