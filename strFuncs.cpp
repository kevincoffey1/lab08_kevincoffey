#include "strFuncs.h"
#include <cctype>

using namespace std;


/* Precondition: s1 is a valid string that may contain upper or lower case alphabets, no spaces or special characters
 * Postcondition: Returns true if s1 is a palindrome, false otherwise
 *
 * Palindromes are NOT case-sensitive - "RaCecaR" is a valid palindrome
 *
 *You should provide a recursive solution*/
bool isPalindrome(const string s1){
    if (s1.size() == 0 || s1.size() == 1) {
		return true; 
    }
    char c1 = s1[0]; 
    char c2 = s1[s1.size()-1]; 
    string s2;
    for (int i = 1; i < s1.size()-1; i++) {
	s2 += s1[i]; 	
    }
    if (toupper(c1) != toupper(c2)){
	   return false; 
    } else { 
	   return isPalindrome(s2); 
    } 
    return true;
}
