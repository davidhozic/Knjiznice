#include <iostream>
#include <linked_list.hh>
using namespace std;


/* TO BUILD RUN:
 make clean all 
	inside in the terminal or bash (will not work on windows console)    */


#define TYPE	int





class_LIST <TYPE> example_list;




TYPE compare(TYPE a, TYPE b) // for the sort function, all the types must match the type used at creation of the list
{
	return a - b; 
}

int main()
{
	/*******************************************************************************
	* 																			   *
	* 						  ADDING & REMOVING ELEMENTS			 			   *
	* 																			   *
	*******************************************************************************/
	/***************************************************************
	*	DESCRIPTION: Adds element to the back of the list		   *
	*	PARAMETERS: Element to add								   *
	*	RETURN: None											   *
	***************************************************************/
	example_list.add_end(1);
	example_list += 1;
	example_list = example_list + 1;

	/***************************************************************
	*	DESCRIPTION: Adds element to the front of the list		   *
	*	PARAMETERS: Element to add								   *
	*	RETURN: None											   *
	***************************************************************/
	example_list.add_front(69);
	example_list = 69 + example_list;

	/***************************************************************
	*	DESCRIPTION: Removes the element at specific index		   *
	*	PARAMETERS: index of element to remove					   *
	*	RETURN: None											   *
	***************************************************************/
	example_list.remove_by_index(0);
	
	/***************************************************************
	*	DESCRIPTION: Removes the back element from the list		   *
	*	PARAMETERS: None										   *
	*	RETURN: Returns removed element							   *
	***************************************************************/
	cout << "Popped element: " << example_list.pop_end() << endl;	

	/***************************************************************
	*	DESCRIPTION: Removes multiple elements starting at index   *
	*	PARAMETERS: ( start index , number of elements to remove ) *
	*	RETURN: Returns nothing									   *
	***************************************************************/
	example_list.splice(0, 2);	

	/*******************************************************************************
	* 																			   *
	* 						 	   OTHER FUNCTIONS				     			   *
	* 																			   *
	*******************************************************************************/

	/***************************************************************
	*	DESCRIPTION: Prints out contents of the list			   *
	*	PARAMETERS:  None		                                   *
	*	RETURN: Returns nothing									   *
	***************************************************************/
	for (int i = 0; i < 10; i++)
	{
		example_list += i;
		example_list = i + example_list;
	}

	example_list.print_console();	

	/***************************************************************
	*	DESCRIPTION: Sorts the list based on a compared function   *
	*	PARAMETERS: Comparator function - must return < 0 if first *
	*	element is smaller than the next or > 0 if first element   *
	*   is bigger than the next one. 							   *
	*	RETURN: Returns nothing									   *
	***************************************************************/
	example_list.sort(compare);
	cout <<""<<endl<<endl<<endl;

	example_list.print_console();	

	/***************************************************************
	*	DESCRIPTION: Returns the length of the list  			   *
	*	PARAMETERS:  None		                                   *
	*	RETURN: Returns length of the list  					   *
	***************************************************************/

    cout << "Lenghth of the list is: " << example_list.length() << endl;


	return 0;
}
