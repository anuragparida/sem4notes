package chapter2.i2;

public class YungThread implements Runnable {
	
	long waitingTime;
	
	public YungThread() {
		Thread t = new Thread(this);
		t.start();
	}

	@Override
	public void run() {
		while(true) {
			System.out.println("Yung: " + waitingTime + " ms");
			try {
				long start = System.currentTimeMillis();
				Thread.sleep(900);
				long end = System.currentTimeMillis();
				waitingTime += (end - start);
			} catch (InterruptedException e) {
				e.printStackTrace();
			}
		}
	}
}