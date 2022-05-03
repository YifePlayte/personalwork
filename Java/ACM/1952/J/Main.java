import java.util.*;

public class Main {
	public static void main(String[] args) {
		Scanner cin = new Scanner(System.in);
		TaoTao taoTao;
		Chair chair;
		Apple apples[];
		int getNum;
		while(cin.hasNextInt()) {
			getNum = 0;
			taoTao = new TaoTao(cin.nextInt());
			chair = new Chair(cin.nextInt());
			apples = new Apple[10];
			for(int i = 0; i < 10; i++) {
				apples[i] = new Apple(cin.nextInt());
				if(taoTao.canGetApple(apples[i]))
					getNum++;
				else if (taoTao.canGetApple(apples[i], chair)) {
					getNum++;
				}
			}
			System.out.println(getNum);
		}
	}
}

class TaoTao {
	int height;
	public TaoTao() {
		height = 0;
	}
	public TaoTao(int h) {
		height = h;
	}
	public Boolean canGetApple(Apple a) {
		return a.getHeight() <= height;
	}
	public Boolean canGetApple(Apple a, Chair c) {
		return a.getHeight() <= (c.getHeight() + height);
	}
}

class Chair {
	int height;
	public Chair() {
		height = 0;
	}
	public Chair(int h) {
		height = h;
	}
	public int getHeight() {
		return height;
	}
}

class Apple {
	int height;
	public Apple() {
		height = 0;
	}
	public Apple(int h) {
		height = h;
	}
	public int getHeight() {
		return height;
	}
}