import java.util.*;


public class Main {
	private static final int ALLOW_IMBALANCE = 1;

	public static void main(String[] args) {
		//do something~
	}

	private static class AvlNode<T> {
		AvlNode(T theElement) {
			this(theElement, null, null);
		}

		AvlNode(T theElement, AvlNode<T> lt, AvlNode<T> rt) {
			this.element = theElement;
			left = lt;
			right = rt;
			height = 0;
		}

		T element;
		AvlNode<T> left;
		AvlNode<T> right;
		int height;
	}

	private <T> int height(AvlNode<T> t) {
		return t == null ? -1 : t.height;
	}

	private <T> AvlNode<T> insert(T x, AvlNode<T> t) {
		if (t == null) {
			return new AvlNode<T>(x, null, null);
		}

		int compareResult = ((String) x).compareTo((String) t.element);// 有误

		if (compareResult < 0) {
			t.left = insert(x, t.left);

		} else if (compareResult > 0) {
			t.right = insert(x, t.right);
		} else {

		}
		return balance(t);
	}

	private <T> AvlNode<T> balance(AvlNode<T> t) {
		if(t== null) {
			return t;
		}
		
		if(height(t.left) - height(t.right) > ALLOW_IMBALANCE) {
			if(height(t.left.left) >= height(t.left.right)) {
				t = rotateWithLeftChild(t);
			}else {
				t = dobleWithLeftChild(t);
			}
		}else if (height(t.right) - height(t.left) >ALLOW_IMBALANCE) {
			if(height(t.right.right) >= height(t.right.left)) {
				t=rotateWithRightChild(t);
			}else {
				t=dobleWithRightChild(t);
			}
			
		}
		return t;
	}


	private <T> AvlNode<T> dobleWithLeftChild(AvlNode<T> k3) {
		k3.left = rotateWithRightChild(k3.left);
		return rotateWithLeftChild(k3);
	}
	private <T> AvlNode<T> dobleWithRightChild(AvlNode<T> t) {
		
		return null;
	}

	private <T> AvlNode<T> rotateWithLeftChild(AvlNode<T> k2) {
		AvlNode<T> k1 = k2.left;
		k2.left = k1.right;
		k1.right = k2;
		k2.height = Math.max(height(k2.left), height(k2.right))+1;
		k1.height = Math.max(height(k1.left), k2.height)+1;
		return k1;
	}

	private <T>AvlNode<T> rotateWithRightChild(AvlNode<T> k2) {
		AvlNode<T> k1 = k2.right;
		k2.right = k1.left;
		k1.left = k2;
		k2.height = Math.max(height(k2.left), height(k2.right))+1;
		k1.height = Math.max(height(k1.right), k2.height)+1;
		return k1;
	}

}
