import java.util.*;
import java.lang.Math;

public class Main {
	public static void main(String[] args) {
		Scanner cin = new Scanner(System.in);
		Point a, b;
		while (cin.hasNextDouble()) {
			a = new Point(cin.nextDouble(), cin.nextDouble());
			if (cin.nextInt() == 1) {
				a.pointMove(cin.nextDouble(), cin.nextDouble()).pointPrintln();
			} else {
				b = new Point(cin.nextDouble(), cin.nextDouble());
				a.pointSpin(b, cin.nextDouble() * Math.PI / 180).pointPrintln();
			}
		}
	}
}

class Point {
	double x, y;
	public Point() {
		x = 0;
		y = 0;
	}
	public Point(double X, double Y) {
		x = X;
		y = Y;
	}
	public Point pointMove(double dx, double dy) {
		return new Point(x + dx, y + dy);
	}
	public Point pointSpin(Point a, double b) {
		double dx = x - a.x;
		double dy = y - a.y;
		double ex = Math.cos(b) * dx - Math.sin(b) * dy;
		double ey = Math.cos(b) * dy + Math.sin(b) * dx;
		return new Point(a.x + ex, a.y + ey);
	}
	public void pointPrintln() {
		System.out.printf("(%.2f,%.2f)\n", x, y);
	}
}
