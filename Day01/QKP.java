package Day01;

import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;

class QKP {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	int NMAX = 1997;
	int a[][] = new int[NMAX][NMAX];
	int m, n;
	
	void solve()
	{
		int k, q, p, r, c, cnt = 0, tc = 1;
		while(true) {
			cnt = 0;
			n = ni();
			m = ni();
			if(n == 0 && m == 0) break;
			q = ni();
			for(int i = 0; i < q; i++) {
				r = ni();
				c = ni();
				a[r - 1][c - 1] = 2;
			}
			k = ni();
			for(int i = 0; i < k; i++) {
				r = ni();
				c = ni();
				a[r - 1][c - 1] = 3;
			}
	 
			p = ni();
			for(int i = 0; i < p; i++) {
				r = ni();
				c = ni();
				a[r - 1][c - 1] = 4;
			}
			for(int i = 0; i < n; i++)
				for(int j = 0; j < m; j++) {
					if(a[i][j] == 3) knight(i, j);
					else if(a[i][j] == 2) queen(i, j);
				}
			for(int i = 0; i < n; i++)
				for(int j = 0; j < m; j++) if(a[i][j] == 0) cnt++;
			out.println("Board " + ( tc++ ) + " has " + cnt + " safe squares.");
			for(int i = 0; i < n; i++)
				for(int j = 0; j < m; j++) a[i][j] = 0;
		}
	}
	
	void knight(int x, int y) {
		int i, j, k;
		i = x - 2;
		j = y - 1;
		k = y + 1;
		if(i >= 0) {
			if(j >= 0 && a[i][j] == 0) a[i][j] = 1;
			if(k < m && a[i][k] == 0) a[i][k] = 1;
		}
		i++;
		j--;
		k++;
		if(i >= 0) {
			if(j >= 0 && a[i][j] == 0) a[i][j] = 1;
			if(k < m && a[i][k] == 0) a[i][k] = 1;
		}
		i += 2;
		if(i < n) {
			if(j >= 0 && a[i][j] == 0) a[i][j] = 1;
			if(k < m && a[i][k] == 0) a[i][k] = 1;		
		}
		i++;
		j++;
		k--;
		if(i < n) {
			if(j >= 0 && a[i][j] == 0) a[i][j] = 1;
			if(k < m && a[i][k] == 0) a[i][k] = 1;
		}
	}
	 
	void queen(int x, int y) {
		int i, j;
		i = y - 1;
		j = x - 1;
		while(i >= 0 && (a[x][i] == 0 || a[x][i] == 1)) a[x][i--] = 1;
		while(j >= 0 && (a[j][y] == 0 || a[j][y] == 1)) a[j--][y] = 1;
		i = y + 1;
		j = x + 1;
		while(i < m && (a[x][i] == 0 || a[x][i] == 1)) a[x][i++] = 1;
		while(j < n && (a[j][y] == 0 || a[j][y] == 1)) a[j++][y] = 1;
		i = y + 1;
		j = x + 1;
		while((i < m && j < n) && (a[j][i] == 0 || a[j][i] == 1)) a[j++][i++] = 1;
		i = y - 1;
		j = x - 1;
		while((i >= 0 && j >= 0) && (a[j][i] == 0 || a[j][i] == 1)) a[j--][i--] = 1;
		i = y - 1;
		j = x + 1;
		while((i >= 0 && j < n) && (a[j][i] == 0 || a[j][i] == 1)) a[j++][i--] = 1;
		i = y + 1;
		j = x - 1;
		while((i < m && j >= 0) && (a[j][i] == 0 || a[j][i] == 1)) a[j--][i++] = 1;
	}
	
	void run() throws Exception
	{
		is = INPUT.isEmpty() ? System.in : new ByteArrayInputStream(INPUT.getBytes());
		out = new PrintWriter(System.out);
		
		long s = System.currentTimeMillis();
		solve();
		out.flush();
		if(!INPUT.isEmpty())tr(System.currentTimeMillis()-s+"ms");
	}
	
	public static void main(String[] args) throws Exception { new QKP().run(); }
	
	private byte[] inbuf = new byte[1024];
	private int lenbuf = 0, ptrbuf = 0;
	
	private int readByte()
	{
		if(lenbuf == -1)throw new InputMismatchException();
		if(ptrbuf >= lenbuf){
			ptrbuf = 0;
			try { lenbuf = is.read(inbuf); } catch (IOException e) { throw new InputMismatchException(); }
			if(lenbuf <= 0)return -1;
		}
		return inbuf[ptrbuf++];
	}
	
	private boolean isSpaceChar(int c) { return !(c >= 33 && c <= 126); }
	private int skip() { int b; while((b = readByte()) != -1 && isSpaceChar(b)); return b; }
	
	private double nd() { return Double.parseDouble(ns()); }
	private char nc() { return (char)skip(); }
	
	private String ns()
	{
		int b = skip();
		StringBuilder sb = new StringBuilder();
		while(!(isSpaceChar(b))){ // when nextLine, (isSpaceChar(b) && b != ' ')
			sb.appendCodePoint(b);
			b = readByte();
		}
		return sb.toString();
	}
	
	private char[] ns(int n)
	{
		char[] buf = new char[n];
		int b = skip(), p = 0;
		while(p < n && !(isSpaceChar(b))){
			buf[p++] = (char)b;
			b = readByte();
		}
		return n == p ? buf : Arrays.copyOf(buf, p);
	}
	
	private char[][] nm(int n, int m)
	{
		char[][] map = new char[n][];
		for(int i = 0;i < n;i++)map[i] = ns(m);
		return map;
	}
	
	private int[] na(int n)
	{
		int[] a = new int[n];
		for(int i = 0;i < n;i++)a[i] = ni();
		return a;
	}
	
	private int ni()
	{
		int num = 0, b;
		boolean minus = false;
		while((b = readByte()) != -1 && !((b >= '0' && b <= '9') || b == '-'));
		if(b == '-'){
			minus = true;
			b = readByte();
		}
		
		while(true){
			if(b >= '0' && b <= '9'){
				num = num * 10 + (b - '0');
			}else{
				return minus ? -num : num;
			}
			b = readByte();
		}
	}
	
	private long nl()
	{
		long num = 0;
		int b;
		boolean minus = false;
		while((b = readByte()) != -1 && !((b >= '0' && b <= '9') || b == '-'));
		if(b == '-'){
			minus = true;
			b = readByte();
		}
		
		while(true){
			if(b >= '0' && b <= '9'){
				num = num * 10 + (b - '0');
			}else{
				return minus ? -num : num;
			}
			b = readByte();
		}
	}
	
	private static void tr(Object... o) { System.out.println(Arrays.deepToString(o)); }
}
