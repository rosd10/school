
public class Directory extends AbstractFile {
	private int[] children;
	private int numberOfChildren;
	
	public Directory(String name, int pos, int parent){
		super(name, pos, parent);
		
		this.children = new int[128];
		this.numberOfChildren = 0;
	}
	
	public int[] getChildren(){
		int[] temp = new int[this.numberOfChildren];
		
		System.arraycopy(this.children, 0, temp, 0, this.numberOfChildren);
		
		return temp;
	}
	
	public void addChildren(int pos){
		this.children[this.numberOfChildren] = pos;
		this.numberOfChildren++;
	}
	
	public void removeChildren(int pos){
		for(int i = 0; i < this.numberOfChildren; i++){
			if(this.children[i] == pos){
				this.children[i] = this.children[this.numberOfChildren - 1];
				this.numberOfChildren--;
			}
		}
	}
	
	public String getName(){
		return super.getName();
	}
	
	public void setName(String name){
		super.setName(name);
	}
}
