class PC {
	CPU cpu;
	HardDisk hd;

	void setCPU(CPU c) {
		cpu = c;
	}

	void setHardDisk(HardDisk h) {
		hd = h;
	}

	void show() {
		System.out.println("CPU speed: " + cpu.getSpeed());
		System.out.println("HardDisk amount: "+ hd.getAmount());
	}
	
}
