
public abstract class AbstractFile {
	private String name;
	private int pos;
	private int parent;
	
	public AbstractFile(){
		this.name = "";
		this.pos = -1;
		this.parent = -1;
	}
	
	public AbstractFile(String name, int pos, int parent){
		this.name = name;
		this.pos = pos;
		this.parent = parent;
	}
	
	public String getName(){
		return this.name;
	}
	
	public void setName(String name){
		this.name = name;
	}
	
	public int getPos(){
		return this.pos;
	}
	
	public int getParent(){
		return this.parent;
	}
	
	public void setParent(int parent){
		this.parent = parent;
	}
	
	public void setPos(int pos){
		this.pos = pos;
	}
}
