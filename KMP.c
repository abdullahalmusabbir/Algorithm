#include <stdio.h>
#include <string.h>

void search(const char* pat, const char* txt) {
    int m = strlen(pat);
    int n = strlen(txt);

    for (int i = 0; i <= n - m; i++) {
        int j = 0;

        while (j < m && txt[i + j] == pat[j]) {
            j++;
        }

        if (j == m) {
            printf("%d ", i);
        }
    }
}

int main() {
    const char txt[] = "aabaacaadaabaaba";
    const char pat[] = "aaba";

    search(pat, txt);

    return 0;
}
