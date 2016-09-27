#include "Search_Data.h"

Search_Data::Search_Data()
{
}

Search_Data::~Search_Data()
{
}

int Search_Data::openDir_My(char* dirname, char* currentDirName, Grafo *G) {
	DIR *dr = NULL;
	struct dirent *drnt = NULL;
	char path[PATH_MAX + 2];
	char *p = path;
	const char *src;
	char *end = &path[PATH_MAX];
	int ok;
	wFile wF;

	src = dirname;
	while (p < end  &&  *src != '\0') {
		*p++ = *src++;
	}
	*p = '\0';

	dr = opendir(dirname);

	if (dr == NULL) {
		cout << "ERRO! Diretorio invalido" << endl;
		ok = 0;
		return ok;
	}

	while (drnt = readdir(dr)) {
		if (drnt == NULL) {
			cout << "ERROR! Diretorio nao abre corretamente" << endl;
			return 0;
		}

		if ((strcmp(drnt->d_name, ".") != 0) && (strcmp(drnt->d_name, "..") != 0)) {

			//cout << endl << childDir->d_name << endl;

			char *q = p;
			char c;

			/* Get final character of directory name */
			if (path < q) {
				c = q[-1];
			}
			else {
				c = ':';
			}

			/* Append directory separator if not already there */
			if (c != ':'  &&  c != '/'  &&  c != '\\') {
				*q++ = '/';
			}

			/* Append file name */
			src = drnt->d_name;
			while (q < end  &&  *src != '\0') {
				*q++ = *src++;
			}
			*q = '\0';

			if ((strcmp(currentDirName, "_sent_mail") == 0) || (strcmp(currentDirName, "sent")) == 0) {
				if (drnt->d_type == DT_REG) {
					//Files::openFile(path, grafo);
					cout << path << endl;
					wF.openFile(path, G);
				}
			}

			if (drnt->d_type == DT_DIR)
				openDir_My(path, drnt->d_name, G);
		}
	}

	closedir(dr);
	ok = 1;

	return ok;
}
