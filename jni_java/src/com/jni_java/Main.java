package com.jni_java;

public class Main {

	static native int add(int a, int b);

	static {
		System.loadLibrary("libjni_c");
	}

	public static void main(String[] args) {

		System.out.println("hello");
		System.out.println("add form c:" + add(2, 3));

	}

}
