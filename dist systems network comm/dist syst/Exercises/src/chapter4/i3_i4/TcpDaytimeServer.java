package chapter4.i3_i4;

import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.net.ServerSocket;
import java.net.Socket;
import java.text.SimpleDateFormat;
import java.util.Date;

public class TcpDaytimeServer {
	
	// modify for different port usage
	private static final int PORT = 1313; // well-known port 13

	protected ServerSocket serverSocket;

	public TcpDaytimeServer() throws IOException {
		serverSocket = new ServerSocket(PORT);
	}

	public void startServer() throws IOException {
		while (true) {
			System.out.println("Waiting for connection on port " + PORT + "...");
			Socket connectionSocket = serverSocket.accept();
			System.out.println("New connection.");
			
			// read desired format
			InputStream in = connectionSocket.getInputStream();
			StringBuffer formatString = new StringBuffer();
			int data = -1;
			while ((char) (data = in.read()) != '\n') {
				formatString.append((char) data);
			}
			
			// create and send response
			SimpleDateFormat formatter = new SimpleDateFormat(formatString.toString());
			String daytime = formatter.format(new Date());
			OutputStream out = connectionSocket.getOutputStream();
			out.write(daytime.getBytes());
			out.flush();
			// closing in- or output stream also closes the socket
			out.close();
		}
	}

	public static void main(String[] args) throws IOException {
		(new TcpDaytimeServer()).startServer();
	}
}