import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner cin = new Scanner(System.in);
		Shape s;
		Prism p;
		while (cin.hasNextInt()) {
			switch (cin.nextInt()) {
			case 0:
				s = new Circle(cin.nextDouble());
				break;
			case 1:
				s = new Triangle(cin.nextDouble(), cin.nextDouble(), cin.nextDouble());
				break;
			case 2:
				s = new Rectangle(cin.nextDouble(), cin.nextDouble());
				break;
			default:
				return;
			}
			p = new Prism(s, cin.nextDouble());
			System.out.printf("%.2f\n", p.getVolume());
		}
	}

}

abstract class Shape {
	abstract public double getArea();

}

class Circle extends Shape {
	double r;

	public Circle(double R) {
		this.r = R;
	}

	@Override
	public double getArea() {
		return Math.PI * Math.pow(this.r, 2);
	}

}

class Triangle extends Shape {
	double a, b, c;

	public Triangle(double A, double B, double C) {
		this.a = A;
		this.b = B;
		this.c = C;
	}

	@Override
	public double getArea() {
		if (a > 0 && b > 0 && c > 0 && a + b > c && a + c > b && b + c > a) {
			double p = (a + b + c) / 2;
			return Math.sqrt(p * (p - a) * (p - b) * (p - c));
		} else {
			return 0;
		}
	}

}

class Rectangle extends Shape {
	double a, b;

	public Rectangle(double A, double B) {
		this.a = A;
		this.b = B;
	}

	@Override
	public double getArea() {
		return a * b;
	}

}

class Prism {
	Shape s;
	double h;

	public Prism(Shape S, double H) {
		this.s = S;
		this.h = H;
	}

	public double getVolume() {
		return this.s.getArea() * h;
	}

}
