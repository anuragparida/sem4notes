package chapter3.i2;

public class LeafThread extends Thread {
	
	public LeafThread(String name) {
		this.setName(name);
	}
	
	@Override
	public void run() {
		Leaf_v2[] leaves = new Leaf_v2[10000]; // increase number to make race condition visible
		for (int i = 0; i < leaves.length; i++) {
			System.out.println(getName() + ": creating leaf " + i );
			leaves[i] = new Leaf_v2();
		}
	}
}