import java.util.*;

public class Main {
	public static void main(String[] args) {
		Scanner cin = new Scanner(System.in);
		Student student = new Student();
		Bird bird = new Bird();
		Car car = new Car();
		while(cin.hasNext()) {
			switch(cin.next()) {
			case "Student":
				student.doSth();
				break;
			case "Bird":
				bird.doSth();
				break;
			case "Car":
				car.doSth();
				break;
			default:
			}
		}
	}

}

class Student implements DoSth {
	@Override
	public void doSth() {
		System.out.println("The student is studying!");
	}

}

class Bird implements DoSth {
	@Override
	public void doSth() {
		System.out.println("The bird is flying in air!");
	}

}

class Car implements DoSth {
	@Override
	public void doSth() {
		System.out.println("The car is running on the road!");
	}

}

interface DoSth {
	public void doSth();

}
