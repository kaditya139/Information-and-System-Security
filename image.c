#include<stdio.h>
#include<string.h>
#include<math.h>

int main() {
	FILE *fp1 = fopen("lena.pgm", "r");
	FILE *fp2 = fopen("message.pgm", "w");
	char c, d;
	int length, width, max;
	fscanf(fp1, "%c", &c);
	fscanf(fp1, "%c", &d);
	fscanf(fp1, "%d", &length);
	fscanf(fp1, "%d", &width);
	fscanf(fp1, "%d", &max);
	fprintf(fp2, "%c%c\n%d  %d\n%d\n", c, d, length, width, max);

	int store[length][width];
	int i, j, k;
	for(i=0;i<length;i++) {
		for(j=0;j<width;j++) {
			fscanf(fp1, "%d", &store[i][j]);
		}
	}

	char message[100];
	printf("Type your secret message :\n");
	scanf("%[^\n]%c", message);
	int len = strlen(message);
	int l=0;
	i=0;j=0;
	for(k=0;k<len;k++) {
		int temp = (int)message[k];
		int arr[8];
		for(l=0;l<8;l++)
			arr[l] = 0;

        int z = 0;
		while(temp > 0) {
			arr[z++] = temp % 2;
			temp = temp / 2;
		}
		for(z=0;z<4;z++) {
            int temp1 = arr[z];
            arr[z] = arr[7-z];
            arr[7-z] = temp1;
		}

		for(l=0;l<8;l++) {
			if(arr[l] == 0 && store[i][j]%2 == 1) {
				store[i][j]--;
				j++;
			}
			else if(arr[l] == 1 && store[i][j]%2 == 0) {
				store[i][j]++;
				j++;
			}
			else {
				j++;
			}
			if(j == width) {
				j = 0; i++;
			}
		}
	}

	for(i=0;i<length;i++) {
		for(j=0;j<width;j++) {
			fprintf(fp2, "%d  ", store[i][j]);
		}
		fprintf(fp2, "\n");
	}

	printf("\nHidden message was :\n");
	int row = 0;
	for(i=0;i<len;i++) {
        int ascii = 0;
        for(j=0;j<8;j++) {
            int index = (i*8)+j;
            if(index == width)
                row++;
            index = index % width;
            int temp = store[row][index];
            int rem = temp % 2;
            ascii = ascii + rem * pow(2, (7-j));
        }
        printf("%c", ascii);
	}
	return 0;
}
