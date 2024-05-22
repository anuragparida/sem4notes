package chapter3.i4;

public class PrimeThread extends Thread {

	private int[] numbers;

	public PrimeThread(int[] numbers) {
		this.numbers = numbers;
	}

	@Override
	public void run() {
		for (int number : numbers) {
			checkPrime(number);
		}
	}

	public void checkPrime(int number) {
		for (int i = 2; i < number; i++) {
			if (number % i == 0) { // i divides number?
				System.out.println(Thread.currentThread().getName() + ": " + number + " is not prime.");
				return;
			}
		}
		System.out.println(Thread.currentThread().getName() + ": " + number + " is prime.");
	}
}