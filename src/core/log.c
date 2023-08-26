#include <jni.h>
#include <stdarg.h>
#include "env.h"

jobject logger;

jmethodID log_method_trace;
jmethodID log_method_debug;
jmethodID log_method_info;
jmethodID log_method_warn;
jmethodID log_method_error;
jmethodID log_method_fatal;

void setup_logger(jobject _logger) {
	logger = _logger;

	jclass logger_class = (*env)->GetObjectClass(env, logger);

	log_method_trace = (*env)->GetMethodID(env, logger_class, "trace", "(Ljava/lang/String;)V");
	log_method_debug = (*env)->GetMethodID(env, logger_class, "debug", "(Ljava/lang/String;)V");
	log_method_info  = (*env)->GetMethodID(env, logger_class, "info",  "(Ljava/lang/String;)V");
	log_method_warn  = (*env)->GetMethodID(env, logger_class, "warn",  "(Ljava/lang/String;)V");
	log_method_error = (*env)->GetMethodID(env, logger_class, "error", "(Ljava/lang/String;)V");
	log_method_fatal = (*env)->GetMethodID(env, logger_class, "fatal", "(Ljava/lang/String;)V");
}

void log_message(jmethodID method, char* message) {
	(*env)->CallVoidMethod(env, logger, method, (*env)->NewStringUTF(env, message));
}

void vlogf_message(jmethodID method, char* format, va_list args) {
	char buf[512];
	vsprintf(buf, format, args);

	log_message(method, buf);
}


void log_trace(char* message) {
	log_message(log_method_trace, message);
}
void log_debug(char* message) {
	log_message(log_method_debug, message);
}
void log_info(char* message) {
	log_message(log_method_info, message);
}
void log_warn(char* message) {
	log_message(log_method_warn, message);
}
void log_error(char* message) {
	log_message(log_method_error, message);
}
void log_fatal(char* message) {
	log_message(log_method_fatal, message);
}

void logf_trace(char* format, ...) {
	va_list args;
	va_start(args, format);

	vlogf_message(log_method_trace, format, args);

	va_end(args);
}
void logf_debug(char* format, ...) {
	va_list args;
	va_start(args, format);

	vlogf_message(log_method_debug, format, args);

	va_end(args);
}
void logf_info(char* format, ...) {
	va_list args;
	va_start(args, format);

	vlogf_message(log_method_info, format, args);

	va_end(args);
}
void logf_warn(char* format, ...) {
	va_list args;
	va_start(args, format);

	vlogf_message(log_method_warn, format, args);

	va_end(args);
}
void logf_error(char* format, ...) {
	va_list args;
	va_start(args, format);

	vlogf_message(log_method_error, format, args);

	va_end(args);
}
void logf_fatal(char* format, ...) {
	va_list args;
	va_start(args, format);

	vlogf_message(log_method_fatal, format, args);

	va_end(args);
}