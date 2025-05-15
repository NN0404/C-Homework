#include <stdio.h>
#include <math.h>

#define MAX_CHAR 256 
int main(){
	
	char str[MAX_CHAR];
	
	puts("Enter: ");
	fgets(str, sizeof(str), stdin);
		
	size_t n = strlen (str);
	if (str[n - 1] == '\n') {
		str[n - 1] = '\0';
		n--;
	} 
	
	int start = 0;
	while (str[start] == ' ') {
		start++;
	}
	
	char *cleaned = (char *)malloc(n * sizeof(char));
	if (cleaned == NULL) {
		printf("FAILED");
		free(str);
		return 1;
	}
	
	int j = 0; int space_flag = 0;
	
	for (int i = start; i < n; i++) {
		if (str[i] != ' ') {
			cleaned[j++] = str[i];
			space_flag = 0;
		} else if (!space_flag) {
			cleaned[j++] = ' ';
			space_flag = 1;
		}
	}
	
	cleaned[j] = '\0';
	printf("%s", cleaned);
	
	free(str);
	free(cleaned);
	
	return 0;
}
