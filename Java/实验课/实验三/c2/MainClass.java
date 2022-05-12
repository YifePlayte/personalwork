public class MainClass {
	public static void main(String[] args) {
		TV haierTV = new TV();
		haierTV.setChannel(5);
		System.out.println("haierTV的频道是" + haierTV.getChannel());
		Family zhangsanFamily = new Family();
		zhangsanFamily.buyTV(haierTV);
		System.out.println("zhangsanFamily开始看电视节目");
		zhangsanFamily.seeTV();
		int m = 2;
		System.out.println("zhangsanFamily将电视更换为" + m + "频道");
		zhangsanFamily.remoteControl(m);
		System.out.println("haierTV的频道是" + haierTV.getChannel());
		System.out.println("zhangsanFamily再看电视节目");
		zhangsanFamily.seeTV();
	}
	
}
