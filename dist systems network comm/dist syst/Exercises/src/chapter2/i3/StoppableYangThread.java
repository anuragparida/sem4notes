package chapter2.i3;

public class StoppableYangThread implements Runnable {
	
	boolean stop = false;
	
	long waitingTime;

	@Override
	public void run() {
		while(!stop) {
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