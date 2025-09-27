
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>

int main(void) {
	int gcd(int x , int y) {
		if(!y) {
			return x;
		}
		return gcd(y, x%y);
	}
	
	int gcd3(int x , int y , int z) {
		return gcd(gcd(x,y),z);
	}
	return 0;
}
