import java.util.Scanner;

public class practiceset1q2 {
    public static void main(String[] args) {
        System.out.println("Enter side of square");
        Scanner sc = new Scanner(System.in);
        int s = sc.nextInt();
        int area = s * s;
        System.out.println("Area:" + area);
        sc.close();
    }
}
