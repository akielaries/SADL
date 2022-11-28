/* RM-pkg
 * Testing the RC4 stream cipher encryption algorithm on fields
 * of text using a XOR and tradition swap method.
 */
#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include "../../include/number_theory/rc4.hpp"


int main() {
    /*
     * Provide some details on how to use this algorithm
     */
    std::cout << "<------------------------------------------------------>\n\n";
    std::cout << "RIVEST CIPHER (RC4) EXAMPLE\n\n";

    /*<--------------------------------INIT--------------------------------->*/

    // declare RC4 class obj
    RC4 rc;

    /*
     * declare some key values and strings to hash
     * these first 3 plaintext strings are verified from the RC4 wiki
     * and will be displayed when using a traditional swap method 
     */
    // expected hash = BBF316E8D940AF0AD3
    char* key0    = (char*)"Key";
    char* text0   = (char*)"Plaintext";
    // expected hash = 1021BF0420
    char* key1    = (char*)"Wiki";
    char* text1   = (char*)"pedia";
    // expected hash = 45A01F645FC35B383552544B9BF5
    char* key2    = (char*)"Secret";
    char* text2   = (char*)"Attack at dawn";

    /*
     * char value for using one of the following 
     * XOR swap         0 
     * traditional swap 1
     * byte swap        2
     */
    int x_swap = 0;
    int t_swap = 1;
    int b_swap = 2;

    // declare a ciphertext pointer and allocate memory
    unsigned char *hashtext_0 = (unsigned char *)malloc(sizeof(int) * 
                                strlen(text0));
  
    printf("String before hash : %s\n", text0);

    /*<-------------------------------COMPUTE-------------------------------->*/
    /*
     * the main arguments are <key> & <plaintext> + allocated memory of
     * ciphertext as well as the swap type (x_swap true/false)
     */

    unsigned char *computed_text = rc.compute(key0, 
                                            text0, 
                                            hashtext_0, 
                                            x_swap);
    /*
     * function to store the computed hash 
     */
    std::string display_text = rc.store_hash(text0, hashtext_0, x_swap);
    std::cout << "COMPUTED HASH = " << display_text << std::endl;

    // free whats no longer in use
    free(hashtext_0);
    /*<------------------------------------------------------------------>*/
    printf("String before hash: %s\n", text1);
    unsigned char *hashtext_1 = (unsigned char *)malloc(sizeof(int) *
                                strlen(text1));
    
    unsigned char *computed_text1 = rc.compute(key1, 
                                            text1,
                                            hashtext_1,
                                            x_swap);

    std::string display_text1 = rc.store_hash(text1, hashtext_1, x_swap);
    std::cout << "COMPUTED HASH (TSWAP) = " << display_text1 << std::endl;

    free(hashtext_1);
    /*<------------------------------------------------------------------>*/
    printf("String before hash: %s\n", text2);
    unsigned char *hashtext_2 = (unsigned char *)malloc(sizeof(int) *
                                strlen(text2));
    
    unsigned char *computed_text2 = rc.compute(key2, 
                                            text2,
                                            hashtext_2,
                                            x_swap);

    std::string display_text2 = rc.store_hash(text2, hashtext_2, x_swap);
    std::cout << "COMPUTED HASH (TSWAP) = " << display_text2 << std::endl;

    printf("\n\n");

    free(hashtext_2);
    return EXIT_SUCCESS;
}

