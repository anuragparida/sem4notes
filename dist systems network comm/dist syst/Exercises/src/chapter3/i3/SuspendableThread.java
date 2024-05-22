package chapter3.i3;

import java.util.concurrent.Semaphore;

public class SuspendableThread extends Thread {

	protected boolean isRunning; // flag to suspend thread
	protected Semaphore s; // signal on/off status
	protected int counter;

	public SuspendableThread() {
		this.isRunning = true;
		this.s = new Semaphore(1, true);
		this.counter = 0;
	}

	@Override
	public void run() {
		while (true) {
			try {
				s.acquire();
				System.err.println("RESUME!");
			} catch (InterruptedException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}

			while (isRunning) {
				counter++;
				System.out.println(counter);
			}
			System.err.println("SUSPENDED!");
		}
	}

	/**
	 * Toggle this thread (on/off) and notify all waiting threads.
	 */
	public void toogle() throws InterruptedException {
		isRunning = !isRunning;
		s.release();
	}

	public static void main(String[] args) throws InterruptedException {
		SuspendableThread st = new SuspendableThread();
		st.start();

		while (true) {
			Thread.sleep(2000); // 2 seconds
			st.toogle();
		}
	}
}