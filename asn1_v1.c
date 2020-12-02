// CSE373 assignment-1
// Prepared by 
// A. S. M. Sabiqul Hassan
// NSU ID 1812442042
// NSU Spring 2020 CSE373 Section 03


#include<stdio.h>
#include<stdlib.h>



// design a new soldier type
struct Soldier {
	int briefingTime;	// variable B
	int executionTime;	// variable J
};



// function to display soldiers' info
void displaySoldierDetails(struct Soldier sl) {
	printf("briefing time is: %d\n", sl.briefingTime);
	printf("execution time is: %d\n", sl.executionTime);
}

// function to display soldiers' info in
// ascending order based on executionTime
void sortSoldiersAscendingOnExecutionTime(struct Soldier sl[], int teamLength) {
	int i;	// for steps to sort
	int j;	// for position of soldiers
	struct Soldier tempSl;	// temp variable to hold a soldier for swapping
	
	for(i = 0; i < teamLength - 1; i++) {
		for(j = 0; j < teamLength - i - 1; j++) {
			// check executionTime to sort in ascending order
			if(sl[j].executionTime > sl[j+1].executionTime) {
				// swap 2 soldiers postion
				tempSl = sl[j];
				sl[j] = sl[j+1];
				sl[j+1] = tempSl;
			}
		}
	}
}

// function to display soldiers' info in
// descending order based on executionTime
void sortSoldiersDescendingOnExecutionTime(struct Soldier sl[], int teamLength) {
	int i;	// for steps to sort
	int j;	// for position of soldiers
	struct Soldier tempSl;	// temp variable to hold a soldier for swapping
	
	for(i = 0; i < teamLength - 1; i++) {
		for(j = 0; j < teamLength - i - 1; j++) {
			// check executionTime to sort in descending order
			if(sl[j].executionTime < sl[j+1].executionTime) {
				// swap 2 soldiers postion
				tempSl = sl[j];
				sl[j] = sl[j+1];
				sl[j+1] = tempSl;
			}
		}
	}
}
	
int main()
{
	
	int noOfSoldiers;	// variable N
	
	// ask the user to enter no of soldiers
	scanf("%d", &noOfSoldiers);
	
	// create a soldier group
	struct Soldier sl[noOfSoldiers];
		
	// take input for each one of the soldiers
	int i;	// temporary serial for a soldier
	for(i = 0; i < noOfSoldiers; i++) {
		// ask the briefing time 
		// for a particular soldier
		scanf("%d", &sl[i].briefingTime);
		
		// ask the execution time 
		// for a particular soldier
		scanf("%d", &sl[i].executionTime);
	}
	
	// extra part for tesing
	// display input details
	printf("\nAfter taking input from user: \n");
	for(i = 0; i < noOfSoldiers; i++) {
		printf("\nFor soldier %d\n", i+1);
		displaySoldierDetails(sl[i]);
	}
	
	
/*	
	// sort the soldier squad in ascending
	// according to the execution time
	sortSoldiersAscendingOnExecutionTime(sl, noOfSoldiers);
	
	// extra part for tesing
	// display input details
	// after sorting soldier squad
	printf("\nAfter sorting soldiers in ascending order: \n");
	for(i = 0; i < noOfSoldiers; i++) {
		printf("\nFor soldier %d\n", i+1);
		displaySoldierDetails(sl[i]);
	}
*/


	// sort the soldier squad in descending
	// according to the execution time
	sortSoldiersDescendingOnExecutionTime(sl, noOfSoldiers);
	
	// extra part for tesing
	// display input details
	// after sorting soldier squad
	printf("\nAfter sorting soldiers in descending order: \n");
	for(i = 0; i < noOfSoldiers; i++) {
		printf("\nFor soldier %d\n", i+1);
		displaySoldierDetails(sl[i]);
	}	
	
	
	// to minimize time to complete the mission
	// of soldier commando squad
	int totalMissionTime = 0;	// time to complete the mission
	
	// 1st soldier's briefing time will always be selected
	totalMissionTime += sl[0].briefingTime;
	
	// add time for other soldiers
	for(int i = 1; i < noOfSoldiers; i++) {
		//if(sl[i].briefingTime >= sl[i-1].executionTime) {
			totalMissionTime += sl[i].briefingTime;
		//}
	}
	
	// add last soldier's executionTime to get total time to complete mission
	totalMissionTime += sl[noOfSoldiers - 1].executionTime;
	
	
	
	// find out the estemated time 
	// to complete the mission
	printf("\n%d\n", totalMissionTime);
	
	
		
	
	
	
	
	return 0;
}
