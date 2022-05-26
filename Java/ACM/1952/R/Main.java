import java.util.*;

public class Main {
	public static void main(String[] args) {
		Scanner cin = new Scanner(System.in);
		while (cin.hasNextLine()) {
			String str = cin.nextLine();
			char a = str.charAt(0);
			int f = 0, e = str.length() - 1;
			for (int i = 0; i < str.length(); i++) {
				if (str.charAt(i) == a) {
					f++;
				} else {
					break;
				}
			}
			for (int i = str.length() - 1; i >= 0; i--) {
				if (str.charAt(i) == a) {
					e--;
				} else {
					break;
				}
			}
			while (f < e) {
				if (str.charAt(f) == a) {
					str = str.substring(0, f).concat(str.substring(f + 1, str.length()));
					e--;
				} else {
					f++;
				}
			}
			System.out.println(str);
		}
	}

}
