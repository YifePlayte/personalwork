import java.util.*;

public class Main {
	public static void main(String[] args) {
		Scanner cin = new Scanner(System.in);
		while (cin.hasNextInt()) {
			switch (cin.nextInt()) {
			case 3:
			case 4:
			case 5:
				Season.spring.printInfol();
				break;
			case 6:
			case 7:
			case 8:
				Season.summer.printInfol();
				break;
			case 9:
			case 10:
			case 11:
				Season.autumn.printInfol();
				break;
			case 12:
			case 1:
			case 2:
				Season.winter.printInfol();
				break;
			default:
				System.out.println("invalid month!");
			}
		}
	}

}

enum Season {
	spring{
		public void printInfol() {
			System.out.println("spring:Spring blossoms make you feel comfortable.");
		}
	},
	summer{
		public void printInfol() {
			System.out.println("summer:It's a little hot.");
		}
	},
	autumn{
		public void printInfol() {
			System.out.println("autumn:The autumn wind sweeps the fallen leaves and the weather turns cool.");
		}
	},
	winter{
		public void printInfol() {
			System.out.println("winter:It's too cold.");
		}
	};

	public abstract void printInfol();
}
