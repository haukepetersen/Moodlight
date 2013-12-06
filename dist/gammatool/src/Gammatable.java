import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;


public class Gammatable {
	
	
	private int[] table = null;
	private int numOfValues = 0;
	private int maxValue = 0;
	private int numOfRows = 0;
	BufferedReader bufferRead = new BufferedReader(new InputStreamReader(System.in));
	
	
	public Gammatable() {
	}
	
	public void askParams() {
		String input;
		try{
			System.out.print("Number of Values: ");
			input = bufferRead.readLine();
			numOfValues = Integer.parseInt(input);
			System.out.print("Maximum Compare Value: ");
			input = bufferRead.readLine();
			maxValue = Integer.parseInt(input);
			System.out.print("Number of ouput lines: ");
			input = bufferRead.readLine();
			numOfRows = Integer.parseInt(input);
		}
		catch(IOException e)
		{
			e.printStackTrace();
		}
	}
	
	public void calculate() {
		table = new int[numOfValues + 1];
		for (int i = 0; i <= numOfValues; i++) {
			double max = maxValue;
			double quot = (double)i / numOfValues;
			double res = Math.pow(max, quot);
			table[i] = (int)Math.round(res);
		}
	}
	
	public void print() {
		int rowcount = 0;
		System.out.println("Results: ");
		for (int i = 0; i <= numOfValues; ) {

			String row = "\t";
			for (int j = 0; j < numOfRows && i <= numOfValues; j++) {
				row += "\t" + stuff(table[i++]) + ",";
			}
			System.out.println(row);
			rowcount++;
		}
		
		System.out.println("Generated a table with " + table.length + " entries. Rowcount: " + rowcount);
		System.out.println("Entry 1000: " + table[1000]);
		
	}
	
	
	private String stuff(int num) {
		String res = Integer.toString(num, 16);
		while (res.length() < 4) {
			res = "0" + res;
		}
		return "0x" + res;
	}
	
	
	public static void main(String[] args) {
		Gammatable gt = new Gammatable();
		gt.askParams();
		gt.calculate();
		gt.print();
	}
}
