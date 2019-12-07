import java.util.*;
import java.io.*;
import java.lang.*;

class ReadFile{
	public static void printData(FileReader f) throws IOException{
		int i;
		int dig = 0;
		int let = 0;
		int lines = 0;
		int words = 0;
		int chars = 0;
		while((i = f.read()) != -1){
			char c = (char)i;
			if(Character.isDigit(c))
				dig++;
			else if(Character.isLetter(c))
				let++;
			else if(c == '\n' || c == '.')
				lines++;
			else if(c == ' ')
				words++;
			if(c != '\n' && c != ' ') chars++;

		}
		words+=2;
		lines++;
		System.out.println("Chars: " + chars);
		System.out.println("Words: " + words);
		System.out.println("Letters: " + let);
		System.out.println("Digits: " + dig);
		System.out.println("Lines: " + lines);
		f.close();
	}
	public static void main(String args[]){
		String path;
		path = "/home/student/Shashank_178/Week_10/test.txt";

		try{
			FileReader fr = new FileReader(path);
			printData(fr);
		}catch(IOException e){
			System.out.println("No such file");
			System.exit(0);
		}
	}
}