import java.io.*;

public class IOexample{
	public static void main(String args[]) throws IOException{
		FileInputStream in = null;
	    FileOutputStream out = null;

	    try{
	    	in = new FileInputStream("test.txt");
	    	out = new FileOutputStream("output.txt");
	    	int c;
	    	while((c=in.read()) != -1){
	    		out.write(c);
	    	}
	    }catch(Exception e){
	    	e.printStackTrace();
	    }
	    finally{
	    	if(in != null)
	    		in.close();
	    	if(out != null)
	    		out.close();
	    }
	}
}
