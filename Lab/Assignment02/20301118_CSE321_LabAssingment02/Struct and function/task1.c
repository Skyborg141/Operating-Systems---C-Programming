#include <stdio.h>

struct Item {
    int quantity;
    float price_per_unit;
};

int main() {
    struct Item food[3]; 
    int people_count;

    printf("Enter the quantity and price for each item.\n");

    printf("Paratha - Quantity: ");
    scanf("%d", &food[0].quantity);
    printf("Paratha - Price per unit: ");
    scanf("%f", &food[0].price_per_unit);

    printf("Vegetable - Quantity: ");
    scanf("%d", &food[1].quantity);
    printf("Vegetable - Price per unit: ");
    scanf("%f", &food[1].price_per_unit);

    printf("Mineral Water - Quantity: ");
    scanf("%d", &food[2].quantity);
    printf("Mineral Water - Price per unit: ");
    scanf("%f", &food[2].price_per_unit);

    printf("Enter the number of people: ");
    scanf("%d", &people_count);


    float total_cost = (food[0].quantity * food[0].price_per_unit) +
                       (food[1].quantity * food[1].price_per_unit) +
                       (food[2].quantity * food[2].price_per_unit);

    float per_person_cost = total_cost / people_count;

    printf("Each person needs to pay: %.2f tk\n", per_person_cost);

    return 0;
}
