import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner cin = new Scanner(System.in);
        while (cin.hasNextInt()) {
            String line = cin.nextLine();
            Scanner lineIn = new Scanner(line);
            divnum a = new divnum(lineIn.nextInt(), lineIn.nextInt());
            while (lineIn.hasNextInt()) {
                switch (lineIn.nextInt()) {
                    case 1:
                        a = a.add(new divnum(lineIn.nextInt(), lineIn.nextInt()));
                        break;
                    case 2:
                        a = a.minus(new divnum(lineIn.nextInt(), lineIn.nextInt()));
                        break;
                    case 3:
                        a = a.multiply(new divnum(lineIn.nextInt(), lineIn.nextInt()));
                        break;
                    case 4:
                        a = a.divide(new divnum(lineIn.nextInt(), lineIn.nextInt()));
                        break;
                }
            }
            a.print();
            System.out.println();
        }
    }


}

class divnum {
    int a, b;
    boolean denominatorIsZero;
    boolean divisorIsZero;

    public divnum(int a, int b) {
        this(a, b, b == 0, false);
    }

    public divnum(int a, int b, boolean denominatorIsZero, boolean divisorIsZero) {
        this.a = a;
        this.b = b;
        this.denominatorIsZero = denominatorIsZero;
        this.divisorIsZero = divisorIsZero;
    }

    public static int gcd(int a, int b) {
        return b == 0 ? a : gcd(b, a % b);
    }

    public divnum add(divnum b) {
        return new divnum(
                this.a * b.b + this.b * b.a,
                this.b * b.b,
                this.denominatorIsZero || b.denominatorIsZero,
                this.divisorIsZero || b.denominatorIsZero).simplify();
    }

    public divnum minus(divnum b) {
        return new divnum(
                this.a * b.b - this.b * b.a,
                this.b * b.b,
                this.denominatorIsZero || b.denominatorIsZero,
                this.divisorIsZero || b.denominatorIsZero).simplify();
    }

    public divnum multiply(divnum b) {
        return new divnum(
                this.a * b.a,
                this.b * b.b,
                this.denominatorIsZero || b.denominatorIsZero,
                this.divisorIsZero || b.denominatorIsZero).simplify();
    }

    public divnum divide(divnum b) {
        return new divnum(
                this.a * b.b,
                this.b * b.a,
                this.denominatorIsZero || b.denominatorIsZero,
                this.divisorIsZero || b.denominatorIsZero || b.a == 0).simplify();
    }

    public divnum simplify() {
        int c = gcd(this.a, this.b);
        this.a = this.a / c;
        this.b = this.b / c;
        return this;
    }

    public void print() {
        simplify();
        if (this.denominatorIsZero) {
            System.out.print("The denominator cannot be zero！");
        } else if (this.divisorIsZero) {
            System.out.print("The divisor cannot be zero！");
        } else {
            System.out.printf("%d/%d", this.a, this.b);
        }
    }
}
