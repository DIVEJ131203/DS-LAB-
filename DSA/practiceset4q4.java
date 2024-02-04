import java.util.Scanner;

public class practiceset4q4 {
    public static void main(String[] args) {
        System.out.println("Enter a number");
        Scanner s = new Scanner(System.in);
        int num = s.nextInt();
        int temp, sum = 0;
        while (num > 0) {
            temp = num % 10;
            sum = sum + temp;
            num /= 10;
        }
        System.out.println(sum);
        s.close();
    }
}
