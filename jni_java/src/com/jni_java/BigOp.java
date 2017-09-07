package com.jni_java;

import java.math.BigDecimal;

public class BigOp {
	public static String bigNumberAdd(String a, String b) {
		BigDecimal n1 = new BigDecimal(a);
		BigDecimal n2 = new BigDecimal(b);
		System.out.println("java call:" + a + "+" + b);
		return n1.add(n2).toString();

	}

}
