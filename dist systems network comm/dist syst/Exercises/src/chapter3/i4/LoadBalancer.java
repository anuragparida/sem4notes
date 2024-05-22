package chapter3.i4;

import java.util.Arrays;

public class LoadBalancer {
	
	protected int lowerLimit;
	protected int upperLimit;
	protected int numThreads;

	public LoadBalancer(int lowerLimit, int upperLimit, int numThreads) {
		this.lowerLimit = lowerLimit;
		this.upperLimit = upperLimit;
		this.numThreads = numThreads;
	}

	public void execute() throws InterruptedException {
		// workload per thread
		int numPerThread = (upperLimit - lowerLimit) / numThreads;

		// store number range in array
		int[] numbers = new int[upperLimit - lowerLimit + 1];
		for (int i = 0; i < numbers.length; i++) {
			numbers[i] = lowerLimit + i;
		}

		// create PrimeThread objects and distribute work
		PrimeThread[] workers = new PrimeThread[numThreads];
		for (int i = 0; i < numThreads; i++) {

			int[] temp;
			if (i == numThreads - 1) {
				// last thread consumes remaining numbers due to integer division
				temp = Arrays.copyOfRange(numbers, i * numPerThread, numbers.length - 1);
			} else {
				temp = Arrays.copyOfRange(numbers, i * numPerThread, (i + 1) * numPerThread);
			}

			System.out.println("Creating thread for " + temp[0] + "-" + temp[temp.length - 1] + ".");
			workers[i] = new PrimeThread(temp);
		}
		System.out.println();

		// start search concurrently
		for (PrimeThread thread : workers) {
			thread.start();
		}

		// wait for all worker threads to terminate
		for (PrimeThread thread : workers) {
			thread.join();
		}		
	}
}