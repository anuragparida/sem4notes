package chapter4.i3_i4;

import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.net.Socket;

public class TcpDaytimeClient {

	// modify for different server
	private static final String HOST = "localhost";
	private static final int PORT = 1313; // well-known port 13

	@SuppressWarnings("unused")
	private static final String LONG_FORMAT = "E. MMM d. yyyy HH:mm:ss-z";
	@SuppressWarnings("unused")
	private static final String SHORT_FORMAT = "HH:mm:ss";

	protected Socket socket;
	protected InputStream in;
	protected OutputStream out;

	public TcpDaytimeClient() throws IOException {
		socket = new Socket(HOST, PORT);
		in = socket.getInputStream();
		out = socket.getOutputStream();
	}

	public void startClient() throws IOException {
		// send format string
		out.write(LONG_FORMAT.getBytes());
		out.write("\n".getBytes());
		out.flush();

		// read daytime response
		int data = 0;
		StringBuffer daytime = new StringBuffer();
		while ((data = in.read()) != -1) {
			daytime.append((char) data);
		}
		System.out.println(daytime);
		// closing in- or output stream also closes the socket
		in.close();
	}

	public static void main(String[] args) throws IOException {
		(new TcpDaytimeClient()).startClient();
	}
}