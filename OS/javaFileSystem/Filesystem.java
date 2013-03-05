import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;

public class Filesystem {

	private AbstractFile[] array;
	private int pwd;

	public Filesystem() {
		this.array = new AbstractFile[128];
	}

	public String format() {

		// Delete old file hierarchy
		for (int i = 0; i < array.length; i++) {
			array[i] = null;
		}

		// Create new root directoryint i = 0;
		array[0] = new Directory("/", 0, 0);

		// Set pwd to root
		this.pwd = 0;

		return new String("Diskformat sucessfull");
	}

	public String ls(String[] p_asPath) {
		System.out.print("Listing directory ");

		Directory tempDir = (Directory) this.array[this.pwd];

		int[] temp = tempDir.getChildren();

		for (int i = 0; i < temp.length; i++) {
			System.out.print("\n" + this.array[temp[i]].getName());
		}

		return new String("");
	}

	public String create(String[] p_asPath, byte[] p_abContents) {
		System.out.print("Creating file ");

		String temp = new String(p_abContents);
		int currentPwd = this.pwd;

		for (int i = 0; i < p_asPath.length - 1; i++) {

			int[] tempChildren = ((Directory) this.array[currentPwd])
					.getChildren();

			for (int n = 0; n < tempChildren.length; n++) {
				if (this.array[tempChildren[n]].getName()
						.compareTo(p_asPath[i]) == 0) {
					currentPwd = tempChildren[n];
				}
			}
		}

		int i = 0;
		while (this.array[i] != null) {
			i++;
		}

		File file = new File(p_asPath[p_asPath.length - 1], i, currentPwd, temp);
		this.array[i] = file;
		((Directory) this.array[currentPwd]).addChildren(i);

		return new String("");
	}

	public String cat(String[] p_asPath) {
		System.out.print("Dumping contents of file \n");

		int currentPwd = this.pwd;

		for (int i = 0; i < p_asPath.length; i++) {
			int[] temp = ((Directory) this.array[currentPwd]).getChildren();

			for (int n = 0; n < temp.length; n++) {
				if (this.array[temp[n]].getName().compareTo(p_asPath[i]) == 0
						&& this.array[temp[n]] instanceof Directory) {
					currentPwd = temp[n];
				} else if (this.array[temp[n]].getName().compareTo(p_asPath[i]) == 0
						&& this.array[temp[n]] instanceof File) {
					System.out.println(((File) this.array[temp[n]]).getText());
				}
			}
		}

		return new String("");
	}

	public String save(String p_sPath) {
		System.out.print("Saving filesystem to file " + p_sPath);

		try {
			BufferedWriter out = new BufferedWriter(new FileWriter(p_sPath));

			int nrOfFiles = 0;

			while (this.array[nrOfFiles] != null) {
				nrOfFiles++;
			}

			out.write(nrOfFiles + "\n");

			for (int i = 0; i < nrOfFiles; i++) {
				if (this.array[i] instanceof Directory) {
					out.write("Directory\n");
					out.write(((Directory) this.array[i]).getName() + "\n");
					out.write(((Directory) this.array[i]).getParent() + "\n");
					out.write(((Directory) this.array[i]).getPos() + "\n");

					int[] temp = ((Directory) this.array[i]).getChildren();

					for (int n = 0; n < temp.length; n++) {
						out.write(temp[n] + " ");
					}
					out.write("\n");
				} else {
					out.write("File\n");
					out.write(((File) this.array[i]).getName() + "\n");
					out.write(((File) this.array[i]).getParent() + "\n");
					out.write(((File) this.array[i]).getPos() + "\n");
					out.write(((File) this.array[i]).getText() + "\n");
					out.write("EOF\n");

				}
			}

			out.close();

		} catch (IOException e) {
			e.printStackTrace();
		}

		return new String("");
	}

	public String read(String p_sPath) {
		System.out.print("Reading file " + p_sPath + " to filesystem");

		for (int i = 0; i < this.array.length; i++) {
			this.array[i] = null;
		}

		try {
			BufferedReader in = new BufferedReader(new FileReader(p_sPath));

			String temp = "";

			temp = in.readLine();

			int nrOfFiles = Integer.parseInt(temp);

			int i = 0;
			temp = in.readLine();
			while (temp != null) {

				if (temp.equals("Directory")) {
					String name = in.readLine();
					int parent = Integer.parseInt(in.readLine());
					int pos = Integer.parseInt(in.readLine());
					temp = in.readLine();

					String[] childrenString = temp.split(" ");
					int[] children = new int[childrenString.length];

					for (int n = 0; n < children.length; n++) {
						children[n] = Integer.parseInt(childrenString[n]);
					}

					this.array[i] = new Directory(name, pos, parent);
					for (int n = 0; n < children.length; n++) {
						((Directory) this.array[i]).addChildren(children[n]);
					}
					i++;
				} else {
					String name = in.readLine();
					int parent = Integer.parseInt(in.readLine());
					int pos = Integer.parseInt(in.readLine());
					String text = "";

					temp = in.readLine();
					while (!temp.equals("EOF")) {
						text = text.concat(temp);
						temp = in.readLine();
					}

					this.array[i] = new File(name, pos, parent, text);

					i++;
				}

				temp = in.readLine();
			}

			in.close();

		} catch (FileNotFoundException e) {
			e.printStackTrace();
		} catch (IOException e) {
			e.printStackTrace();
		}

		return new String("");
	}

