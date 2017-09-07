/*
 * main.c
 *
 *  Created on: 2017��9��4��
 *      Author: hanks
 */

#include <stdio.h>
#include "com_jni_java_Main.h"

JNIEXPORT jint JNICALL Java_com_jni_1java_Main_add(JNIEnv * env, jclass job,
		jint n1, jint n2) {

	jclass clazz = (*env)->FindClass(env, "com/jni_java/BigOp");
	if(clazz == NULL){
		printf("找不到类");
	}

	jmethodID mid_static_method =  (*env)->GetStaticMethodID(env, clazz, "bigNumberAdd", "(Ljava/lang/String;Ljava/lang/String;)Ljava/lang/String;");
	if (mid_static_method == NULL) {
		printf("找不到函数");
	}

	jstring a = (*env)->NewStringUTF(env, "111111111111111111111111111");
	jstring b = (*env)->NewStringUTF(env, "22222222222222222222222222");
	jobject res = (*env)->CallStaticObjectMethod(env, clazz, mid_static_method, a, b); // 3������clazz���callStaticMethod��̬����
    const char *resultChar = (*env)->GetStringUTFChars(env, res, NULL);
	printf("bigAdd: %s", resultChar);

	// 删除引用
	(*env)->DeleteLocalRef(env, clazz);
	(*env)->DeleteLocalRef(env, a);
	(*env)->DeleteLocalRef(env, b);

	return n1 + n2;
}
