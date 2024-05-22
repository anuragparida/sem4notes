package chapter4.i5;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.net.Socket;
import java.net.UnknownHostException;

public class TcpEchoClient {

	private static final String HOST = "localhost";
	private static final int PORT = 7777; // well-known port 7
	
	private static final String QUIT_CMD = "EXIT";

	protected BufferedReader keyboard;
	protected Socket socket;

	public TcpEchoClient() throws UnknownHostException, IOException {
		socket = new Socket(HOST, PORT);
		keyboard = new BufferedReader(new InputStreamReader(System.in));
	}

	public void startClient() throws IOException {
		String data = null;
		String echo = null;

		BufferedWriter socketOut = new BufferedWriter(new OutputStreamWriter(socket.getOutputStream()));
		BufferedReader socketIn = new BufferedReader(new InputStreamReader(socket.getInputStream()));

		// infinite loop
		while (true) {
			System.out.print("> ");
			data = keyboard.readLine();
			socketOut.write(data);
			socketOut.newLine();
			socketOut.flush();

			echo = socketIn.readLine();
			System.out.println(echo);

			if (echo.equals(QUIT_CMD)) {
				socket.close();
				break;
			}
		}
	}

	public static void main(String[] args) throws UnknownHostException, IOException {
		(new TcpEchoClient()).startClient();
	}
}