#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 10

typedef struct {
	char type; // 0=fried chicken, 1=French fries
	int amount; // pieces or weight
	char unit; // 0=piece, 1=gram
} item;

item buffer[BUFFER_SIZE];
int first = 0;
int last = 0;

void produce(item *i) {
	while ((first + 1) % BUFFER_SIZE == last) {
		// do nothing -- no free buffer item
	}
	memcpy(&buffer[first], i, sizeof(item));
	first = (first + 1) % BUFFER_SIZE;
}

item *consume() {
	item *i = malloc(sizeof(item));
	while (first == last) {
		// do nothing -- nothing to consume
	}
	memcpy(i, &buffer[last], sizeof(item));
	last = (last + 1) % BUFFER_SIZE;
	return i;
}

void fllog() {
	printf("First = %d; Last = %d\n\n", first, last);
}

int main() {
	printf("Initiating with:\n");
	fllog();

	item item1;
	item1.type = '0';
	item1.amount = 10;
	item1.unit = '0';

	item item2;
	item2.type = '1';
	item2.amount = 5;
	item2.unit = '1';

	printf("Producing item 1:\n\ttype: %c\n\tamount:%d\n\tunit:%c\n", item1.type, item1.amount, item1.unit);
	produce(&item1);
	fllog();

	printf("Producing item 2:\n\ttype: %c\n\tamount:%d\n\tunit:%c\n", item2.type, item2.amount, item2.unit);
	produce(&item2);
	fllog();

	printf("Consuming an item!\n");
	consume();
	fllog();
}