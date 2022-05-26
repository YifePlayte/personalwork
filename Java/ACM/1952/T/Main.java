import java.util.*;

public class Main {
	public static void main(String[] args) {
		Scanner cin = new Scanner(System.in);
		while (cin.hasNextInt()) {
			int[] a, b;
			int num = 0;
			a = new int[10];
			for (int i = 0; i < 10; i++) {
				a[i] = cin.nextInt();
			}
			while (true) {
				boolean fin = true;
				for (int i = 0; i < 10; i++) {
					if (a[i] != a[(i + 1) % 10]) {
						fin = false;
						break;
					}
				}
				if (fin) {
					System.out.printf("%d %d\n", num, a[0]);
					break;
				} else {
					num++;
					for (int i = 0; i < 10; i++) {
						a[i] = a[i] / 2 + a[i] % 2;
					}
					b = a.clone();
					for (int i = 0; i < 10; i++) {
						a[i] += b[(i + 1) % 10];
					}
				}
			}
		}
	}

}
