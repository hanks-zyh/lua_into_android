package lua_java;

public class Main {

	native static void doFile(String file);

	static {
		System.loadLibrary("liblua_java_c");
	}

	public static void main(String[] args) {

		String file = "D:\\Program Files\\eclipse\\work\\eclipseWorkspace\\lua_java\\src\\a.lua";
		doFile(file);
	}
}
