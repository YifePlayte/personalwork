class Cat extends Animal {
	@Override
	public void cry() {
		System.out.print("Meow~~");
	}

	@Override
	public String getAnimalName() {
		return "Cat";
	}

}
