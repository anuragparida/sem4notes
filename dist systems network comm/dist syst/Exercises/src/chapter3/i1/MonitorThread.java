package chapter3.i1;

public class MonitorThread implements Runnable {
	
	public static int counter = 0;	// class attribute

	protected Thread t;

	/**
	 * Creates a concurrent MonitorThread object.
	 */
	public MonitorThread() {
		t = new Thread(this);
		t.start();
	}

	@Override
	public void run() {
		for(int i = 0; i < 1000; i++) {
			criticalWork();			
		}
	}

	
	/**
	 * Increment static counter attribute 1000 times.
	 */
	public void criticalWork() {
		synchronized (getClass()) { // synchronization based on class!
			System.out.println(t.getName() + " doing critical work...");
			for(int i = 0; i < 1000; i++) {
				MonitorThread.counter++;
			}
			System.out.println(t.getName() + ": counter="+counter);
		}
	}

	public static void main(String[] args) {
		new MonitorThread();
		new MonitorThread();
	}
}