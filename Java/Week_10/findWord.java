import java.util.*;
import java.io.*;
import java.lang.*;

class findWord{
	public static boolean findKey(String s[], String key){
		for(String a : s)
			if(a.equals(key))
				return true;
		return false;
	}
	public static void find(FileReader f, String s) throws IOException{
		int i;
		int flag = 0;
		StringBuilder sb = new StringBuilder();
		String k;
		while((i = f.read()) != -1){
			k = Character.toString((char)i);
			sb.append(k);			
		}
		k = sb.toString();
		
		String temp[] = k.split("\n");
		int line = 0;
		for(String t : temp){
			line++;
			String temp2[] = t.split(" ");
			if(findKey(temp2, s)){
				System.out.println("[" + line + "] " + t);
				flag = 1;
			}
		}
		if(flag == 0)
			System.out.println("No Such word");
	}
	public static void main(String args[]) throws IOException{
		Scanner sc = new Scanner(System.in);
		String path = "/home/student/Shashank_178/Week_10/test.txt";

		FileReader f = new FileReader(path);

		System.out.println("Enter word to find");
		String key = sc.next();

		find(f, key);
	}
}