import java.util.*;

public class Main {
	public static void main(String[] args) {
		Scanner cin = new Scanner(System.in);
		int total, cont[], mode, pos;
		while (cin.hasNextInt()) {
			total = cin.nextInt();
			cont = new int[total + 1];
			for (int i = 0; i < total; i++) {
				cont[i] = cin.nextInt();
			}
			mode = cin.nextInt();
			pos = cin.nextInt();
			if (mode == 1) {
				for (int i = total; i > pos; i--) {
					cont[i] = cont[i - 1];
				}
				cont[pos] = cin.nextInt();
				total++;
			} else {
				for (int i = pos; i < total - 1; i++) {
					cont[i] = cont[i + 1];
				}
				total--;
			}
			for (int i = 0; i < total; i++) {
				if (i > 0)
					System.out.print(" ");
				System.out.print(cont[i]);
			}
			System.out.print("\n");
		}
	}
}
