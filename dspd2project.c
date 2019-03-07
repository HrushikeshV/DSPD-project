#include<stdio.h>

#include<stdlib.h>

#include<string.h>



int ticket_id=1;
//int flight_id=5;


typedef struct seat_structure_tag

	{

		int allocated;

		char pass_name[20];

		int age;

		int no_of_luggage;

		int weight;

		//int extra_cost_to_be_paid;

	}seat_structure;

	

	typedef struct flight_tag

			{

				int flight_id;

				int no_of_rows;

				int no_of_tickets_booked;

				seat_structure seat_matrix[100][6];

				struct flight_tag *next;

			} flight;
			
			typedef struct pass_details_tag

			{

				char name[20];

				int age;

				struct pass_details_tag *next;

			} pass_details;


			

	typedef struct ticket_tag

			{

				int ticket_id;

				int flight_id;

				int no_of_passengers;

				pass_details * passenger_head;
				
				int extra_cost_to_be_paid;

				struct ticket_tag *next;

			}	ticket;		
					

typedef struct service_tag

	{

		char serviceName[10];

		int no_of_flights;

		

		flight * flight_head;



		ticket * ticket_head;	

	/*	8*/

			

		struct service_tag *next;

	} service;

	

	

void bookTicket(service * service_head)

{

    char check_service[20];

    int check_flight_id;

    printf("Which service's flight you wanna book ?\n");

    

    scanf("%s",check_service);

    while(service_head!=NULL)

    {

        if(strcmp(service_head->serviceName,check_service)!=0)

        {

            service_head=service_head->next;
            
        }
        else
            break;

    }

    if(service_head!=NULL)

    {

        printf("Enter the flight ID to be booked\n");

        scanf("%d",&check_flight_id);

        while(service_head->flight_head!=NULL)

        {

            if(service_head->flight_head->flight_id!=check_flight_id)

            {

                service_head->flight_head=service_head->flight_head->next;

            }
            else
                break;

        }

        if(service_head->flight_head!=NULL)

        {
            
            
	    //ticket * t_ptr=NULL;

            ticket * t1=(ticket *)malloc(sizeof(ticket));

            t1->ticket_id=ticket_id;

            ticket_id++;

            t1->flight_id=check_flight_id;

            printf("Enter no. of passengers\n");

            scanf("%d",&t1->no_of_passengers);//check with total booked + no _of_passengers

            if(t1->no_of_passengers>6)

            {

                printf("Passenngers should be less than 6\n");

            }

            else

            {

                t1->passenger_head=NULL;

                for(int i=0;i<t1->no_of_passengers;i++)

                {

                    pass_details *p1=(pass_details *)malloc(sizeof(pass_details));

		            pass_details *t_ptr=NULL;

                    printf("Enter name of passenger\n");

                    scanf("%s",p1->name);

                    printf("Enter age\n");

                    scanf("%d",&p1->age);

		            p1->next=NULL;

                    if(t1->passenger_head==NULL)

                    {

                        t1->passenger_head=p1;

                    }

                    else

                    {

                 		t_ptr=t1->passenger_head;
    
    			        while(t_ptr->next!=NULL)
    
    		        	{
    
    			        	t_ptr=t_ptr->next;
    
    		        	}
    
               	        t_ptr->next=p1;

                    }

                }

            }
            
           ticket * ticket_ptr=service_head->ticket_head;
            
            if(ticket_ptr==NULL)
            {
                service_head->ticket_head=t1;
            }
            else
            {
                while(ticket_ptr->next!=NULL)
                
                {
                    
                    ticket_ptr=ticket_ptr->next;
                    
                }
                ticket_ptr->next=t1;
            }
 

        }

        else

        {

            printf("Enter flight id does not exist/n");

        }

    }

    else

    {

        printf("Service not available\n");

    }

}

void allocateBoardingPass(service * service_head)
{
    int check_flight_id;
    char s[20];
    printf("Enter your service name\n");
    scanf("%s",s);
    while(service_head!=NULL)

    {

        if(strcmp(service_head->serviceName,s)!=0)

        {

            service_head=service_head->next;
            
        }
        else
            break;

    }

    if(service_head!=NULL)
    {
        printf("Enter flight ID\n");
        scanf("%d",&check_flight_id);
        while(service_head->flight_head!=NULL)

        {

            if(service_head->flight_head->flight_id!=check_flight_id)

            {

                service_head->flight_head=service_head->flight_head->next;

            }
            else
                break;

        }

        if(service_head->flight_head!=NULL)
        {
            int check_ticket_id;
            printf("Enter your ticket ID\n");
            scanf("%d",&check_ticket_id);
            while(service_head->ticket_head!=NULL)

            {
    
                if(service_head->ticket_head->ticket_id!=check_ticket_id)
    
                {
    
                    service_head->ticket_head=service_head->ticket_head->next;
    
                }
                else
                    break;
    
            }
    
            if(service_head->ticket_head!=NULL)
            {
                
            }
            else
            {
                printf("No ticket had been booked from this id\n");
            }
        }
        else
        {
            printf("This flight does not exist\n");
        }
    }
    else
    {
        printf("This service does not exist\n");
    }
    
    
}

service * addFlightServiceWindow(service * service_head)

{

	int i;

	service * s1=(service *)malloc(sizeof(service));

	service * service_ptr=NULL;

	printf("Which service do you wanna avail?\n");

	scanf("%s",s1->serviceName);

	printf("How many flights would be operated ?\n");

	scanf("%d",&s1->no_of_flights);

	s1->flight_head = NULL;

	flight * flight_ptr=NULL;

	for(i=0;i<s1->no_of_flights;i++)

	{

		printf("%d executed\n",i);

		flight * f1=(flight *)malloc(sizeof(flight));

		//s1->flight_head * f1=(s1->flight *)malloc(sizeof(s1->flight));

		printf("Enter flight ID\n");
        scanf("%d",&f1->flight_id);
		//f1->flight_id=flight_id;
		//flight_id++;

		printf("Enter no. of rows\n");

		scanf("%d",&f1->no_of_rows);

		f1->no_of_tickets_booked=0;

		f1->next=NULL;

		if(s1->flight_head==NULL)

		{

			s1->flight_head=f1;

		}

		else

		{

			flight_ptr=s1->flight_head;

			while(flight_ptr->next!=NULL)

			{

				flight_ptr=flight_ptr->next;

			}

			flight_ptr->next=f1;

		}

	}

	

	s1->ticket_head=NULL;

	//printf("Returm from loop/n");

	

	service_ptr=service_head;

	

	if(service_head==NULL)

	{

		service_head=s1;

	}

	else

	{

		while(service_ptr->next!=NULL)

		{

			service_ptr=service_ptr->next;

		}

		service_ptr->next=s1;

	}

	return service_head;

}



void print_list(service * service_head)

{

	while(service_head!=NULL)

	{

		printf("%s \n",service_head->serviceName);

		printf("%d \n",service_head->no_of_flights);

		while(service_head->flight_head!=NULL)

		{

			printf("%d\n",service_head->flight_head->flight_id);

			service_head->flight_head=service_head->flight_head->next;

		}

		service_head=service_head->next;

		printf("LOop executed\n");

	}

}



int main()

{

	int temp,i;

	//initialize();

	printf("How many Windows you want to create\n");

	scanf("%d",&temp);

	service * service_head=NULL;

	for(i=0;i<temp;i++)

	{

		service_head=addFlightServiceWindow(service_head);

	}

	//printf("this executed\n");

	printf("Book your ticket here\n");

	//bookTicket();

	print_list(service_head);

	return 0;

}	

	