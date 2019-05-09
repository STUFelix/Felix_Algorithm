import java.util.*;

public class Main {
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		int N = scanner.nextInt();
		List<Integer> items = new ArrayList<Integer>();
		for (int i = 0; i < N; i++) {
			items.add(scanner.nextInt());
		}	
		items = quickSort(items);
		for (Iterator<Integer> iterator = items.iterator(); iterator.hasNext();) {
			Integer integer = (Integer) iterator.next();
			if(iterator.hasNext()) {
				System.out.print(integer+" ");
			}else {
				System.out.println(integer);
			}
		}
		scanner.close();
	}
	
	private static List<Integer> quickSort(List<Integer> items) {
		if(items.size()>1) {
			List<Integer> smaller = new ArrayList<Integer>();
			List<Integer> same = new ArrayList<Integer>();
			List<Integer> larger = new ArrayList<Integer>();
			Integer pivot = items.get(items.size()/2);
			for (Integer i : items) {
				if(i<pivot) {
					smaller.add(i);
				}else if(i>pivot){
					larger.add(i);
				}else {
					same.add(i);
				}
			}
			quickSort(smaller);
			quickSort(larger);
			
			items.clear();
			items.addAll(smaller);
			items.addAll(same);
			items.addAll(larger);
			
			return items;
		}else {
			return items;

		}
	}

}
