#include<stdio.h>
#include<string.h>
struct Student{
	int roll;
	char name[50];
	float m1 ,m2,m3;
};
struct Student students[100];
int count=0;
void addStudent(){
	struct Student s;
	printf("enter a roll number\n");
	scanf("%d", &s.roll);
	printf("enter name\n");
	scanf("%s", s.name);
	printf("enter makrs of three subjects\n");
	scanf("%f %f %f", &s.m1 , &s.m2 , &s.m3);
	students[count]=s;
	count++;
	printf("student added successfully\n");
}
void displayStudents(){
	int i;
	if(count==0){
		printf("no records found\n");
		return;
	}
	printf("\n%-10s %-20s %-10s\n", "Roll No", "Name", "Average");
	for( i=0; i<count; i++){
			float avg=(students[i].m1+students[i].m2+students[i].m3)/3;
			printf("%-10d %-20s %-10.2f\n",students[i].roll,students[i].name,avg);
		}
		printf("\n");
	}
	
	void searchStudent(){
		int roll,i;
		printf("enter roll number to search: ");
		scanf("%d",&roll);
		for(i=0; i<count; i++){
			if(students[i].roll==roll){
			
			float avg = (students[i].m1+students[i].m2+students[i].m3)/3;
			printf("found! name: %s, average: %.2f\n\n",students[i].name,avg);
			return ;
			}			}
			printf("student not found.\n\n");
		}
		
			
		void deleteStudent(){
			int roll;
			printf("enter roll number to delete:");
			scanf("%d", &roll);
			int i,j;
			int found=0;
			for( i=0; i<count; i++){
				if (students[i].roll==roll){
					found=1;
					for( j=i; j<count-1; j++){
						students[j]=students[j+1];
					}
					count--;
					printf("student deleted successfully!\n\n");
					break;
				}
			}
			if(!found){
				printf("student not found.\n\n");
				
			}
		}
int main(){
	int choice;
	while(1){
		printf("---- Student Record Management ----\n");
		printf("1. Add Student\n");
        printf("2. Display All Students\n");
        printf("3. Search Student\n");
        printf("4. Delete Student\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
        	case 1: addStudent(); break;
        	case 2: displayStudents(); break;
        	case 3: searchStudent(); break;
        	case 4: deleteStudent(); break;
        	case 5:
        		printf("existing program.\n");
        		return 0;
        		default:
        			printf("invalid choice , try again.\n\n");
		}

	}
	return 0;
}



