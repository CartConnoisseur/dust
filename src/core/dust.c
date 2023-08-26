#define _GNU_SOURCE

#include <jni.h>
#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include <dlfcn.h>
#include "dust.h"
#include "log_internal.h"
#include "log.h"

JNIEnv* env = 0;
JavaVM* jvm = 0;
jint jni_version = 0;

void load_mod(char* filename) {
	logf_info("Loading native mod: %s", filename);

	char path[512];
	sprintf(path, "./dust/%s", filename);

	void* mod = dlopen(path, RTLD_LAZY);
	if (mod == NULL) {
		logf_error("Error loading native mod: %s", dlerror());
	}

	const char* (*init_mod)() = dlsym(mod, "init");

	logf_info("Successfully loaded native mod: %s (%s)", (*init_mod)(), filename);
}

void init(JNIEnv* _env, jobject this, jobject _logger, jstring mod_id) {
	env = _env;

	(*env)->GetJavaVM(env, &jvm);
	jni_version = (*env)->GetVersion(env);

	setup_logger(_logger);


	log_info("Successfully initialized Dust core");


	struct dirent *de;

	DIR* dr = opendir("./dust");
	while ((de = readdir(dr)) != NULL) {
		if (de->d_type == DT_REG && strcmp(de->d_name, "dust.so")) {
			load_mod(de->d_name);
		}
	}
	closedir(dr);
}

void init_client(JNIEnv* _env, jobject this) {
	// TODO: add init_client hook to mods.
	//			This requires keeping track of loaded
	//			 mods, which we currently do not do
}

Identifier create_identifier(char* namespace, char* path) {
	jclass identifier_class = (*env)->FindClass(env, "net/minecraft/util/Identifier");
	jmethodID constructor = (*env)->GetMethodID(env, identifier_class, "<init>", "(Ljava/lang/String;Ljava/lang/String;)V");
	
	return (*env)->NewObject(env, identifier_class, constructor, (*env)->NewStringUTF(env, namespace), (*env)->NewStringUTF(env, path));
}