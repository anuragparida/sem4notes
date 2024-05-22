package chapter2.i3;

public class StoppableYungThread implements Runnable {
	
	boolean stop = false;
	
	long waitingTime;
	
	public StoppableYungThread() {
		Thread t = new Thread(this);
		t.start();
	}

	@Override
	public void run() {
		while(!stop) {
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