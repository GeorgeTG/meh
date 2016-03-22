#include <string.h>
#include <sys/stat.h>

void combine(char* destination, const char* path1, const char* path2) {
	if(path1 == NULL && path2 == NULL) {
		strcpy(destination, "");;
	}
	else if(path2 == NULL || strlen(path2) == 0) {
		strcpy(destination, path1);
	}
	else if(path1 == NULL || strlen(path1) == 0) {
		strcpy(destination, path2);
	}
	else {
		char directory_separator[] = "/";
#ifdef WIN32
		directory_separator[0] = '\\';
#endif
		const char *last_char = path1;
		while(*last_char != '\0')
			last_char++;
		int append_directory_separator = 0;
		if(strcmp(last_char-1, directory_separator) != 0) {
			append_directory_separator = 1;
		}
		strcpy(destination, path1);
		if(append_directory_separator)
			strcat(destination, directory_separator);
		strcat(destination, path2);
	}
}

int is_dir(char *path) {
	struct stat stat_buf;

	if ( stat(path, &stat_buf) != 0) {
		return 0;
	}

	return S_ISDIR(stat_buf.st_mode);
}

int is_file(char *path) {
	struct stat stat_buf;

	if ( lstat(path, &stat_buf) != 0) {
		return 0;
	}

	return S_ISREG(stat_buf.st_mode);
}


