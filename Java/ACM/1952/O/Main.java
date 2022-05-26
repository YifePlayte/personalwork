import java.util.*;

public class Main {
	public static void main(String[] args) {
		Scanner cin = new Scanner(System.in);
		Complex a, b;
		while (cin.hasNextDouble()) {
			a = new Complex(cin.nextDouble(), cin.nextDouble());
			b = new Complex(cin.nextDouble(), cin.nextDouble());
			a.add(b).print();
			a.minus(b).print();
			a.multiply(b).print();
			a.divide(b).print();
			System.out.print("\n");
		}
	}

	static class Complex {
		double a, b;
		boolean isDivByZero;

		public Complex() {
			this.a = 0;
			this.b = 0;
			this.isDivByZero = false;
		}

		public Complex(double A, double B) {
			this.a = A;
			this.b = B;
			this.isDivByZero = false;
		}

		public Complex(double A, double B, boolean IsDivByZero) {
			this.a = A;
			this.b = B;
			this.isDivByZero = IsDivByZero;
		}

		public Complex add(Complex B) {
			return new Complex(this.a + B.a, this.b + B.b);
		}

		public Complex minus(Complex B) {
			return new Complex(this.a - B.a, this.b - B.b);
		}

		public Complex multiply(Complex B) {
			return new Complex(this.a * B.a - this.b * B.b, this.a * B.b + this.b * B.a);
		}

		public Complex divide(Complex B) {
			if (B.a == 0 && B.b == 0)
				return new Complex(this.a, this.b, true);
			double c = Math.pow(B.a, 2) + Math.pow(B.b, 2);
			return new Complex((this.a * B.a + this.b * B.b) / c, (this.b * B.a - this.a * B.b) / c);
		}

		public void print() {
			if (this.isDivByZero)
				System.out.print("divied by 0!");
			else
				System.out.printf("(%.2f,%.2f)", this.a, this.b);
		}

	}

}
