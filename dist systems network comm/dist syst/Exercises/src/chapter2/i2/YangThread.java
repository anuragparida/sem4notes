package chapter2.i2;

public class YangThread implements Runnable {
	
	long waitingTime;

	@Override
	public void run() {
		while(true) {
			System.out.println("Yang: " + waitingTime + " ms");
			try {
				long start = System.currentTimeMillis();
				Thread.sleep(600);
				long end = System.currentTimeMillis();
				waitingTime += (end - start);
			} catch (InterruptedException e) {
				e.printStackTrace();
			}
		}
	}
}