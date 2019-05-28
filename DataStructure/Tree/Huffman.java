import java.util.*;

/*引用：http://rosettacode.org/wiki/Huffman_coding#Java*/

/*实现Comparable接口，重写compareTo*/
abstract class HuffmanTree implements Comparable<HuffmanTree>{
	public final int frequency;
	public HuffmanTree(int freq) {
		frequency = freq;
	}
	
	public int compareTo(HuffmanTree tree) {
		return frequency - tree.frequency;
	}
}

class HuffmanLeaf extends HuffmanTree{
	public final char value;
	
	public HuffmanLeaf(int freq,char val) {
		super(freq);
		value = val;
	}
}

class HuffmanNode extends HuffmanTree{
	public final HuffmanTree left,right;
	
	public HuffmanNode(HuffmanTree l, HuffmanTree r) {
		super(l.frequency + r.frequency);
		left =l;
		right =r;
	}
}

class HuffmanCode{
	
	public static HuffmanTree buildTree(int[] charFreqs) {
		/*优先队列*/
		PriorityQueue<HuffmanTree> trees =new PriorityQueue<HuffmanTree>();
		
		for(int i=0;i<charFreqs.length;i++) {
			if(charFreqs[i]>0) {
				trees.offer(new HuffmanLeaf(charFreqs[i],(char)i));
			}
		}
		
		assert trees.size()>0;
		
		while(trees.size() > 1) {
			HuffmanTree a =trees.poll();
			HuffmanTree b =trees.poll();
			
			trees.offer(new HuffmanNode(a,b));
		}
		
		
		return trees.poll();
	}
}



public class HufferMan {
	public static void main(String []args) {
		String test ="this is an example for huffman encoding";
		
		/*这里存的是频率*/
		int[] charFreqs = new int[256];
		for(char c:test.toCharArray()) {
			charFreqs[c]++;
		}
		
		HuffmanTree tree =HuffmanCode.buildTree(charFreqs);
		
		System.out.println("SYMBOL\tWEIGHT\tHUFFMAN CODE");
		printCodes(tree, new StringBuffer());	
	}

	private static void printCodes(HuffmanTree tree, StringBuffer prefix) {
		// TODO Auto-generated method stub
		assert tree!=null;
		if(tree instanceof HuffmanLeaf) {
			HuffmanLeaf leaf = (HuffmanLeaf) tree;
			System.out.println(leaf.value + "\t"+leaf.frequency+"\t"+prefix);
		}else if(tree instanceof HuffmanNode){
			HuffmanNode node =(HuffmanNode) tree;
			
			//traverse left
			prefix.append('0');
			printCodes(node.left, prefix);
			prefix.deleteCharAt(prefix.length()-1);
			
			//traverse right
			prefix.append('1');
			printCodes(node.right, prefix);
			prefix.deleteCharAt(prefix.length()-1);
			
		}
		
	}

}
