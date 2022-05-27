#include <stdio.h> 

void my_print(const char* p, const int x){ 
	printf("p is \"%s\" and x is %d\n", p, x); 
}
int main(){
	printf("1.\n");
	printf("Hello, world!\n\n");

	printf("2.\n");
	char h[] = "Hello";
	char w[] = "World!";
	printf("%s %s\n\n", h, w); 

	printf("3.\n");
	my_print("foo",7);
	my_print("Kitti",10);
	my_print("Bármi Áron",13);

	return 0;

}
