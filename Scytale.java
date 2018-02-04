package example;

import java.util.*;
import java.math.*;

public class Scytale {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter key :");
        int key = sc.nextInt();
        System.out.println("Enter plain text :");
        String text = sc.next();
        text = text + sc.nextLine();
        int length = text.length();
        
        int i, j;
        char[] encrypt = new char[length];
        int k = 0;
        for(i=0;i<key;i++) {
            for(j=i;j<length;j+=key) {
                encrypt[k++] = text.charAt(j);
            }
        }
        System.out.println("Encrypted Message are :");
        for(i=0;i<length;i++)
            System.out.print(encrypt[i]);
        System.out.println();
        
        int len = 0;
        if(length/key == 0)
            len = length/key;
        else
            len = length/key + 1;
        
        char[] decrypt = new char[length];
        char[][] string = new char[50][len];
        int remain = length % key;
        k = 0;
        outer:for(i=0;i<50;i++) {
            if(i<remain) {
                for(j=0;j<len;j++) {
                    string[i][j] = encrypt[k++];
                    if(k == length)
                        break outer;
                }
            }
            else {
                for(j=0;j<len-1;j++) {
                    string[i][j] = encrypt[k++];
                    if(k >= length)
                        break outer;
                }
            }
        }
        k = 0;
        outer:for(j=0;j<len;j++) {
            for(i=0;i<key;i++) {
                decrypt[k++] = string[i][j];
                if(k == length)
                    break outer;
            }
        }
        System.out.println("Decrypted Message are :");
        for(i=0;i<length;i++)
            System.out.print(decrypt[i]);
        System.out.println();
    }
}