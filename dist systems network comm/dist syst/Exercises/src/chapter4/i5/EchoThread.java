package chapter4.i5;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.net.Socket;

public class EchoThread extends Thread {
	
	private static final String QUIT_CMD = "EXIT";

	protected Socket socket;

	public EchoThread(Socket socket) {
		this.socket = socket;
	}

	@Override
	public void run() {
		try {

			BufferedReader socketIn = new BufferedReader(new InputStreamReader(socket.getInputStream()));
			BufferedWriter socketOut = new BufferedWriter(new OutputStreamWriter(socket.getOutputStream()));

			String line = null;
			// infinite loop
			while (true) {
				line = socketIn.readLine();

				// send answer (echo)
				socketOut.write(line);
				socketOut.newLine();
				socketOut.flush();

				if (line.equals(QUIT_CMD)) {
					socket.close();
					break;
				}
			}
		} catch (IOException e) {
			e.printStackTrace();
		}
	}
}