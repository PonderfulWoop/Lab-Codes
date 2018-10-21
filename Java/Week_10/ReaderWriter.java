import java.util.*;
import java.io.*;
import java.lang.*;

class ReaderWriter{
	public static void CopyPaste(FileReader fr, FileWriter fw) throws IOException{
		int i;
		while((i = fr.read()) != -1){
			fw.write((char)i);
		}
		fw.close();
		fr.close();
	}
	public static void main(String args[]) throws IOException{
		Scanner sc = new Scanner(System.in);
		String path = "/home/student/Shashank_178/Week_10/test.txt";

		FileReader fr = new FileReader(path);
		int i = path.lastIndexOf('/');
		path = path.substring(0, i+1);
		path = path + "output.txt";

		FileWriter fw = new FileWriter(path);

		CopyPaste(fr, fw);

	}
}