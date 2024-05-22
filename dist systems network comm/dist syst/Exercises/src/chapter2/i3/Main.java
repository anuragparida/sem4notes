package chapter2.i3;

public class Main {
	
	private static final int SLEEP_TIME_MILLIS = 5000; // 5 sec
	
	public static void main(String[] args) throws InterruptedException {
				
		StoppableYinThread yin = new StoppableYinThread();
		StoppableYangThread yang = new StoppableYangThread();
		StoppableYungThread yung = new StoppableYungThread();
		
		yin.start();
		Thread t = new Thread(yang);
		t.start();
		
		Thread.sleep(SLEEP_TIME_MILLIS);
		yin.stop = true;
		
		Thread.sleep(SLEEP_TIME_MILLIS);
		yang.stop = true;
		
		Thread.sleep(SLEEP_TIME_MILLIS);
		yung.stop = true;
			
	}
}