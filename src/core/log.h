#pragma once

void log_trace(char* message);
void log_debug(char* message);
void log_info (char* message);
void log_warn (char* message);
void log_error(char* message);
void log_fatal(char* message);

void logf_trace(char* format, ...);
void logf_debug(char* format, ...);
void logf_info (char* format, ...);
void logf_warn (char* format, ...);
void logf_error(char* format, ...);
void logf_fatal(char* format, ...);