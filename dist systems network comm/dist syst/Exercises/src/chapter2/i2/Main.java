package chapter2.i2;

public class Main {
	
	public static void main(String[] args) {
		(new YinThread()).start();
		(new Thread(new YangThread())).start();
		new YungThread();
	}
}