import java.lang.reflect.Method;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner cin = new Scanner(System.in);
        Object t;
        while (cin.hasNextInt()) {
            switch (cin.nextInt()) {
            case 1:
                t = new Point(cin.nextDouble(), cin.nextDouble());
                break;
            case 2:
                t = new Line(cin.nextDouble(), cin.nextDouble(), cin.nextDouble(), cin.nextDouble());
                break;
            case 3:
                t = new Circle(cin.nextDouble(), cin.nextDouble(), cin.nextDouble());
                break;
            case 4:
                t = new Triangle(cin.nextDouble(), cin.nextDouble(), cin.nextDouble(), cin.nextDouble(), cin.nextDouble(), cin.nextDouble());
                break;
            default:
                return;
            }
            try {
                Class<?> shape = t.getClass();
                Method move = shape.getDeclaredMethod("move", double.class, double.class);
                Method spin = shape.getDeclaredMethod("spin", Point.class, double.class);
                Method print = shape.getDeclaredMethod("print");
                switch (cin.nextInt()) {
                case 1:
                    print.invoke(move.invoke(t, cin.nextDouble(), cin.nextDouble()));
                    break;
                case 2:
                    Point o = new Point(cin.nextDouble(), cin.nextDouble());
                    print.invoke(spin.invoke(t, o, cin.nextDouble()));
                    break;
                }
                System.out.println();
            } catch (Exception e) {}
        }
    }

}

class Point {
    double x, y;

    public Point(double X, double Y) {
        x = X;
        y = Y;
    }

    public Point move(double dx, double dy) {
        return new Point(x + dx, y + dy);
    }

    public Point spin(Point p, double angle) {
        double dx = x - p.x;
        double dy = y - p.y;
        double ex = Math.cos(angle * Math.PI / 180) * dx - Math.sin(angle * Math.PI / 180) * dy;
        double ey = Math.cos(angle * Math.PI / 180) * dy + Math.sin(angle * Math.PI / 180) * dx;
        return new Point(p.x + ex, p.y + ey);
    }

    public void print() {
        System.out.printf("(%.2f,%.2f)", x, y);
    }

}

class Line {
    Point a, b;

    public Line(double ax, double ay, double bx, double by) {
        this.a = new Point(ax, ay);
        this.b = new Point(bx, by);
    }

    public Line(Point A, Point B) {
        this.a = A;
        this.b = B;
    }

    public Line move(double dx, double dy) {
        return new Line(this.a.move(dx, dy), this.b.move(dx, dy));
    }

    public Line spin(Point p, double angle) {
        return new Line(this.a.spin(p, angle), this.b.spin(p, angle));
    }

    public void print() {
        this.a.print();
        System.out.print("-");
        this.b.print();
    }

}

class Circle {
    Point o;
    double r;

    public Circle(double X, double Y, double R) {
        this.o = new Point(X, Y);
        this.r = R;
    }

    public Circle(Point O, double R) {
        this.o = O;
        this.r = R;
    }

    public Circle move(double dx, double dy) {
        return new Circle(this.o.move(dx, dy), this.r);
    }

    public Circle spin(Point p, double angle) {
        return new Circle(this.o.spin(p, angle), this.r);
    }

    public void print() {
        this.o.print();
        System.out.printf("Radius:%.2f", this.r);
    }

}

class Triangle {
    Point a, b, c;

    public Triangle(double ax, double ay, double bx, double by, double cx, double cy) {
        this.a = new Point(ax, ay);
        this.b = new Point(bx, by);
        this.c = new Point(cx, cy);
    }

    public Triangle(Point A, Point B, Point C) {
        this.a = A;
        this.b = B;
        this.c = C;
    }

    public Triangle move(double dx, double dy) {
        return new Triangle(this.a.move(dx, dy), this.b.move(dx, dy), this.c.move(dx, dy));
    }

    public Triangle spin(Point p, double angle) {
        return new Triangle(this.a.spin(p, angle), this.b.spin(p, angle), this.c.spin(p, angle));
    }

    public void print() {
        this.a.print();
        System.out.print("-");
        this.b.print();
        System.out.print("-");
        this.c.print();
    }

}
