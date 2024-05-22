package chapter4.i5;

import java.io.IOException;
import java.net.ServerSocket;
import java.net.Socket;

public class TcpEchoServer {

	private static final int PORT = 7777; // well-known port 7

	protected ServerSocket serverSocker;

	public TcpEchoServer() throws IOException {
		serverSocker = new ServerSocket(PORT);
	}

	public void startServer() throws IOException {
		// infinite loop
		while (true) {
			System.out.println("Waiting for connection on port " + PORT + "...");
			Socket connection = serverSocker.accept();
			System.out.println("...new connnection from " + connection.getRemoteSocketAddress());
			(new EchoThread(connection)).start();
		}
	}

	public static void main(String[] args) throws IOException {
		(new TcpEchoServer()).startServer();
	}
}