package chapter4.i1_i2;

import java.net.Inet4Address;
import java.net.InetAddress;
import java.net.UnknownHostException;

public class NameAddressResolution {
	
	public static void main(String[] args) {
		
		if(args.length != 1 ) {
			System.err.println("Synposis: java -cp . chapter3.i1_i2.NameAddressResolution <ip-address|hostname>");
			System.exit(-1);
		}
		
		InetAddress[] ipAddresses = null;
		try {
			ipAddresses = InetAddress.getAllByName(args[0]);
		} catch (UnknownHostException e) {
			System.err.println("Resolution fails.");
			System.exit(-1);
		}
		
		for (int i = 0; i < ipAddresses.length; i++) {
			if(ipAddresses[i] instanceof Inet4Address) {
				System.out.println("IPv4 address: " + ipAddresses[i]);
			}
			else {
				System.out.println("IPv6 address: " + ipAddresses[i]);
			}
		}
	}
}