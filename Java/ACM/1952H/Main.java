import java.util.*;

public class Main {
	public static void main(String[] args) {
		Scanner cin = new Scanner(System.in);
		Circle a, b;
		while (cin.hasNextDouble()) {
			a = new Circle(cin.nextDouble(), cin.nextDouble(), cin.nextDouble());
			b = new Circle(cin.nextDouble(), cin.nextDouble(), cin.nextDouble());
			System.out.println(a.posRelation(b));
		}
	}

	static class Circle {
		double x, y, r;
		public Circle() {
			this.x = 0;
			this.y = 0;
			this.r = 0;
		}
		public Circle(double X, double Y, double R) {
			this.x = X;
			this.y = Y;
			this.r = R;
		}
		public String posRelation(Circle B) {
			double dx = this.x - B.x;
			double dy = this.y - B.y;
			double d = Math.sqrt(Math.pow(dx, 2) + Math.pow(dy, 2));
			if (d > this.r + B.r) {
				return "SEPARATION";
			} else if (d < this.r + B.r) {
				return "INTERSECTION";
			} else {
				return "TANGENT";
			}
		}
	}
}