package chapter3.i4;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

	public static void main(String[] args) throws NumberFormatException, IOException, InterruptedException {

		// read limits and number of threads from user
		BufferedReader keyboard = new BufferedReader(new InputStreamReader(System.in));
		System.out.print("Lower limit: ");
		int lowerLimit = Integer.parseInt(keyboard.readLine());
		System.out.print("Upper limit: ");
		int upperLimit = Integer.parseInt(keyboard.readLine());
		System.out.print("Number of threads: ");
		int numThreads = Integer.parseInt(keyboard.readLine());
		System.out.println();
		
		LoadBalancer lb = new LoadBalancer(lowerLimit, upperLimit, numThreads);
		lb.execute();
	}
}