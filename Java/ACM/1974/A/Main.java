import java.util.*;

public class Main {
	public static void main(String[] args) {
		Scanner cin = new Scanner(System.in);
		Tri t;
		while (cin.hasNextInt()) {
			t = new Tri(cin.nextInt());
			t.print();
		}
	}

}

class Tri {
	int n;

	public Tri(int N) {
		this.n = N;
	}

	void print() {
		for (int i = 1; i <= this.n; i++) {
			for (int j = i; j > 0; j--) {
				System.out.printf("%4d", i + (2 * this.n - j) * (j - 1) / 2);
			}
			System.out.println();
		}

	}

}
