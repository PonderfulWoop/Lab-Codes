import com.course.buildings.*;

import java.util.*;

public class Driver{
	public static void main(String arg[]){
		Scanner sc = new Scanner(System.in);
		System.out.println("Enter Square feet, Stories, Grade and Classrooms for the School: ");
		float sq = sc.nextFloat();
		int st = sc.nextInt();
		int g = sc.nextInt();
		int c = sc.nextInt();

		School school = new School();
		school.set(c, g, st, sq);
		school.get();


		System.out.println("Enter Square feet, Stories, beds and baths for the School: ");
		sq = sc.nextFloat();
		st = sc.nextInt();
		int bed = sc.nextInt();
		int bath = sc.nextInt();

		House house = new House();
		school.set(bed, bath, st, sq);
		school.get();
	}
}