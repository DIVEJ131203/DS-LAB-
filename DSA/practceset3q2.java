import java.util.Scanner;

public class practceset3q2 {
    public static void main(String[] args) {
        System.out.println("Enter Temprature");
        Scanner sc = new Scanner(System.in);
        int temp = sc.nextInt();
        if (temp >= 98.6) {
            System.out.println("Fever");
        } else {
            System.out.println("Normal Temprature");
        }
        sc.close();
    }
}
