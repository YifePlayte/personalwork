import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner cin = new Scanner(System.in);
        while (cin.hasNext()) {
            String line = cin.nextLine();
            Scanner lineIn = new Scanner(line);
            Complex a = new Complex(lineIn.nextDouble(), lineIn.nextDouble());
            while (lineIn.hasNextInt()) {
                switch (lineIn.nextInt()) {
                    case 1:
                        a = a.add(new Complex(lineIn.nextDouble(), lineIn.nextDouble()));
                        break;
                    case 2:
                        a = a.minus(new Complex(lineIn.nextDouble(), lineIn.nextDouble()));
                        break;
                    case 3:
                        a = a.multiply(new Complex(lineIn.nextDouble(), lineIn.nextDouble()));
                        break;
                    case 4:
                        a = a.divide(new Complex(lineIn.nextDouble(), lineIn.nextDouble()));
                        break;
                }
            }
            a.print();
            System.out.println();
        }
    }
}

class Complex {
    double a, b;
    boolean valid;

    public Complex() {
        this(0, 0, true);
    }

    public Complex(double a, double b) {
        this(a, b, true);
    }

    public Complex(double a, double b, boolean valid) {
        this.a = a;
        this.b = b;
        this.valid = valid;
    }

    public Complex add(Complex B) {
        return new Complex(this.a + B.a, this.b + B.b, this.valid && B.valid);
    }

    public Complex minus(Complex B) {
        return new Complex(this.a - B.a, this.b - B.b, this.valid && B.valid);
    }

    public Complex multiply(Complex B) {
        return new Complex(this.a * B.a - this.b * B.b, this.a * B.b + this.b * B.a, this.valid && B.valid);
    }

    public Complex divide(Complex B) {
        if (B.a == 0 && B.b == 0) {
            return new Complex(0, 0, false);
        }
        double c = Math.pow(B.a, 2) + Math.pow(B.b, 2);
        return new Complex((this.a * B.a + this.b * B.b) / c, (this.b * B.a - this.a * B.b) / c, this.valid && B.valid);
    }

    public void print() {
        if (this.valid) {
            if (this.b < 0) {
                System.out.printf("(%.2f%.2fi)", this.a, this.b);
            } else {
                System.out.printf("(%.2f+%.2fi)", this.a, this.b);
            }
        } else {
            System.out.print("divied by 0!");
        }
    }
}
