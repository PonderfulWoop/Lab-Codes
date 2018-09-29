public class SingleLL<T>{
	private LinkedListNode<T> first = null;

	public void insert(LinkedListNode<T> node){
		node.setNext(first);
		first = node;
	}

	public void remove(){
		if(first.getNext()!=null)
			first = first.getNext();
		else first = null;
	}

	public void dispList(LinkedListNode<T> node){
		System.out.print(node.getValue()+"\t");
		if(node.getNext()!=null)
			dispList(node.getNext());
		else
			System.out.println();
	}

	public void print(){
		dispList(first);
	}

	public static void main(String args[]){
		Integer nums[] = {2,5,6,2,1,6};
		SingleLL<Integer> ob = new SingleLL<Integer>();
		for(int i = 0; i<nums.length; i++){
			ob.insert(new LinkedListNode<Integer>(nums[i]));
		}
		System.out.println("List: ");
		ob.print();
		System.out.println("List after removal: ");
		ob.remove();
		ob.print();
	}
}

class LinkedListNode<T> {
	private T value;
	private LinkedListNode<T> next;

	public LinkedListNode(T value) {
		this.value = value;
	}

	public void setNext(LinkedListNode<T> next) {
		this.next = next;
	}

	public LinkedListNode<T> getNext() {
		return next;
	}

	public T getValue() {
		return value;
	}
}