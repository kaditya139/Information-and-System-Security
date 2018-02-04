#include<stdio.h>
#include<stdlib.h>

void printStar(char l, int n) {
    int i;
    printf("%c : ", (l+'a'));
    for(i=0;i<n;i++)
        printf("*");
    printf("\n");
}

int main() {
	FILE *fp1, *fp2;
	fp1 = fopen("random.txt","r");
	fp2 = fopen("cipher.txt","w");
	int freqP[26], freqC[26], i;
	for(i=0;i<26;i++) {
		freqP[i] = 0;
		freqC[i] = 0;
	}
	char c;
	while((c=fgetc(fp1)) != EOF) {
		if(c >= 'a' && c <= 'z') {
			freqP[c-'a']++;
			if((int)(c+7) > 122)
				c = c-19;
            else
                c = c+7;
			fprintf(fp2, "%c", c);
			freqC[c-'a']++;
		}
	}
	for(i=0;i<26;i++) {
        printf("Plain\t");
        printStar(i, freqP[i]);
        printf("Cipher\t");
        printStar(i, freqC[i]);
	}
	return 0;
}
