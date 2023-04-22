#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct passenger
{
    char name[20];
    char reg_no[10];
    int age;
    int seat_no;
    struct passenger*link;
};
struct coach
{
    int coach_no;
    int coach_class;
    int vacant_seats;
    struct passenger*pre;
    struct coach*next;
};
struct header
{
    char name[20];
    char reg_no[10];
    int cc_coaches;
    int ec_coaches;
    struct coach*link;
};
void add_passenger(struct header*head, struct coach*coach, int coach_no, int coach_class, int seat_no);
void print_passenger(struct header*head, struct coach*coach, int coach_no, int coach_class);
void delete_passenger(struct header*head, struct coach*coach, int coach_no, int coach_class, int seat_no);
void print_header(struct header *head);
void add_coach(struct header *head, int coach_class, int coach_no);

int main()
{
    struct header*head = NULL;
    int choice, coach_no, coach_class, age, seat_no;
    char name[20], reg_no[20];
    while (1)
    {
       printf("\n\n\n");
        printf("\n1. Create a new train\n");
        printf("2. Add a new coach\n");
        printf("3. Add a new passenger\n");
        printf("4. Print all passengers by age\n");
        printf("5. Print all coaches by age\n");
        printf("6. Print all passengers by registration number\n");
        printf("7. Print all coaches by registration number\n");
        printf("8. Print all passengers by seat number\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
           // head = create_new_train();
            break;
        case 2:
            printf("Enter the name of the train:\n ");
            scanf("%s", name);
            printf("Enter the registration number of the train: \n");
            scanf("%s", reg_no);
            printf("Enter the number of CC coaches: \n");
            scanf("%d", &coach_no);
            printf("Enter the number of EC coaches: ");
            scanf("%d", &coach_class);
           //add_new_coach(head, name, reg_no, coach_no, coach_class);
            break;
        case 3:
            printf("Enter the name of the passenger: ");
            scanf("%s", name);
            printf("Enter the registration number of the passenger: ");
            scanf("%s", reg_no);
            printf("Enter the age of the passenger: ");
            scanf("%d", &age);
            printf("Enter the coach number of the passenger: ");
            scanf("%d", &coach_no);
            printf("Enter the coach class of the passenger: ");
            scanf("%d", &coach_class);
            printf("Enter the seat number of the passenger: ");
        }
    }
}
/*struct node* create_new_train(struct header*head, struct coach*coach, int coach_no, int coach_class, int seat_no)
{
    struct passenger*new_passenger = (struct passenger*)malloc(sizeof(struct passenger));
    struct passenger*temp =coach->pre;
    new_passenger->seat_no = seat_no;
    printf("Enter name of passenger: ");
    scanf("%s", new_passenger->name);
    printf("Enter registration number of passenger: ");
    scanf("%s", new_passenger->reg_no);
    printf("Enter age of passenger: ");
    scanf("%d", &new_passenger->age);
    new_passenger->link = NULL;
return(new_passenger);
}*/
void add_passenger(struct header*head, struct coach*coach, int coach_no, int coach_class, int seat_no)
{
    struct passenger*new_passenger = (struct passenger*)malloc(sizeof(struct passenger));
    struct passenger*temp =coach->pre;
    new_passenger->seat_no = seat_no;
    printf("Enter name of passenger: ");
    scanf("%s", new_passenger->name);
    printf("Enter registration number of passenger: ");
    scanf("%s", new_passenger->reg_no);
    printf("Enter age of passenger: ");
    scanf("%d", &new_passenger->age);
    new_passenger->link = NULL;
    if (coach->pre==NULL)
    {
        coach->pre = new_passenger;
    }
    else
    {
        while (temp->link!=NULL)
        {
            temp=temp->link;
        }
        temp->link = new_passenger;
    }
    coach->vacant_seats--;
}
void print_passenger(struct header*head, struct coach*coach, int coach_no, int coach_class)
{
    struct passenger*temp = coach->pre;
    printf("\nCoach Number: %d\n", coach_no);
    printf("Coach Class: %d\n", coach_class);
    printf("Vacant Seats: %d\n", coach->vacant_seats);
    printf("Passenger Details:\n");
    while (temp!=NULL)
    {
        printf("Name: %s\n", temp->name);
        printf("Registration Number: %s\n", temp->reg_no);
        printf("Age: %d\n", temp->age);
        printf("Seat Number: %d\n", temp->seat_no);
        temp = temp->link;
    }
}
void delete_passenger(struct header*head, struct coach*coach, int coach_no, int coach_class, int seat_no)
{
    struct passenger*temp = coach->pre;
    struct passenger*prev = NULL;
    while (temp!=NULL)
    {
        if (temp->seat_no == seat_no)
        {
            if (prev==NULL)
            {
                coach->pre = temp->link;
            }
            else
            {
                prev->link = temp->link;
            }
            free(temp);
            coach->vacant_seats++;
            break;
        }
        prev = temp;
        temp = temp->link;
    }
}
void print_header(struct header *head)
{
    printf("\nName: %s\n", head->name);
    printf("Registration Number: %s\n", head->reg_no);
    printf("Number of CC Coaches: %d\n", head->cc_coaches);
    printf("Number of EC Coaches: %d\n", head->ec_coaches);
}
void print_coach(struct header *head, struct coach *coach, int coach_no, int coach_class)
{
    printf("\nCoach Number: %d\n", coach_no);
    printf("Coach Class: %d\n", coach_class);
    printf("Vacant Seats: %d\n", coach->vacant_seats);
    printf("Passenger Details:\n");
    struct passenger *temp = coach->pre;
    while (temp != NULL)
    {
        printf("Name: %s\n", temp->name);
        printf("Registration Number: %s\n", temp->reg_no);
        printf("Age: %d\n", temp->age);
        printf("Seat Number: %d\n", temp->seat_no);
        temp = temp->link;
    }
}
void add_coach(struct header *head, int coach_class, int coach_no)
{
    struct coach *new_coach = (struct coach *)malloc(sizeof(struct coach));
    new_coach->coach_no = coach_no;
    new_coach->coach_class = coach_class;
    new_coach->vacant_seats = coach_class * 10;
    new_coach->pre = NULL;
    new_coach->next = NULL;
    if (head->link == NULL)
    {
        head->link = new_coach;
    }
    else
    {
        struct coach*temp = head->link;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next=new_coach;
    }
    if (coach_class == 1)
    {
        head->cc_coaches++;
    }
    else
    {
        head->ec_coaches++;
    }
}
void delete_coach(struct header *head, int coach_class, int coach_no)
{
    struct coach*temp = head->link;
    struct coach*prev=NULL;
    while (temp != NULL)
    {
        if (temp->coach_no == coach_no)
        {
            if (prev == NULL)
            {
                head->link = temp->next;
            }
            else
            {
                prev->pre=temp->next;
            }
            free(temp);
            if (coach_class == 1)
            {
                head->cc_coaches--;
            }
            else
            {
                head->ec_coaches--;
            }
            break;
        }
        prev = temp;
        temp = temp->next;
    }
}
void print_all_passengers(struct header *head, struct coach *coach, int coach_no, int coach_class)
{
    struct passenger *temp = coach->pre;
    printf("\nCoach Number: %d\n", coach_no);
    printf("Coach Class: %d\n", coach_class);
    printf("Vacant Seats: %d\n", coach->vacant_seats);
    printf("Passenger Details:\n");
    while (temp != NULL)
    {
        printf("Name: %s\n", temp->name);
        printf("Registration Number: %s\n", temp->reg_no);
        printf("Age: %d\n", temp->age);
        printf("Seat Number: %d\n", temp->seat_no);
        temp = temp->link;
    }
}
void print_all_coaches(struct header *head)
{
    struct coach*temp = head->link;
    printf("\nName: %s\n", head->name);
    printf("Registration Number: %s\n", head->reg_no);
    printf("Number of CC Coaches: %d\n", head->cc_coaches);
    printf("Number of EC Coaches: %d\n", head->ec_coaches);
    while (temp!=NULL)
    {
        printf("\nCoach Number: %d\n", temp->coach_no);
        printf("Coach Class: %d\n", temp->coach_class);
        printf("Vacant Seats: %d\n", temp->vacant_seats);
        printf("Passenger Details:\n");
        struct passenger*temp1;
        temp1=temp->next;
        while (temp1->link!=NULL)
        {
            printf("Name: %s\n", temp1->name);
            printf("Registration Number: %s\n", temp1->reg_no);
            printf("Age: %d\n", temp1->age);
            printf("Seat Number: %d\n", temp1->seat_no);
            temp1=temp1->link;
        }
        temp=temp->next;
    }
}
void print_all_passengers_by_age(struct header *head, struct coach *coach, int coach_no, int coach_class)
{
    struct passenger*temp = coach->pre;
    printf("\nCoach Number: %d\n", coach_no);
    printf("Coach Class: %d\n", coach_class);
    printf("Vacant Seats: %d\n", coach->vacant_seats);
    printf("Passenger Details:\n");
    while (temp != NULL)
    {
        printf("Name: %s\n", temp->name);
        printf("Registration Number: %s\n", temp->reg_no);
        printf("Age: %d\n", temp->age);
        printf("Seat Number: %d\n",temp->seat_no);
        temp = temp->link;
    }
}
void print_all_coaches_by_age(struct header *head)
{
    struct coach*temp = head->link;
    printf("\nName: %s\n", head->name);
    printf("Registration Number: %s\n", head->reg_no);
    printf("Number of CC Coaches: %d\n", head->cc_coaches);
    printf("Number of EC Coaches: %d\n", head->ec_coaches);
    while (temp != NULL)
    {
        printf("\nCoach Number: %d\n", temp->coach_no);
        printf("Coach Class: %d\n", temp->coach_class);
        printf("Vacant Seats: %d\n", temp->vacant_seats);
        printf("Passenger Details:\n");
        struct passenger *temp1 = temp->pre;
        while (temp1 != NULL)
        {
            printf("Name: %s\n", temp1->name);
            printf("Registration Number: %s\n", temp1->reg_no);
            printf("Age: %d\n", temp1->age);
            printf("Seat Number: %d\n", temp1->seat_no);
            temp1 = temp1->link;
        }
        temp = temp->next;
    }
}
void print_all_passengers_by_seat(struct header *head, struct coach *coach, int coach_no, int coach_class)
{
    struct passenger*temp = coach->pre;
    printf("\nCoach Number: %d\n", coach_no);
    printf("Coach Class: %d\n", coach_class);
    printf("Vacant Seats: %d\n", coach->vacant_seats);
    printf("Passenger Details:\n");
    while (temp != NULL)
    {
        printf("Name: %s\n", temp->name);
        printf("Registration Number: %s\n", temp->reg_no);
        printf("Age: %d\n", temp->age);
        printf("Seat Number: %d\n", temp->seat_no);
        temp = temp->link;
    }
}
void print_all_coaches_by_seat(struct header *head)
{
    struct coach *temp = head->link;
    printf("\nName: %s\n", head->name);
    printf("Registration Number: %s\n", head->reg_no);
    printf("Number of CC Coaches: %d\n", head->cc_coaches);
    printf("Number of EC Coaches: %d\n", head->ec_coaches);
    while (temp != NULL)
    {
        printf("\nCoach Number: %d\n", temp->coach_no);
        printf("Coach Class: %d\n", temp->coach_class);
        printf("Vacant Seats: %d\n", temp->vacant_seats);
        printf("Passenger Details:\n");
        struct passenger *temp1 = temp->pre;
        while (temp1 != NULL)
        {
            printf("Name: %s\n", temp1->name);
            printf("Registration Number: %s\n", temp1->reg_no);
            printf("Age: %d\n", temp1->age);
            printf("Seat Number: %d\n", temp1->seat_no);
            temp1 = temp1->link;
        }
        temp = temp->next;
    }
}
void print_all_passengers_by_name(struct header *head, struct coach *coach, int coach_no, int coach_class)
{
    struct passenger *temp = coach->pre;
    printf("\nCoach Number: %d\n", coach_no);
    printf("Coach Class: %d\n", coach_class);
    printf("Vacant Seats: %d\n", coach->vacant_seats);
    printf("Passenger Details:\n");
    while (temp != NULL)
    {
        printf("Name: %s\n", temp->name);
        printf("Registration Number: %s\n", temp->reg_no);
        printf("Age: %d\n", temp->age);
        printf("Seat Number: %d\n", temp->seat_no);
        temp = temp->link;
    }
}
void print_all_coaches_by_name(struct header *head)
{
    struct coach *temp = head->link;
    printf("\nName: %s\n", head->name);
    printf("Registration Number: %s\n", head->reg_no);
    printf("Number of CC Coaches: %d\n", head->cc_coaches);
    printf("Number of EC Coaches: %d\n", head->ec_coaches);
    while (temp != NULL)
    {
        printf("\nCoach Number: %d\n", temp->coach_no);
        printf("Coach Class: %d\n", temp->coach_class);
        printf("Vacant Seats: %d\n", temp->vacant_seats);
        printf("Passenger Details:\n");
        struct passenger *temp1;
        temp1= temp->pre;
        while (temp1 != NULL)
        {
            printf("Name: %s\n", temp1->name);
            printf("Registration Number: %s\n", temp1->reg_no);
            printf("Age: %d\n", temp1->age);
            printf("Seat Number: %d\n", temp1->seat_no);
            temp1 = temp1->link;
        }
        temp = temp->next;
    }
}
/*void print_all_passengers_by_age(struct header*head, struct coach*coach, int coach_no, int coach_class)
{
    struct passenger*temp = coach->pre;
    printf("\nCoach Number: %d\n", coach_no);
    printf("Coach Class: %d\n", coach_class);
    printf("Vacant Seats: %d\n", coach->vacant_seats);
    printf("Passenger Details:\n");
    while (temp != NULL)
    {
        printf("Name: %s\n", temp->name);
        printf("Registration Number: %s\n", temp->reg_no);
        printf("Age: %d\n", temp->age);
        printf("Seat Number: %d\n", temp->seat_no);
        temp = temp->link;
    }
}
void print_all_coaches_by_age(struct header*head)
{
    struct coach*temp = head->link;
    printf("\nName: %s\n", head->name);
    printf("Registration Number: %s\n", head->reg_no);
    printf("Number of CC Coaches: %d\n", head->cc_coaches);
    printf("Number of EC Coaches: %d\n", head->ec_coaches);
    while (temp != NULL)
    {
        printf("\nCoach Number: %d\n", temp->coach_no);
        printf("Coach Class: %d\n", temp->coach_class);
        printf("Vacant Seats: %d\n", temp->vacant_seats);
        printf("Passenger Details:\n");
        struct passenger *temp1 = temp->pre;
        while (temp1 != NULL)
        {
            printf("Name: %s\n", temp1->name);
            printf("Registration Number: %s\n", temp1->reg_no);
            printf("Age: %d\n", temp1->age);
            printf("Seat Number: %d\n", temp1->seat_no);
            temp1 = temp1->link;
        }
        temp = temp->next;
    }
}*/
void print_all_passengers_by_reg_no(struct header *head, struct coach *coach, int coach_no, int coach_class)
{
    struct passenger *temp = coach->pre;
    printf("\nCoach Number: %d\n", coach_no);
    printf("Coach Class: %d\n", coach_class);
    printf("Vacant Seats: %d\n", coach->vacant_seats);
    printf("Passenger Details:\n");
    while (temp != NULL)
    {
        printf("Name: %s\n", temp->name);
        printf("Registration Number: %s\n", temp->reg_no);
        printf("Age: %d\n", temp->age);
        printf("Seat Number: %d\n", temp->seat_no);
        temp = temp->link;
    }
}
void print_all_coaches_by_reg_no(struct header *head)
{
    struct coach *temp = head->link;
    printf("\nName: %s\n", head->name);
    printf("Registration Number: %s\n", head->reg_no);
    printf("Number of CC Coaches: %d\n", head->cc_coaches);
    printf("Number of EC Coaches: %d\n", head->ec_coaches);
    while (temp != NULL)
    {
        printf("\nCoach Number: %d\n", temp->coach_no);
        printf("Coach Class: %d\n", temp->coach_class);
        printf("Vacant Seats: %d\n", temp->vacant_seats);
        printf("Passenger Details:\n");
        struct passenger *temp1 = temp->pre;
        while (temp1 != NULL)
        {
            printf("Name: %s\n", temp1->name);
            printf("Registration Number: %s\n", temp1->reg_no);
            printf("Age: %d\n", temp1->age);
            printf("Seat Number: %d\n", temp1->seat_no);
            temp1 = temp1->link;
        }
        temp = temp->next;
    }
}
void print_all_passengers_by_seat_no(struct header *head, struct coach *coach, int coach_no, int coach_class)
{
    struct passenger *temp = coach->pre;
    printf("\nCoach Number: %d\n", coach_no);
    printf("Coach Class: %d\n", coach_class);
    printf("Vacant Seats: %d\n", coach->vacant_seats);
    printf("Passenger Details:\n");
    while (temp != NULL)
    {
        printf("Name: %s\n", temp->name);
        printf("Registration Number: %s\n", temp->reg_no);
        printf("Age: %d\n", temp->age);
        printf("Seat Number: %d\n", temp->seat_no);
        temp = temp->link;
    }
}
