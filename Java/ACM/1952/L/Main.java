import java.util.*;

public class Main {
	public static void main(String[] args) {
		Scanner cin = new Scanner(System.in);
		ArrayList<EItem> eItems = new ArrayList<EItem>();
		EItem eItem = null;
		while (cin.hasNextInt()) {
			switch (cin.nextInt()) {
			case 1:
				eItem = new TV(cin.next());
				eItems.add(eItem);
				break;
			case 2:
				eItem = new WashMachine(cin.next());
				eItems.add(eItem);
				break;
			case 3:
				eItem = new Fridge(cin.next());
				eItems.add(eItem);
				break;
			case 4:
				eItem = new MicroWave(cin.next());
				eItems.add(eItem);
				break;
			default:
			}
		}
		for (int i = 0; i < eItems.size(); i++) {
			eItems.get(i).doSth();
		}
	}

}

abstract class EItem {
	public abstract void doSth();

}

class TV extends EItem {
	private String name;

	TV(String s) {
		name = s;
	}

	@Override
	public void doSth() {
		System.out.println(name + " is playing programs.");
	}

	void setName(String s) {
		name = s;
	}

}

class WashMachine extends EItem {
	private String name;

	WashMachine(String s) {
		name = s;
	}

	@Override
	public void doSth() {
		System.out.println(name + " is washing clothes.");
	}

	void setName(String s) {
		name = s;
	}

}

class Fridge extends EItem {
	private String name;

	Fridge(String s) {
		name = s;
	}

	@Override
	public void doSth() {
		System.out.println(name + " is cooling.");
	}

	void setName(String s) {
		name = s;
	}

}

class MicroWave extends EItem {
	private String name;

	MicroWave(String s) {
		name = s;
	}

	@Override
	public void doSth() {
		System.out.println(name + " is heating foods.");
	}

	void setName(String s) {
		name = s;
	}

}

