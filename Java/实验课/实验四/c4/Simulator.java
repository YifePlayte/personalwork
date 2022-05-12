class Simulator {
	public void playSound(Animal animal) {
		System.out.print(animal.getAnimalName() + ": ");
		animal.cry();
		System.out.print("\n");
	}

}
