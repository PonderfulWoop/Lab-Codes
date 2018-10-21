import java.io.File;
import java.util.*;

class FileDir{
	static void getDir(File[] arr, int index, int level){
		if(index == arr.length){
			return;
		}
		for(int i = 0; i<level; i++){
			System.out.println("\t");
		}
		if(arr[index].isFile())
			System.out.println(arr[index].getName());
		else{
			System.out.println("[" + arr[index].getName()+ "]");
			getDir(arr[index].listFiles(), 0, level + 1);
		}
		getDir(arr, ++index, level);
	}
	public static void main(String args[]){
		Scanner sc = new Scanner(System.in);
		String path;

		path = "/home/student/Shashank_178/Week_10/";
		File f1 = new File(path);
		if(f1.exists() && f1.isDirectory()){
			File[] arr = f1.listFiles();

			getDir(arr, 0, 0);
		}

	}
}