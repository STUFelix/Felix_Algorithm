import java.util.*;

/*
输入格式：
输入一共10行，每行一个长度为9的字符串。
输入表示这个棋盘，我们用'.'表示空位置，用'#'表示该位置有棋子，'S'表示初始的马的位置,用'T'表示马需要跳到的位置。（S，T应该保证只有一个）

输出格式：
能就输出一行"Yes"
不能就输出一行"No"
*/

public class chessDFS {
	static boolean flag = false ;
    static String str[] = new String[10];
    static boolean vis[][] = new boolean[10][10];
    static int dir[][] = {
    		{2,1},
    		{1,2},
    		{-1,2},
    		{2,-1},
    		{1,-2},
    		{-1,2},
    		{-1,-2},
    		{-2,-1},
    }; 
    
public static void main(String[] args){
        
        int x = 0;
        int y = 0;
        Scanner in = new Scanner(System.in);
        for(int i=0;i<10;i++){
        	str[i] = in.nextLine();
        }
        
        for(int i=0;i<10;i++) {
        	for(int j=0;j<9;j++) {
        		if(str[i].charAt(j)=='S') {
        			x=i;
        			y=j;
        		}
        	}
        }
        in.close();
        
        dfs(x,y);
        
        if(flag) {
        	System.out.println("Yes");
        }else {
        	System.out.println("No");
        }
        
    }
	private static void dfs(int x,int y) {
		vis[x][y] = true;
		if(flag) {
			return;
		}
		if(str[x].charAt(y)=='T') {
			flag = true;
			return ;
		}
		for(int i=0;i<8;i++) {
			int tx =x+dir[i][0];
			int ty =y+dir[i][1];
			if(inmap(tx,ty)&& str[tx].charAt(ty)!='#' &&!vis[tx][ty]) {
				dfs(tx,ty);
			}
		}
	
	}
	private static boolean inmap(int tx, int ty) {
		return 0<=tx&&tx<10&&0<=ty&&ty<9;
	}
	
}
