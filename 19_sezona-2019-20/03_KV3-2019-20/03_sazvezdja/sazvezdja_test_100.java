import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;



class Point {
	int x, y;

	public Point(int x, int y) {
		this.x = x;
		this.y = y;
	}
	
	@Override
	public String toString() {
		return x + " " + y;
	}
}


public class Sol_ok_1 {
	int n;
	List<Point> sol = new ArrayList<Point>();


	int l(int k) {
		return k * (k-1) * (k-2) / 6;
	}
	
	
	void solve() {
		int y = 0;
		int l1 = 0;
		int l2 = 0;
		int l0 = 0;
		
		while (n > 0) {
			int k = 3;
			while (l(k) <= n) {
				k++;
			}
			k--;
			
			for (int i = 0; i < k; i++) {
				sol.add(new Point(l0 + i, y));
			}
			n -= l(k);
			y++;
			
			l2 = l1;
			l1 = l0;
			l0 = y < 2 ? 0 : 2 * (l0+k-1) - l2 + 1; 
		}
	}
	
	
	void readInput() {
		try (Scanner in = new Scanner(System.in)) {
			n = in.nextInt();
		}
	}
	
	
	void writeOutput() {
		System.out.println(sol.size());
		sol.forEach(p -> System.out.println(p.toString()));
	}
	
	
	public Sol_ok_1() {
		readInput();
		solve();
		writeOutput();
	}


	public static void main(String[] args) {
		new Sol_ok_1();
	}
}
