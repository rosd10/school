
public class File extends AbstractFile {
	private String text;
	
	public File(String name, int pos, int parent, String text){
		super(name, pos, parent);
		
		this.setText(text);
	}

	public void setText(String text) {
		this.text = text;
	}

	public String getText() {
		return this.text;
	}
}
