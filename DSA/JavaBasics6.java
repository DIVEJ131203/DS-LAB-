import java.util.Scanner;

public class JavaBasics6 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter Radius");
        int radius = sc.nextInt();
        System.out.println(2 * 3.14 * radius);
        sc.close();
    }
}