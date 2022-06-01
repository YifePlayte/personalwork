import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner cin = new Scanner(System.in);
		while (cin.hasNext()) {
			String a = cin.next();
			String b = cin.next();
			int i;
			for (i = 0; i < a.length() && i < b.length(); i++) {
				if (a.charAt(i) != b.charAt(i)) {
					break;
				}
			}
			if (i == 0) {
				System.out.println("no");
			} else {
				for (int j = 0; j < i; j++) {
					System.out.print(a.charAt(j));
				}
				System.out.println();
			}
		}
	}

}
