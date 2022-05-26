import java.util.*;
import java.lang.Math;

public class Main {
    public static void main(String[] args) {
        Scanner cin = new Scanner(System.in);
        Triangle t;
        while (cin.hasNextDouble()) {
            t = new Triangle(cin.nextDouble(), cin.nextDouble(), cin.nextDouble());
            t.printInfoln();
        }
    }

}

class Triangle {
    double a, b, c;

    public Triangle(double A, double B, double C) {
        this.a = A;
        this.b = B;
        this.c = C;
    }

    public double getArea() {
        double p = (a + b + c) / 2;
        return Math.sqrt(p * (p - a) * (p - b) * (p - c));
    }

    public double getPerimeter() {
        return a + b + c;
    }

    public void printInfoln() {
        if (a <= 0 || b <= 0 || c <= 0) {
            System.out.println("The length of edge must be greater than 0!");
        } else if (a + b > c && a + c > b && b + c > a) {
            System.out.printf("area:%.2f perimeter:%.2f\n", getArea(), getPerimeter());
        } else {
            System.out.println("The Trilaterals cannot form a triangle.");
        }
    }

}
