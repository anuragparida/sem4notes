package chapter2.i1;

public class Main {
	
	private static final int SLEEP_TIME_MILLIS = 500; // 0,5 sec
	
	public static void main(String[] args) throws InterruptedException {
		
		// Thread via inner class
		Thread t = new Thread() {
			
			@Override
			public void run() {
				while(true) {
					System.out.println("Yang");
					try {
						Thread.sleep(SLEEP_TIME_MILLIS); // 0,5 sec
					} catch (InterruptedException e) {
						e.printStackTrace();
					} 
				}
			}
		};
		
		t.start();
		
		while(true) {
			System.out.println("Yin");
			Thread.sleep(SLEEP_TIME_MILLIS); // 0,5 sec
		}	
	}
}