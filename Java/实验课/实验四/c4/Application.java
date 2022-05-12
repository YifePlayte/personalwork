public class Application {
	public static void main(String[] args) {
		Animal cat = new Cat();
		Animal dog = new Dog();
		Simulator simulator = new Simulator();
		simulator.playSound(cat);
		simulator.playSound(dog);
	}

}
