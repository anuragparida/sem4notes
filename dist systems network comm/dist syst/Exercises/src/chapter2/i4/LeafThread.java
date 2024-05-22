package chapter2.i4;

public class LeafThread extends Thread {
	
	public LeafThread(String name) {
		this.setName(name);
	}
	
	@Override
	public void run() {
		Leaf[] leaves = new Leaf[10];
		for (int i = 0; i < leaves.length; i++) {
			System.out.println(getName() + ": creating leaf " + i );
			leaves[i] = new Leaf();
		}
	}
}