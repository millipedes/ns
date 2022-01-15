/**
* @file menus.c
* @brief This function contains all of the menus that are printed to the
* console across the language
* @author Matthew C. Lindeman
* @date January 08, 2022
* @bug None know
* @todo Nothing atm
*/
#include"include/menus.h"

/**
* This function prints the main menu of the REPL
* @param N/a
* @return N/a
*/
void print_welcome_screen(void) {
    printf("------------------------------------------------\n");
    printf("\t██████╗  █████╗ ███████╗██████╗ \n");
    printf("\t██╔══██╗██╔══██╗██╔════╝██╔══██╗\n");
    printf("\t██████╔╝███████║███████╗██████╔╝\n");
    printf("\t██╔══██╗██╔══██║╚════██║██╔══██╗\n");
    printf("\t██║  ██║██║  ██║███████║██████╔╝\n");
    printf("\t╚═╝  ╚═╝╚═╝  ╚═╝╚══════╝╚═════╝ \n");
    printf("------------------------------------------------\n");
	printf("Welcome to the REPL for the rasb programming\n");
	printf("language.  For help please visit:\n");
	printf("https://github.com/millipedes/ns\n");
    printf("------------------------------------------------\n");
}
