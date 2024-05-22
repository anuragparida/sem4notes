package chapter2.i2;

public class YinThread extends Thread {
	
	long waitingTime;
	
	@Override
	public void run() {
		while(true) {
			System.out.println("Yin: " + waitingTime + " ms");
			try {
				long start = System.currentTimeMillis();
				Thread.sleep(300);
				long end = System.currentTimeMillis();
				waitingTime += (end - start);
			} catch (InterruptedException e) {
				e.printStackTrace();
			}
		}
	}
}