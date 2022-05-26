import java.util.*;

public class Main {
	public static void main(String[] args) {
		Scanner cin = new Scanner(System.in);
		Kids k;
		while (cin.hasNextInt()) {
			k = new Kids(cin.nextInt(), cin.nextInt());
			k.doGame();
		}
	}

}

class Kids {
	int num;
	int n;
	boolean[] isNotIn;

	public Kids(int Num, int N) {
		this.num = Num;
		this.n = N;
		this.isNotIn = new boolean[this.num];
	}

	void doGame() {
		int i = 0 % this.num;
		int l = 1 % this.n;
		int left = this.num;
		while (left != 1) {
			if (!this.isNotIn[i]) {
				if (l == 0) {
					this.isNotIn[i] = true;
					left--;
				}
				l = (l + 1) % this.n;
			}
			i = (i + 1) % this.num;
		}
		for (i = 0; i < this.num; i++) {
			if (!this.isNotIn[i]) {
				System.out.println(i + 1);
			}
		}
	}

}
