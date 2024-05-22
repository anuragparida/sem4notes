package chapter2.i3;

public class StoppableYinThread extends Thread {
	
	boolean stop = false;
	
	long waitingTime;
	
	@Override
	public void run() {
		while(!stop) {
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