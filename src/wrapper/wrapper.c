#include <jni.h>
#include <stdio.h>
#include <dlfcn.h>
#include "re_larimo_calvin_dust_Dust.h"
#include "re_larimo_calvin_dust_client_DustClient.h"

JNIEXPORT void JNICALL Java_re_larimo_calvin_dust_Dust_load(JNIEnv* env, jobject this, jobject logger, jobject core_logger, jstring mod_dir, jstring mod_id) {
	jclass logger_class = (*env)->GetObjectClass(env, logger);
	jmethodID log_info = (*env)->GetMethodID(env, logger_class, "info", "(Ljava/lang/String;)V");
	jmethodID log_error = (*env)->GetMethodID(env, logger_class, "error", "(Ljava/lang/String;)V");

	char buf[512];
	const char* dir = (*env)->GetStringUTFChars(env, mod_dir, JNI_FALSE);
	sprintf(buf, "%s/internal/core.so", dir);

	(*env)->CallVoidMethod(env, logger, log_info, (*env)->NewStringUTF(env, "Loading Dust core (internal/dust.so)"));

	void* core = dlopen(buf, RTLD_LAZY | RTLD_GLOBAL);
	if (core == NULL) {
		sprintf(buf, "Failed to load Dust core (\"internal/core.so\"): %s", dlerror());
		
		(*env)->CallVoidMethod(env, logger, log_error, (*env)->NewStringUTF(env, buf));
	}

	(*env)->CallVoidMethod(env, logger, log_info, (*env)->NewStringUTF(env, "Initializing Dust core"));
	void (*init)(JNIEnv*, jobject, jobject, jstring) = dlsym(core, "init");
	(*init)(env, this, core_logger, mod_id);
}

JNIEXPORT void JNICALL Java_re_larimo_calvin_dust_client_DustClient_load_1client(JNIEnv* env, jobject this) {
	void* core = dlopen(0, RTLD_LAZY | RTLD_GLOBAL);

	void (*init_client)(JNIEnv*, jobject) = dlsym(core, "init_client");
	(*init_client)(env, this);
}