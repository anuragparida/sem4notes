package chapter3.i2;

public class Leaf_v2 {
	
	private static int counter = 0;
	
	public Leaf_v2() {
		synchronized (getClass()) { // synchronization for class attribute counter
			counter++;
			System.out.println("Number of leaves: " + counter);			
		}
	}
}