	public String rm(String[] p_asPath) {
		System.out.print("Removing file ");

		int currentPwd = this.pwd;

		for (int i = 0; i < p_asPath.length; i++) {
			int[] children = ((Directory) this.array[currentPwd]).getChildren();

			for (int n = 0; n < children.length; n++) {
				if (this.array[children[n]].getName().compareTo(p_asPath[i]) == 0
						&& this.array[children[n]] instanceof Directory) {
					currentPwd = children[n];
				} else if (this.array[children[n]].getName().compareTo(
						p_asPath[i]) == 0
						&& this.array[children[n]] instanceof File) {
					((Directory) this.array[currentPwd])
							.removeChildren(children[n]);
				}
			}
		}

		return new String("");
	}

	public String copy(String[] p_asSource, String[] p_asDestination) {
		System.out.print("Copying file \n");

		int currentPwd = this.pwd;

		for (int i = 0; i < p_asSource.length; i++) {
			int[] tempChildren = ((Directory) this.array[currentPwd])
					.getChildren();

			for (int n = 0; n < tempChildren.length; n++) {
				if (this.array[tempChildren[n]].getName().compareTo(
						p_asSource[i]) == 0
						&& this.array[tempChildren[n]] instanceof Directory) {
					currentPwd = tempChildren[n];
				} else if (this.array[tempChildren[n]].getName().compareTo(
						p_asSource[i]) == 0
						&& this.array[tempChildren[n]] instanceof File) {
					this.create(p_asDestination,
							((File) this.array[tempChildren[n]]).getText()
									.getBytes());
				}
			}
		}

		return new String("");
	}

	public String append(String[] p_asSource, String[] p_asDestination) {
		System.out.print("Appending file ");

		int currentPwd = this.pwd;
		String textToAppend = "";

		for (int i = 0; i < p_asSource.length; i++) {
			for (int n = 0; n < ((Directory) array[currentPwd]).getChildren().length; n++) {
				int[] temp = ((Directory) array[currentPwd]).getChildren();
				if (this.array[temp[n]].getName().compareTo(p_asSource[i]) == 0
						&& this.array[temp[n]] instanceof Directory) {
					currentPwd = temp[n];
				} else if (this.array[temp[n]].getName().compareTo(
						p_asSource[i]) == 0
						&& this.array[temp[n]] instanceof File) {
						textToAppend = ((File)this.array[temp[n]]).getText();
				}
			}
		}
		
		currentPwd = this.pwd;
		
		for (int i = 0; i < p_asDestination.length; i++) {
			for (int n = 0; n < ((Directory) array[currentPwd]).getChildren().length; n++) {
				int[] temp = ((Directory) array[currentPwd]).getChildren();
				if (this.array[temp[n]].getName().compareTo(p_asDestination[i]) == 0
						&& this.array[temp[n]] instanceof Directory) {
					currentPwd = temp[n];
				} else if (this.array[temp[n]].getName().compareTo(
						p_asDestination[i]) == 0
						&& this.array[temp[n]] instanceof File) {
						String temp1 = ((File)this.array[temp[n]]).getText();
						textToAppend = textToAppend.concat(temp1);
						((File)this.array[temp[n]]).setText(textToAppend);
				}
			}
		}

		return new String("");
	}

	public String rename(String[] p_asSource, String[] p_asDestination) {
		System.out.print("Renaming file ");

		int currentPwd = this.pwd;

		for (int i = 0; i < p_asSource.length; i++) {

			boolean found = false;
			for (int n = 0; n < ((Directory) array[currentPwd]).getChildren().length
					&& !found; n++) {
				int[] temp = ((Directory) array[currentPwd]).getChildren();

				if (this.array[temp[n]].getName().compareTo(p_asSource[i]) == 0
						&& this.array[temp[n]] instanceof Directory) {
					currentPwd = temp[n];
					found = true;
				} else if (this.array[temp[n]].getName().compareTo(
						p_asSource[i]) == 0
						&& this.array[temp[n]] instanceof File) {
					this.array[temp[n]].setName(p_asDestination[0]);
					found = true;
				}
			}

		}

		return new String("");
	}

	public String mkdir(String[] p_asPath) {
		System.out.print("Creating directory ");

		int currentPwd = this.pwd;

		for (int i = 0; i < p_asPath.length; i++) {
			int n = 0;
			while (array[n] != null) {
				n++;
			}

			array[n] = new Directory(p_asPath[i], n, currentPwd);
			((Directory) array[currentPwd]).addChildren(n);

			currentPwd = n;
		}

		return new String("");
	}

	public String cd(String[] p_asPath) {
		System.out.print("Changing directory to ");
		int tempPwd = this.pwd;

		for (int i = 0; i < p_asPath.length; i++) {

			if (p_asPath[i].equals("..")) {
				tempPwd = this.array[tempPwd].getParent();
			} else if (p_asPath[i].equals(".")) {

			} else {
				int[] temp = ((Directory) this.array[tempPwd]).getChildren();

				for (int n = 0; n < temp.length; n++) {
					String tempString = this.array[temp[n]].getName();
					if (tempString.compareTo(p_asPath[i]) == 0) {
						tempPwd = temp[n];
					}
				}
			}

			this.pwd = tempPwd;
		}

		return this.array[this.pwd].getName();
	}

	public String pwd() {
		if (this.array[this.pwd] == null) {
			return "/unknown/";
		} else {
			return this.array[this.pwd].getName();
		}
	}

	private void dumpArray(String[] p_asArray) {
		for (int nIndex = 0; nIndex < p_asArray.length; nIndex++) {
			System.out.print(p_asArray[nIndex] + "=>");
		}
	}

}
