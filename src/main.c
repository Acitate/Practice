#include <stdio.h>

int main() {
	float age;
	int is_subscribed;
	puts("Enter your age: ");
	scanf("%f", &age);
	puts("Are you subscribed to the club?(1 for yes, 0 for no) ");
	scanf("%d", &is_subscribed);

	if (age <= 12) {
		puts("Price: 10\n");
	} else if (age >= 12 && age <= 18) {
		if (is_subscribed == 1) {
			puts("Price: 12");
		} else {
			puts("Price: 15");
		}
	} else if (age > 18 && age <= 60) {
		if (is_subscribed == 1) {
			puts("Price: 20");
		} else {
			puts("Price: 25");
		}
	} else if (age > 60) {
		puts("Price: 10");
	}
}