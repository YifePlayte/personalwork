import java.util.Scanner;
import java.lang.Math;

public class Main {
    public static void main(String[] args) {
        Scanner cin = new Scanner(System.in);
        double a, b, c, p, s;
        while (cin.hasNextDouble()) {
            a = cin.nextDouble();
            b = cin.nextDouble();
            c = cin.nextDouble();
            p = (a + b + c) / 2;
            if (a > 0 && b > 0 && c > 0 && a + b > c && a + c > b && b + c > a) {
                s = Math.sqrt(p * (p - a) * (p - b) * (p - c));
                System.out.printf("%.2f\n", s);
            } else {
                System.out.println("not a triangle!");
            }
        }
    }
}
