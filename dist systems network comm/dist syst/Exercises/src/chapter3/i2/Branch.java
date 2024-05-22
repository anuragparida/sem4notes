package chapter3.i2;

public class Branch {
	
	public static void main(String[] args) throws InterruptedException {
		LeafThread t1 = new LeafThread("LeafThread-1");
		LeafThread t2 = new LeafThread("LeafThread-2");
		LeafThread t3 = new LeafThread("LeafThread-3");
		
		System.out.println("Starting 3 LeafThreads.");
		t1.start();
		t2.start();
		t3.start();
		System.out.println();
		
		// CAUTION: waiting for the threads in the given sequence
		System.out.println("Waiting for completion...");
		t1.join();
		System.out.println(t1.getName() + " terminated.");
		t2.join();
		System.out.println(t1.getName() + " terminated.");
		t3.join();
		System.out.println(t1.getName() + " terminated.");

		System.out.println();
		System.out.println("All LeafThreads terminated.");
		System.out.println("Bye!");
	}
}